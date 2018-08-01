/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/13/17
 *  File: BinaryReader.cpp
 *****************************************************************************/

#include "../include/BinaryReader.hpp"
#include <array>
#include <cstring>
#include <fstream>
#include <iostream>

namespace ReplayParser {

  BinaryReader::BinaryReader(const std::string& filepath) {
    try {
      byte_position = 0;
      bit_position = 0;
      read_file(filepath);
    }
    catch(const std::runtime_error &e) {
      file_bytes.resize(0);
    }
  }

  void BinaryReader::read_file(const std::string& filepath) {
    std::ifstream file_stream(filepath, std::ios::binary | std::ios::in);
    if (file_stream.is_open()) {
      size_t file_size = get_file_size(file_stream);
      file_bytes.resize(file_size);
      file_stream.read(reinterpret_cast<char*>(file_bytes.data()), file_size); // NOLINT
      file_stream.close();
    }
    else {
      throw std::runtime_error("Failed to open file exception");
    }
  }

  size_t BinaryReader::get_file_size(std::ifstream &file_stream) {
    size_t file_start = file_stream.tellg();
    file_stream.seekg(0, std::ios::end);
    size_t file_size = file_stream.tellg();
    file_stream.seekg(file_start, std::ios::beg);
    return file_size;
  }

  std::vector<Byte> BinaryReader::read_bytes(int length) { 
    try {
      std::vector<Byte> list_of_bytes;
      list_of_bytes.resize(length);
      for (int i = 0; i < length; ++i) {
        list_of_bytes.at(i) = read_aligned_byte();
      }
      return list_of_bytes;
    }
    catch(std::runtime_error &e){
      std::cerr << "Exception caught: " << e.what() << std::endl;
      return std::vector<Byte>();
    }
  }

  float BinaryReader::read_aligned_float() {
    try {
      constexpr int FLOAT_SIZE = sizeof(float);
      static_assert(FLOAT_SIZE == 4,
        "BinaryReader::read_aligned_float() requires 'float' to be 4 bytes");
      std::array<Byte, FLOAT_SIZE> list_of_bytes;
      for (int index = 0; index < FLOAT_SIZE; index++) {
        list_of_bytes.at(index) = read_aligned_byte();
      }
      return bytes_to_float(list_of_bytes);
    }
    catch (std::runtime_error &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
      return 0;
    }
  }

  float BinaryReader::bytes_to_float(std::array<Byte, 4> bytes) {
    static_assert(sizeof(float) == 4,
      "BinaryReader::bytes_to_float() requires 'float' to be 4 bytes");
    float combined_value = 0.0f;
    memcpy(&combined_value, &bytes, sizeof(combined_value)); // NOLINT
    return combined_value;
  }

  uint8_t BinaryReader::read_aligned_uint8() {
    try {
      Byte next_byte = read_aligned_byte();
      uint8_t read_value = std::to_integer<uint32_t>(next_byte.get_value());
      return read_value;
    }
    catch (const std::runtime_error &e) {
      std::cerr << e.what() << std::endl;
      return 0;
    }
  }

  uint32_t BinaryReader::read_aligned_uint32() {
    try {
      const int BYTES_TO_READ = 4;
      std::array<Byte, BYTES_TO_READ> list_of_bytes;
      for (int index = 0; index < BYTES_TO_READ; index++) {
        list_of_bytes.at(index) = read_aligned_byte();
      }
      std::uint32_t read_value = bytes_to_uint32(list_of_bytes);
      return read_value;
    }
    catch(const std::runtime_error &e){
      std::cerr << e.what() << std::endl;
      throw e;
    }
  }

  std::uint32_t BinaryReader::bytes_to_uint32(std::array<Byte, 4> bytes) {
    static_assert(sizeof(std::uint32_t) == 4,
      "BinaryReader::bytes_to_uint32() requires 'std::uin32_t' to be 4 bytes");
    std::uint32_t combined_value = 0;
    memcpy(&combined_value, &bytes, sizeof(combined_value)); // NOLINT
    return combined_value;
  }

  uint64_t BinaryReader::read_aligned_uint64() {
    try {
      const int AMOUNT_OF_BYTES_TO_READ = 8;
      std::array<Byte, AMOUNT_OF_BYTES_TO_READ> list_of_bytes;
      for (int index = 0; index < AMOUNT_OF_BYTES_TO_READ; index++) {
        list_of_bytes.at(index) = read_aligned_byte();
      }
      uint64_t read_value = bytes_to_uint64(list_of_bytes);
      return read_value;
    }
    catch (const std::runtime_error &e) {
      std::cerr << e.what() << std::endl;
      return 0;
    }
  }

  uint64_t BinaryReader::bytes_to_uint64(std::array<Byte, 8> bytes) {
    static_assert(sizeof(uint64_t),
      "BinaryReader::byte_to_uint64() requires 'uint64_t' to be 8 bytes");
    uint64_t combined_value = 0;
    memcpy(&combined_value, &bytes, sizeof(combined_value)); // NOLINT
    return combined_value;
  }

  std::string BinaryReader::read_length_prefixed_string() {
    std::string string_value;
    std::uint32_t str_length = read_aligned_uint32();
    string_value = read_string_of_n_length(str_length);
    return string_value.substr(0, str_length - 1);
  }

  std::string BinaryReader::read_string_of_n_length(std::uint32_t length) {
    try {
      std::string read_string;
      for (std::uint32_t i = 0; i < length; i++) {
        Byte next_byte = read_aligned_byte();
        auto byte_value = std::to_integer<std::uint8_t>(next_byte.get_value());
        char next_char;
        memcpy(&next_char, &byte_value, sizeof(next_char));
        read_string += next_char;
      }
      return read_string;
    }
    catch (const std::runtime_error &e) {
      throw e;
    }
  }

  Byte BinaryReader::read_aligned_byte() {
    if (bit_position != 0) {
      throw std::runtime_error(
        "Attempted to read byte with bit pointer misaligned"
      );
    }
    try {
      Byte next_byte = file_bytes.at(byte_position);
      increment_byte_position();
      return next_byte;
    } catch (std::out_of_range& e) {
      throw e;
    }
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

  size_t BinaryReader::size() {
    return file_bytes.size();
  }

  void BinaryReader::close() {
    file_bytes.clear();
    byte_position = 0;
    bit_position = 0;
  }

} // namespace ReplayParser
