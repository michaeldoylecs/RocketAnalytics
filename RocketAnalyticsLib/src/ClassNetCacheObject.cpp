/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/20/18
 * File: ClassNetCacheObject.cpp
 * Description: 
 *   Represents a ClassNetCacheObject in a Rocket League replay file.
 *****************************************************************************/

#include "../include/ClassNetCacheObject.hpp"

namespace ReplayParser {

  ClassNetCacheObject::ClassNetCacheObject(
    uint32_t index,
    uint32_t parent,
    uint32_t id,
    uint32_t prop_length,
    std::vector<std::pair<uint32_t, uint32_t>> properties)
    : c_index(index), c_parent(parent), c_id(id),
      c_prop_length(prop_length), c_properties(std::move(properties)) {}

  uint32_t ClassNetCacheObject::index() {
    return c_index;
  }

  uint32_t ClassNetCacheObject::parent() {
    return c_parent;
  }

  uint32_t ClassNetCacheObject::id() {
    return c_id;
  }

  uint32_t ClassNetCacheObject::prop_length() {
    return c_prop_length;
  }

  std::vector<std::pair<uint32_t, uint32_t>>
  ClassNetCacheObject::properties() {
    return c_properties;
  }

} // namespace ReplayParser
