// Author: Michael Doyle
// Date: 8/13/17
// BinaryReader.cpp

#include "BinaryReader.hpp"
#include <fstream>
#include <iostream>
#include <cstring>
#include <array>

namespace ReplayParser {

	BinaryReader::BinaryReader(std::string filepath) {
		try {
			byte_position = 0;
			bit_position = 0;
			read_binary_file_into_memory(filepath);
		}
		catch(const std::runtime_error &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
			set_byte_list_size(0);
		}
	}


	float BinaryReader::read_padded_float() {
		try {
			const int AMOUNT_OF_BYTES_TO_READ = 4;
			std::array<Byte, AMOUNT_OF_BYTES_TO_READ> list_of_bytes;
			for (int index = 0; index < AMOUNT_OF_BYTES_TO_READ; index++) {
				list_of_bytes[index] = read_next_padded_byte();
			}
			float read_value = combine_bytes_into_float(list_of_bytes);
			return read_value;
		}
		catch (std::runtime_error e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
			return 0;
		}
	}


	std::uint8_t BinaryReader::read_padded_uint8() {
		try {
			Byte next_byte = read_next_padded_byte();
			std::uint8_t read_value = next_byte.get_value();
			return read_value;
		}
		catch (std::runtime_error e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
			return 0;
		}
	}


	std::uint32_t BinaryReader::read_padded_uint32() {
		try {
			const int AMOUNT_OF_BYTES_TO_READ = 4;
			std::array<Byte, AMOUNT_OF_BYTES_TO_READ> list_of_bytes;
			for (int index = 0; index < AMOUNT_OF_BYTES_TO_READ; index++) {
				list_of_bytes[index] = read_next_padded_byte();
			}
			std::uint32_t read_value = combine_bytes_into_uint32(list_of_bytes);
			return read_value;
		}
		catch(std::runtime_error e){
			std::cout << "Exception caught: " << e.what() << std::endl;
			return 0;
		}
	}


	std::string BinaryReader::read_padded_string() {
		std::cout << "Attempting to read string in BinaryReader";
		std::string string_value;
		std::uint32_t string_length = read_padded_uint32();
		string_value = read_string_of_n_length(string_length);
		return string_value;
	}


	void BinaryReader::read_binary_file_into_memory(std::string filepath) {
		std::ifstream binary_file_stream(filepath, std::ios::binary | std::ios::in);
		if (!binary_file_stream.is_open()) {
			throw std::runtime_error("Failed to open file exception");
		}
		std::size_t binary_file_size = get_file_size(binary_file_stream);
		set_byte_list_size(binary_file_size);
		binary_file_stream.read(reinterpret_cast<char*>(byte_list.data()), binary_file_size); // HACK: Kindof a hack to directly assign data to Byte object memory space
		binary_file_stream.close();
	}


	std::size_t BinaryReader::get_file_size(std::ifstream &file_stream) {
		std::size_t initial_file_position = file_stream.tellg();
		file_stream.seekg(0, std::ios::end);
		std::size_t binary_file_size = file_stream.tellg();
		file_stream.seekg(initial_file_position, std::ios::beg);
		return binary_file_size;
	}


	void BinaryReader::set_byte_list_size(std::size_t size) {
		byte_list.resize(size);
	}


	Byte BinaryReader::read_next_padded_byte() {
		if (bit_position != 0) {
			throw std::runtime_error("Attempted to read byte with bit pointer misaligned");
		}
		Byte next_byte = byte_list.at(byte_position);
		increment_byte_position();
		return next_byte;
	}


	float BinaryReader::combine_bytes_into_float(std::array<Byte, 4> bytes) {
		float combined_value = 0.0f;
		std::memcpy(&combined_value, &bytes, sizeof(combined_value));
		return combined_value;
	}


	std::uint32_t BinaryReader::combine_bytes_into_uint32(std::array<Byte, 4> bytes) {
		const int BYTES_TO_COMBINE = 4;
		const int BITS_IN_A_BYTE = 8;
		std::uint32_t combined_value = 0;
		for (int index = BYTES_TO_COMBINE - 1; index >= 0; index--) {
			combined_value = combined_value << BITS_IN_A_BYTE; // Shift 8 bits left
			combined_value = combined_value | bytes[index].get_value(); // OR on next 8 bits
		}
		return combined_value;
	}


	void BinaryReader::increment_byte_position() {
		byte_position++;
	}


	void BinaryReader::increment_bit_position() {
		bit_position++;
		if (bit_position > 7) {
			bit_position = 0;
			increment_byte_position();
		}
	}


	std::size_t BinaryReader::size() {
		return byte_list.size();
	}


	std::string BinaryReader::read_string_of_n_length(std::uint32_t length) {
		try {
			std::string string_value = "";
			for (std::uint32_t index = 0; index < length; index++) {
				Byte next_byte = read_next_padded_byte();
				std::uint8_t byte_value = next_byte.get_value();
				std::string next_char = (char *) byte_value; //TODO: Better way than C-style casting?
				string_value += next_char;
			}
			return string_value;
		}
		catch (std::runtime_error e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
			return std::string("READ_FAIL");
		}
	}

}