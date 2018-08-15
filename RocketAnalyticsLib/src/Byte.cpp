/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/13/17
 *  File: Byte.cpp
 *****************************************************************************/

#include "../include/Byte.hpp"
#include <bitset>
#include <sstream>

namespace rocketanalytics {

  Byte::Byte() : b_value{0} {}

  Byte::Byte(std::uint8_t rvalue) : b_value{std::byte(rvalue)} {}

  std::byte Byte::value() {
    return b_value;
  }

  int8_t Byte::bit(int index) {
    auto bit_value = std::byte(0);
    const auto BIT_MASK = std::byte(0x01);
    switch (index) {
      case 0:
        bit_value |= (b_value >> 7) & BIT_MASK;
        break;
      case 1:
        bit_value |= (b_value >> 6) & BIT_MASK;
        break;
      case 2:
        bit_value |= (b_value >> 5) & BIT_MASK;
        break;
      case 3:
        bit_value |= (b_value >> 4) & BIT_MASK;
        break;
      case 4:
        bit_value |= (b_value >> 3) & BIT_MASK;
        break;
      case 5:
        bit_value |= (b_value >> 2) & BIT_MASK;
        break;
      case 6:
        bit_value |= (b_value >> 1) & BIT_MASK;
        break;
      case 7:
        bit_value |= b_value & BIT_MASK;
        break;
      default:
        break;
    }
    return std::to_integer<std::int8_t>(bit_value);
  }

  std::string Byte::to_string() {
    std::string bit_string;
    bit_string += std::to_string(bit(0));
    bit_string += std::to_string(bit(1));
    bit_string += std::to_string(bit(2));
    bit_string += std::to_string(bit(3));
    bit_string += std::to_string(bit(4));
    bit_string += std::to_string(bit(5));
    bit_string += std::to_string(bit(6));
    bit_string += std::to_string(bit(7));
    return bit_string;
  }

} // namespace rocketanalytics
