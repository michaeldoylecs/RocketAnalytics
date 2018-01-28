// Author: Michael Doyle
// Date: 8/13/17
// BinaryReaderTests.cpp

#include "BinaryReader.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

using namespace ReplayParser;

//TODO: Write better tests for BinaryReader

TEST(BinaryReaderTests, ReadTestReplay) {
	BinaryReader binary_reader("../../Testing/BinaryReaderTests/TestReplay.replay");
	EXPECT_EQ(binary_reader.read_aligned_uint8(), 1);
	EXPECT_EQ(binary_reader.read_aligned_uint8(), 2);
	EXPECT_EQ(binary_reader.read_aligned_uint8(), 3);
	EXPECT_EQ(binary_reader.read_aligned_uint8(), 4);
	EXPECT_EQ(binary_reader.read_aligned_uint32(), 6859);
	EXPECT_FLOAT_EQ(binary_reader.read_aligned_float(), 45.6897f);
	EXPECT_EQ(binary_reader.read_length_prefixed_string(), "Hello");
	EXPECT_EQ(binary_reader.read_aligned_uint64(), 32642364324629);
}
