// Author: Michael Doyle
// Date: 8/11/17
// IntPropertyTests.cpp

#include "properties\IntProperty.hpp"
#include "gtest\gtest.h"

using namespace ReplayParser;

struct IntPropertyTests : ::testing::Test {
	Property *property;
	std::string property_name = "Int Property!";
	std::uint32_t property_value = 56;
	PType property_type = PType::INT_PROPERTY;

	IntPropertyTests() {
		property = new IntProperty(property_name, property_value);
	}

	~IntPropertyTests() {
		delete property;
	}

};


TEST_F(IntPropertyTests, IntPropertyNameReadTest) {
	EXPECT_EQ(property->get_name(), property_name);
}


TEST_F(IntPropertyTests, IntPropertyTypeReadTest) {
	EXPECT_EQ(property->get_type(), property_type);
}


TEST_F(IntPropertyTests, IntPropertyValueReadTest) {
	EXPECT_EQ(property->get_value(), property_value);
}