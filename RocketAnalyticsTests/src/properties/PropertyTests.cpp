// Author: Michael Doyle
// Date: 8/11/17
// PropertyTests.cpp

#include "properties\Property.hpp"
#include "gtest\gtest.h"

using namespace ReplayParser;

struct PropertyTests : ::testing::Test {
	Property *property;
	std::string property_name = "Empty Property!";
	PType property_type = PType::NONE;

	PropertyTests() {
		property = new Property(property_name);
	}

	~PropertyTests() {
		delete property;
	}

};


TEST_F(PropertyTests, PropertyNameReadTest) {
	EXPECT_EQ(property->get_name(), property_name);
}


TEST_F(PropertyTests, PropertyTypeReadTest) {
	EXPECT_EQ(property->get_type(), property_type);
}
