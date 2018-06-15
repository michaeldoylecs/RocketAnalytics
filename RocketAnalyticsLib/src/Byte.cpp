/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	8/13/17
 *	File:	Byte.cpp
 *****************************************************************************/

#include "../include/Byte.hpp"
#include <bitset>
#include <sstream>

namespace ReplayParser {

	Byte::Byte() {
		this->value = std::byte(0);
	}

	Byte::Byte(std::uint8_t value) {
		this->value = std::byte(value);
	}

	Byte::Byte(const Byte &byte) {
		this->value = byte.value;
	}

	std::byte Byte::get_value() {
		return value;
	}

  int8_t Byte::get_bit(int index) {
		std::byte bit_value = std::byte(0);
    const std::byte BIT_MASK = std::byte(0x01);
		switch (index) {
			case 0:
				bit_value |= (this->value >> 7) & BIT_MASK;
				break;
			case 1:
				bit_value |= (this->value >> 6) & BIT_MASK;
				break;
			case 2:
				bit_value |= (this->value >> 5) & BIT_MASK;
				break;
			case 3:
				bit_value |= (this->value >> 4) & BIT_MASK;
				break;
			case 4:
				bit_value |= (this->value >> 3) & BIT_MASK;
				break;
			case 5:
				bit_value |= (this->value >> 2) & BIT_MASK;
				break;
			case 6:
				bit_value |= (this->value >> 1) & BIT_MASK;
				break;
			case 7:
				bit_value |= this->value & BIT_MASK;
				break;
			default:
				break;
		}
		return std::to_integer<int8_t>(bit_value);
	}

	std::string Byte::to_string() {
    std::string bit_string;
	  bit_string += std::to_string(get_bit(0));
	  bit_string += std::to_string(get_bit(1));
	  bit_string += std::to_string(get_bit(2));
	  bit_string += std::to_string(get_bit(3));
	  bit_string += std::to_string(get_bit(4));
	  bit_string += std::to_string(get_bit(5));
	  bit_string += std::to_string(get_bit(6));
	  bit_string += std::to_string(get_bit(7));
	  return bit_string;
	}

} // namespace ReplayParser
