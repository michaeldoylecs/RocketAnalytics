/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/10/17
 *  File: Version.hpp
 *  Description:
 *    Versions contains the versioning information found the the Rocket
 *  League replay file.
 *****************************************************************************/

#ifndef VERSION_H
#define VERSION_H

#include <cstdint>
#include <string>

namespace ReplayParser {

  class Version {
    public:
      Version() = default;
      Version(std::uint32_t major, std::uint32_t minor);
      std::uint32_t major_value() const;
      std::uint32_t minor_value() const;
      void set_version(std::uint32_t major, std::uint32_t minor);
      std::string to_string() const;

    private:
      std::uint32_t version_major;
      std::uint32_t version_minor;
  };

} // namespace ReplayParser

#endif
