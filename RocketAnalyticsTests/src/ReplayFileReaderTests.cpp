// Author: Michael Doyle
// Date: 8/5/17
// ReplayFileReaderTests.cpp

#include <iostream>
#include "ReplayFileReader.hpp"
#include "gtest\gtest.h"

struct ReplayFileReaderTestFixture: ::testing::Test {
	std::string replay_file_name;
	std::ofstream output_file_stream;
	ReplayParser::ReplayFileReader replay_file_reader;
	std::int8_t int8_array[6] = {1, 56, 74, 89, 43, 5};

	ReplayFileReaderTestFixture() {
		replay_file_name = "replay_test_file_output.replay";
		output_file_stream.open(replay_file_name, std::ios::out | std::ios::binary);
		for (const std::int8_t &value : int8_array) {
			char * write_data = reinterpret_cast<char *>(value);
			int write_data_size = sizeof(value);
			output_file_stream.write(write_data, write_data_size);
		}
		
	}

	void SetUp() {
	}

	void TearDown() {
	}

	~ReplayFileReaderTestFixture() {
	}
};