# CMakeLists for RocketAnalytics
cmake_minimum_required (VERSION 3.9)
project (
    RocketAnalyticsLib
    VERSION 0.2
    DESCRIPTION "Rocket League replay parsing library"
)

# Source files
add_library (${PROJECT_NAME}
    "RocketAnalyticsLib/src/BinaryReader.cpp"
    "RocketAnalyticsLib/src/Byte.cpp"
    "RocketAnalyticsLib/src/ReplayFile.cpp"
    "RocketAnalyticsLib/src/ReplayFileReader.cpp"
    "RocketAnalyticsLib/src/ReplayHeader.cpp"
    "RocketAnalyticsLib/src/ReplayLevels.cpp"
    "RocketAnalyticsLib/src/Version.cpp"
    "RocketAnalyticsLib/src/properties/ByteValue.cpp"
    "RocketAnalyticsLib/src/properties/Property.cpp"
    "RocketAnalyticsLib/src/properties/PropertyType.cpp"
    "RocketAnalyticsLib/src/properties/PropertyValue.cpp"
)

set_target_properties (${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties (${PROJECT_NAME} PROPERTIES SOVERSION 1)
# TODO: Add public interface header

# Header files
target_include_directories (${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/RocketAnalyticsLib/include
        ${PROJECT_SOURCE_DIR}/RocketAnalyticsLib/include/properties
)

# Output location
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Compiler flags
set (CMAKE_CXX_FLAGS
    "-std=c++14 -Wall -Wextra -Wpedantic -Wzero-as-null-pointer-constant"
)

message ("Compiling for: " ${CMAKE_BUILD_TYPE})
