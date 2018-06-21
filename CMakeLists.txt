# Initial CMake configurations
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# CMakeLists for RocketAnalytics
cmake_minimum_required (VERSION 3.9)
project (
  RocketAnalyticsLib
  VERSION 0.2
  DESCRIPTION "Rocket League replay parsing library"
)

# TODO: Figure out how to properly handle compiler flags
set (CMAKE_CXX_STANDARD 17)
add_compile_options(-std=c++17)

# Google Testing Framework
# Download and unpack googletest at configure time
configure_file (CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process (COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
if (result)
  message (FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process (COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
if (result)
  message (FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory (${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories ("${gtest_SOURCE_DIR}/include")
endif ()

# Configure RocketAnalyticsLib Build
add_library (RocketAnalyticsLib
  "RocketAnalyticsLib/src/BinaryReader.cpp"
  "RocketAnalyticsLib/src/Byte.cpp"
  "RocketAnalyticsLib/src/ClassNetCacheObject.cpp"
  "RocketAnalyticsLib/src/Keyframe.cpp"
  "RocketAnalyticsLib/src/Netstream.cpp"
  "RocketAnalyticsLib/src/ReplayFile.cpp"
  "RocketAnalyticsLib/src/ReplayFileReader.cpp"
  "RocketAnalyticsLib/src/ReplayHeader.cpp"
  "RocketAnalyticsLib/src/ReplayKeyframes.cpp"
  "RocketAnalyticsLib/src/ReplayLevels.cpp"
  "RocketAnalyticsLib/src/ReplayReplicatedPackages.cpp"
  "RocketAnalyticsLib/src/ReplayTick.cpp"
  "RocketAnalyticsLib/src/ReplayTickInformation.cpp"
  "RocketAnalyticsLib/src/Version.cpp"
  "RocketAnalyticsLib/src/properties/ByteValue.cpp"
  "RocketAnalyticsLib/src/properties/Property.cpp"
  "RocketAnalyticsLib/src/properties/PropertyType.cpp"
  "RocketAnalyticsLib/src/properties/PropertyValue.cpp"
)

# TODO: Add public interface header
# RocketAnalyticsLib header files
target_include_directories (RocketAnalyticsLib
  PRIVATE
    ${PROJECT_SOURCE_DIR}/RocketAnalyticsLib/include
    ${PROJECT_SOURCE_DIR}/RocketAnalyticsLib/include/properties
)

# RocketAnalyticsLib properties
set_target_properties (RocketAnalyticsLib PROPERTIES
  VERSION ${PROJECT_VERSION}
  CXX_STANDARD_REQUIRED 17
  CXX_STANDARD_REQUIRED ON
)

# Configure RocketAnalytics Test Application
add_executable (RocketAnalyticsApp
  "RocketAnalyticsApp/src/RocketAnalyticsApp.cpp"
)

set_target_properties (RocketAnalyticsApp PROPERTIES
  VERSION ${PROJECT_VERSION}
  CXX_STANDARD_REQUIRED 17
  CXX_STANDARD_REQUIRED ON
)

target_link_libraries (RocketAnalyticsApp RocketAnalyticsLib)

# Configure Tests Build
add_executable (unitTests
  "RocketAnalyticsTests/src/BinaryReaderTests.cpp"
  "RocketAnalyticsTests/src/ByteTests.cpp"
  "RocketAnalyticsTests/src/KeyframeTests.cpp"
  "RocketAnalyticsTests/src/ReplayHeaderTests.cpp"
  "RocketAnalyticsTests/src/ReplayKeyframesTests.cpp"
  "RocketAnalyticsTests/src/RocketAnalyticsTests.cpp"
  "RocketAnalyticsTests/src/VersionTests.cpp"
  "RocketAnalyticsTests/src/properties/ByteValueTests.cpp"
  "RocketAnalyticsTests/src/properties/PropertyTests.cpp"
  "RocketAnalyticsTests/src/properties/PropertyTypeTests.cpp"
  "RocketAnalyticsTests/src/properties/PropertyValueTests.cpp"
)

target_link_libraries (unitTests gtest gmock_main RocketAnalyticsLib)

# Tests header files
target_include_directories (unitTests
  PRIVATE
    ${PROJECT_SOURCE_DIR}/RocketAnalyticsLib/include
    ${PROJECT_SOURCE_DIR}/RocketAnalyticsLib/include/properties
)

# Tests properties
set_target_properties (unitTests PROPERTIES
  VERSION 0.1
  CXX_STANDARD_REQUIRED 17
  CXX_STANDARD_REQUIRED ON
)

enable_testing()
add_test (NAME unit_tests1 COMMAND unitTests)

# Look for clang-tidy
unset (CLANG_TIDY_EXECUTABLE)
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy")
  find_program (CLANG_TIDY_EXECUTABLE "clang-tidy"
    DOC "Path to clang-tidy executable"
  )
  if (CLANG_TIDY_EXECUTABLE MATCHES "CLANG_TIDY_EXECUTABLE")
    unset (CLANG_TIDY_EXECUTABLE)
    message (WARNING "WARNING: .clang-tidy file found for \
      project ${PROJECT_NAME}, yet clang-tidy not on PATH so disabling \
      lint pass"
    )
  endif ()
endif ()

# Add clang-tidy to compilation if it exists
if (DEFINED CLANG_TIDY_EXECUTABLE)
  if (MSVC)
    # Tell clang-tidy to interpret these parameters as clang-cl would
    set_target_properties (${PROJECT_NAME} PROPERTIES
      CXX_CLANG_TIDY "${CLANG_TIDY_EXECUTABLE};-fms-extensions;\
        -fms-compatibility-version=19;-D_M_AMD64=100;"
    )
  else()
    set_target_properties (${PROJECT_NAME} PROPERTIES
      CXX_CLANG_TIDY ${CLANG_TIDY_EXECUTABLE}
    )
  endif()
endif()

# Output location
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Export compile_commands.json
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiling messages
message ("Compiling for: " ${CMAKE_BUILD_TYPE})
