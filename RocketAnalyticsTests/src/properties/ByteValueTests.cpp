// Author: Michael Doyle
// Date: 8/12/17
// ByteValueTests.cpp

#include "ByteValue.hpp"
#include "gtest\gtest.h"

using namespace ReplayParser;

struct ByteValueTests : ::testing::Test {
	ByteValue *byte_value;
	std::string identifier = "This is an identifier!";
	std::string value = "This is a value!";

	ByteValueTests() {
		byte_value = new ByteValue(identifier, value);
	}

	~ByteValueTests() {
		delete byte_value;
	}

};


TEST_F(ByteValueTests, ByteValueReadIdentifier) {
	EXPECT_EQ(byte_value->get_identifer(), identifier);
}


TEST_F(ByteValueTests, ByteValueReadValue) {
	EXPECT_EQ(byte_value->get_value(), value);
}