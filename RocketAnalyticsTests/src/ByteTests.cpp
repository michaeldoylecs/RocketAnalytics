// Author: Michael Doyle
// Date: 8/13/17
// ByteMain.cpp

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../RocketAnalyticsLib/include/Byte.hpp"

using ReplayParser::Byte;

struct ByteTests: testing::Test{
	Byte byte;
	std::uint8_t value = 54; // 0b00110110

	ByteTests() {
		byte = Byte(value);
	}

	~ByteTests() override = default;

};

TEST_F(ByteTests, ByteCopyTest) {
	Byte new_byte = byte;
	EXPECT_EQ(                                        \
    std::to_integer<uint8_t>(new_byte.value()), \
    std::to_integer<uint8_t>(byte.value())     \
  );
}

TEST_F(ByteTests, SizeOfByte) {
	EXPECT_EQ(sizeof(Byte), sizeof(std::uint8_t));
}

TEST_F(ByteTests, GetValue) {
	EXPECT_EQ(std::to_integer<uint8_t>(byte.value()), value);
}

TEST_F(ByteTests, ByteToString) {
	EXPECT_EQ(byte.to_string(), "00110110");
}

TEST_F(ByteTests, CheckBits) {
	EXPECT_EQ(byte.bit(0), 0);
	EXPECT_EQ(byte.bit(1), 0);
	EXPECT_EQ(byte.bit(2), 1);
	EXPECT_EQ(byte.bit(3), 1);
	EXPECT_EQ(byte.bit(4), 0);
	EXPECT_EQ(byte.bit(5), 1);
	EXPECT_EQ(byte.bit(6), 1);
	EXPECT_EQ(byte.bit(7), 0);
}

TEST_F(ByteTests, DefaultConstructor) {
	Byte byteObject;
	EXPECT_EQ(std::to_integer<uint8_t>(byteObject.value()), 0);
}
