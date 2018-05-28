/******************************************************************************L
 *	Author:	Michael Doyle
 *	Date:	8/13/17
 *	File:	Byte.hpp
 *	Description:
 *		Byte is a representation of a byte of data that allows for accessing
 *	individual bits in O(1) time. bit1 is the highest left most bit in a
 *	binary number representation of the given value.
 *****************************************************************************/

#ifndef BYTE_H
#define BYTE_H

#include <cstddef>
#include <cstdint>
#include <string>

namespace ReplayParser {

	class Byte {
		public:
			Byte();
			explicit Byte(std::uint8_t value);
			Byte(const Byte &byte);
			std::byte get_value();
      std::int8_t get_bit(int index);
			std::string to_string();

		private:
      std::byte value;
  };

} // namespace ReplayParser

#endif
