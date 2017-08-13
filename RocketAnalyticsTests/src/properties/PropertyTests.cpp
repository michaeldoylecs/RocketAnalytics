// Author: Michael Doyle
// Date: 8/11/17
// PropertyTests.cpp

#include "PropertyType.hpp"
#include "Property.hpp"
#include "gtest\gtest.h"

using namespace ReplayParser;

// TODO: Update Property Tests

struct PropertyTests : ::testing::Test {
	Property *property;
	std::string property_name = "Empty Property!";
	PType property_type = PType::NONE;

	PropertyTests() {
		property = new Property();
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


TEST_F(PropertyTests, PropertyTypeCopyTest) {
	Property new_property = *property;
	EXPECT_EQ(property->get_type(), new_property.get_type());
	EXPECT_EQ(property->get_name(), new_property.get_name());
}
