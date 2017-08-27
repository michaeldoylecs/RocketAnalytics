// Author: Michael Doyle
// Date: 8/13/17
// ByteMain.cpp

#include "Byte.hpp"
#include "gtest/gtest.h"

using namespace ReplayParser;

struct ByteTests: testing::Test{
	Byte *byte;
	std::uint8_t value = 54; // 0x00110110

	ByteTests() {
		byte = new Byte(value);
	}

	~ByteTests(){
		delete byte;
	}

};


TEST_F(ByteTests, ByteCopyTest) {
	Byte new_byte = *byte;
	EXPECT_EQ(new_byte.get_value(), byte->get_value());
}


TEST_F(ByteTests, SizeOfByte) {
	EXPECT_EQ(sizeof(Byte), sizeof(std::uint8_t));
}


TEST_F(ByteTests, GetValue) {
	EXPECT_EQ(byte->get_value(), value);
}


TEST_F(ByteTests, ByteToString) {
	EXPECT_EQ(byte->to_string(), "00110110");
}


TEST_F(ByteTests, CheckBits) {
	EXPECT_EQ(byte->get_bit(0), 0);
	EXPECT_EQ(byte->get_bit(1), 1);
	EXPECT_EQ(byte->get_bit(2), 1);
	EXPECT_EQ(byte->get_bit(3), 0);
	EXPECT_EQ(byte->get_bit(4), 1);
	EXPECT_EQ(byte->get_bit(5), 1);
	EXPECT_EQ(byte->get_bit(6), 0);
	EXPECT_EQ(byte->get_bit(7), 0);
}


TEST_F(ByteTests, DefaultConstructor) {
	Byte byteObject;
	EXPECT_EQ(byteObject.get_value(), 0);
}
