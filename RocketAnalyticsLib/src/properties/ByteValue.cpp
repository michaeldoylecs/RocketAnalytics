/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/12/17
 *  File: ByteValue.cpp
 *****************************************************************************/

#include "../../include/properties/ByteValue.hpp"

namespace ReplayParser {

  ByteValue::ByteValue(const std::string& id, const std::string& value) {
    byte_id = id;
    byte_value = value;
  }

  std::string ByteValue::get_id() {
    return byte_id;
  }

  std::string ByteValue::get_value() {
    return byte_value;
  }

} // namespace ReplayParser
