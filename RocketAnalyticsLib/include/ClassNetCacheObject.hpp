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
#include <utility>
#include <vector>

namespace rocketanalytics {

  class ClassNetCacheObject {
    public:
      ClassNetCacheObject() = default;
      ClassNetCacheObject(
        uint32_t index,
        uint32_t parent,
        uint32_t id,
        uint32_t prop_length,
        std::vector<std::pair<uint32_t, uint32_t>> properties);

      uint32_t index() const;
      uint32_t parent() const;
      uint32_t id() const;
      uint32_t prop_length() const;
      std::vector<std::pair<uint32_t, uint32_t>> properties() const;

    private:
      uint32_t c_index{0};
      uint32_t c_parent{0};
      uint32_t c_id{0};
      uint32_t c_prop_length{0};
      std::vector<std::pair<uint32_t, uint32_t>> c_properties;
  };

} // namespace rocketanalytics

#endif
