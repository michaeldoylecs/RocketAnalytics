// Author: Michael Doyle
// Date: 8/13/17
// BinaryReaderTests.cpp

#include "BinaryReader.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

using namespace ReplayParser;

//TODO: Write better tests for BinaryReader

TEST(BinaryReaderTests, ReadValueTypes) {
	BinaryReader binary_reader("../../Testing/TestReplay.replay");
	EXPECT_EQ(binary_reader.read_padded_uint8(), 1);
	EXPECT_EQ(binary_reader.read_padded_uint8(), 2);
	EXPECT_EQ(binary_reader.read_padded_uint8(), 3);
	EXPECT_EQ(binary_reader.read_padded_uint8(), 4);
	EXPECT_EQ(binary_reader.read_padded_uint32(), 6859);
	EXPECT_FLOAT_EQ(binary_reader.read_padded_float(), 45.6897f);
	EXPECT_EQ(binary_reader.read_padded_string(), "Hello");
	EXPECT_EQ(binary_reader.read_padded_uint64(), 32642364324629);
}
