/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/20/18
 * File: ClassNetCacheObject.cpp
 * Description: 
 *   Represents a ClassNetCacheObject in a Rocket League replay file.
 *****************************************************************************/

#include "../include/ClassNetCacheObject.hpp"

namespace ReplayParser {

  ClassNetCacheObject::ClassNetCacheObject()
    : c_index(0), c_parent(0), c_id(0), c_prop_length(0) {}

  ClassNetCacheObject::ClassNetCacheObject(
    std::uint32_t index,
    std::uint32_t parent,
    std::uint32_t id,
    std::uint32_t prop_length)
    : c_index(index), c_parent(parent), c_id(id), c_prop_length(prop_length) {}

  ClassNetCacheObject::~ClassNetCacheObject() = default;

  std::uint32_t ClassNetCacheObject::index() {
    return c_index;
  }

  std::uint32_t ClassNetCacheObject::parent() {
    return c_parent;
  }

  std::uint32_t ClassNetCacheObject::id() {
    return c_id;
  }

  std::uint32_t ClassNetCacheObject::prop_length() {
    return c_prop_length;
  }

}
