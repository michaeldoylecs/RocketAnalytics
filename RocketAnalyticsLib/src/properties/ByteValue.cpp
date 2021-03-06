/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/12/17
 *  File: ByteValue.cpp
 *****************************************************************************/

#include "../../include/properties/ByteValue.hpp"

namespace rocketanalytics {

  ByteValue::ByteValue(const std::string& id, const std::string& value) {
    byte_id = id;
    byte_value = value;
  }

  std::string ByteValue::id() {
    return byte_id;
  }

  std::string ByteValue::value() {
    return byte_value;
  }

} // namespace rocketanalytics
