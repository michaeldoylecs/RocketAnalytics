// Author: Michael Doyle
// Date: 8/13/17
// BinaryReader.hpp

#ifndef BIT_READER_H
#define BIT_READER_H

#include "Byte.hpp"
#include <vector>

namespace ReplayParser {

	class ifstream;

	class BinaryReader {
		public:
			BinaryReader(std::string file_path);
			float read_padded_float();
			std::uint8_t read_padded_uint8();
			std::uint32_t read_padded_uint32();
			std::uint64_t read_padded_uint64();
			std::string read_padded_string();
			std::size_t size();

		private:
			std::vector<Byte> byte_list;
			int byte_position;
			int bit_position;

			void read_binary_file_into_memory(std::string filepath);
			void set_byte_list_size(std::size_t size);
			Byte read_next_padded_byte();
			float combine_bytes_into_float(std::array<Byte, 4> bytes);
			std::uint32_t combine_bytes_into_uint32(std::array<Byte, 4> bytes);
			std::uint64_t combine_bytes_into_uint64(std::array<Byte, 8> bytes);
			std::string read_string_of_n_length(std::uint32_t length);
			std::size_t get_file_size(std::ifstream &file_stream);
			void increment_byte_position();
			void increment_bit_position();
	};

}


#endif
