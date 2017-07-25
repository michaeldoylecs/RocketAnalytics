// Author: Michael Doyle
// Date: 7/23/17
// ReplayFileReader.cpp

#include "../include/ReplayFileReader.hpp"
#include <iostream>

namespace ReplayParser {

	ReplayFileReader::ReplayFileReader(std::string filepath) {
		this->filepath = std::string(filepath);
		this->file_stream.open(filepath, std::ios::binary);

		// Check if file stream was opened
		if (!this->file_stream) {
			std::cout << "Failed to open file stream for '" << filepath << "'";
		}
	}

	ReplayFileReader::~ReplayFileReader() {
		if (file_stream) {
			file_stream.close();
		}
	}

	std::int8_t ReplayFileReader::read_int8() {
		std::int8_t raw_int = 0;

		// Check if the file_stream is open
		if (!file_stream) {
			std::cout << "File stream not open for '" << filepath << "'";
			return raw_int;
		}

		// Read 1 byte from file_stream
		file_stream.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
		
		return raw_int;
	}

	std::int32_t ReplayFileReader::read_int32() {
		std::int32_t raw_int = 0;

		// Check if the file_stream is open
		if (!file_stream) {
			std::cout << "File stream not open for '" << filepath << "'";
			return raw_int;
		}

		// Read 4 bytes from file_stream
		file_stream.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));

		return raw_int;
	}

	std::int64_t ReplayFileReader::read_int64() {
		std::int64_t raw_int = 0;

		// Check if the file_stream is open
		if (!file_stream) {
			std::cout << "File stream not open for '" << filepath << "'";
			return raw_int;
		}

		// Read 8 bytes from file_stream
		file_stream.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));

		return raw_int;
	}

	float ReplayFileReader::read_float() {
		float raw_float = 0.0;

		// Check if the file_stream is open
		if (!file_stream) {
			std::cout << "File stream not open for '" << filepath << "'";
			return raw_float;
		}

		// Read 4 bytes from file_stream
		file_stream.read(reinterpret_cast<char *>(&raw_float), sizeof(raw_float));

		return raw_float;
	}

	bool ReplayFileReader::read_bool() {
		bool raw_bool = false;

		// Check if the file_stream is open
		if (!file_stream) {
			std::cout << "File stream not open for '" << filepath << "'";
			return raw_bool;
		}

		// Read 1 byte from file_stream
		file_stream.read(reinterpret_cast<char *>(&raw_bool), sizeof(raw_bool));

		return raw_bool;
	}

	std::string ReplayFileReader::read_string(int length) {
		std::string raw_string;

		// Check if the file_stream is open
		if (!file_stream) {
			std::cout << "File stream not open for '" << filepath << "'";
			return raw_string;
		}

		file_stream.read(reinterpret_cast<char *>(&raw_string), length); // Read characters from file
		
		return raw_string;
	}

}