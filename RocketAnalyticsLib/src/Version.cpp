/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/10/17
 *  File: Version.cpp
 *****************************************************************************/

#include "../include/Version.hpp"

namespace rocketanalytics {

  Version::Version(std::uint32_t major, std::uint32_t minor)
    : version_major{major}, version_minor{minor} {}

  void Version::set_version(std::uint32_t major, std::uint32_t minor) {
    version_major = major;
    version_minor = minor;
  }

  std::uint32_t Version::major_value() const {
    return version_major;
  }

  std::uint32_t Version::minor_value() const {
    return version_minor;
  }

  std::string Version::to_string() const {
    return std::to_string(version_major) +
        "." + std::to_string(version_minor);
  }
} // namespace rocketanalytics
