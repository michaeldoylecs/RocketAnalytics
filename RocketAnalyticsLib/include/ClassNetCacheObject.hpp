/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/20/18
 * File: ClassNetCacheObject.hpp
 * Description:
 *   Represents a ClassNetCacheObject in a Rocket League replay file.
 *****************************************************************************/

#ifndef CLASSNETCACHEOBJECT_HPP
#define CLASSNETCACHEOBJECT_HPP

#include <cstdint>
#include <vector>
#include <utility>

namespace ReplayParser {

  class ClassNetCacheObject {
    public:
      ClassNetCacheObject();
      ClassNetCacheObject(
          std::uint32_t index,
          std::uint32_t parent,
          std::uint32_t id,
          std::uint32_t prop_length,
          std::vector<std::pair<std::uint32_t, std::uint32_t>> properties);
      ~ClassNetCacheObject();

      std::uint32_t index();
      std::uint32_t parent();
      std::uint32_t id();
      std::uint32_t prop_length();
      std::vector<std::pair<std::uint32_t, std::uint32_t>> properties();

    private:
      std::uint32_t c_index;
      std::uint32_t c_parent;
      std::uint32_t c_id;
      std::uint32_t c_prop_length;
      std::vector<std::pair<std::uint32_t, std::uint32_t>> c_properties;
  };

}

#endif
