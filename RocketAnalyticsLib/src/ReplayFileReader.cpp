/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 7/23/17
 *  File: ReplayFileReader.cpp
 *****************************************************************************/

#include "../include/ReplayFileReader.hpp"
#include <iostream>

namespace ReplayParser {

  ReplayFileReader::ReplayFileReader(std::string& filepath) {
    this->replay_file_stream.open(filepath, std::ios::binary);
    this->replay_file_path = filepath;
    if (this->replay_file_stream.is_open()) {
      std::cout << "Failed to open file stream for '" << replay_file_path << "'";
    }
  }

  ReplayFileReader::~ReplayFileReader() {
    if (replay_file_stream.is_open()) {
      replay_file_stream.close();
    }
  }

  std::int8_t ReplayFileReader::read_int8() {
    static_assert(sizeof(char) == 1,
      "ReplayFileReader::read_int8 requires char to be 1 byte");
    static_assert(sizeof(int8_t) == 1,
      "ReplayFileReader::read_int8 requires int8_t to be 1 byte");
    std::int8_t raw_int = 0;
    if (!replay_file_stream) {
      std::cout << "File stream not open for '" << replay_file_path << "'";
      return raw_int;
    }
    replay_file_stream.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int)); // NOLINT
    return raw_int;
  }

  std::int32_t ReplayFileReader::read_int32() {
    static_assert(sizeof(char) == 1,
      "ReplayFileReader::read_int32 requires char to be 1 byte");
    static_assert(sizeof(int32_t) == 4,
      "ReplayFileReader::read_int32 requires int32_t to be 4 bytes");
    std::int32_t raw_int = 0;
    if (!replay_file_stream) {
      std::cout << "File stream not open for '" << replay_file_path << "'";
      return raw_int;
    }
    replay_file_stream.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int)); // NOLINT
    return raw_int;
  }

  std::int64_t ReplayFileReader::read_int64() {
    static_assert(sizeof(char) == 1,
      "ReplayFileReader::read_int64 requires char to be 1 byte");
    static_assert(sizeof(int8_t) == 1,
      "ReplayFileReader::read_int64 requires int64_t to be 8 bytes");
    std::int64_t raw_int = 0;
    if (!replay_file_stream) {
      std::cout << "File stream not open for '" << replay_file_path << "'";
      return raw_int;
    }
    replay_file_stream.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int)); // NOLINT
    return raw_int;
  }

  float ReplayFileReader::read_float() {
    static_assert(sizeof(char) == 1,
      "ReplayFileReader::read_float requires char to be 1 byte");
    static_assert(sizeof(int8_t) == 1,
      "ReplayFileReader::read_float requires float to be 4 bytes");
    float raw_float = 0.0;
    if (!replay_file_stream) {
      std::cout << "File stream not open for '" << replay_file_path << "'";
      return raw_float;
    }
    replay_file_stream.read(reinterpret_cast<char *>(&raw_float), sizeof(raw_float)); // NOLINT
    return raw_float;
  }

  bool ReplayFileReader::read_bool() {
    static_assert(sizeof(char) == 1,
      "ReplayFileReader::read_bool requires char to be 1 byte");
    static_assert(sizeof(bool) == 1,
      "ReplayFileReader::read_bool requires bool to be 1 byte");
    bool raw_bool = false;
    if (!replay_file_stream) {
      std::cout << "File stream not open for '" << replay_file_path << "'";
      return raw_bool;
    }
    replay_file_stream.read(reinterpret_cast<char *>(&raw_bool), sizeof(raw_bool)); // NOLINT
    return raw_bool;
  }

  std::string ReplayFileReader::read_string(int length) {
    std::string raw_string;
    if (!replay_file_stream) {
      std::cout << "File stream not open for '" << replay_file_path << "'";
      return raw_string;
    }
    raw_string.resize(length);
    replay_file_stream.read(raw_string.data(), length);
    return raw_string;
  }

} // namespace ReplayParser
