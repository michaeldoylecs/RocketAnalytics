// Author: Michael Doyle
// Date: 8/11/17
// StrPropertyTests.cpp

#include "properties\StrProperty.hpp"
#include "gtest\gtest.h"

using namespace ReplayParser;

struct StrPropertyTests : ::testing::Test {
	Property *property;
	std::string property_name = "Int Property!";
	std::string property_value = "String value!";
	PType property_type = PType::INT_PROPERTY;

	StrPropertyTests() {
		property = new StrProperty(property_name, property_value);
	}

	~StrPropertyTests() {
		delete property;
	}

};


TEST_F(StrPropertyTests, StrPropertyNameReadTest) {
	EXPECT_EQ(property->get_name(), property_name);
}


TEST_F(StrPropertyTests, StrPropertyTypeReadTest) {
	EXPECT_EQ(property->get_type(), property_type);
}


TEST_F(StrPropertyTests, StrPropertyValueReadTest) {
	EXPECT_EQ(property->get_value(), property_value);
}