// Author: Michael Doyle
// Date: 8/12/17
// PropertyValueTests.cpp

#include "Property.hpp"
#include "PropertyType.hpp"
#include "PropertyValue.hpp"
#include "gtest\gtest.h"

using namespace ReplayParser;

struct PropertyValueTests : ::testing::Test {
	PropertyValue *property_value;

	PropertyValueTests() {
		property_value = new PropertyValue();
	}

	~PropertyValueTests() {
		delete property_value;
	}

};


TEST_F(PropertyValueTests, NonePropertyReadType) {
	EXPECT_EQ(property_value->get_type(), PType::NONE);
}


TEST_F(PropertyValueTests, NonePropertyReadStringValue) {
	EXPECT_EQ(property_value->get_value_as_string(), "None");
}


TEST_F(PropertyValueTests, IntPropertyReadType) {
	uint32_t expected_value = 578;
	PType expected_type = PType::INT_PROPERTY;
	property_value->set_int(expected_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, IntPropertyReadStringValue) {
	uint32_t expected_value = 578;
	std::string expected_string_value = std::to_string(expected_value);
	property_value->set_int(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_string_value);
}


TEST_F(PropertyValueTests, StrPropertyReadType) {
	std::string expected_value = "This is a string value!";
	PType expected_type = PType::STR_PROPERTY;
	property_value->set_string(expected_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, StrPropertyReadStringValue) {
	std::string expected_value = "This is a string value!";
	property_value->set_string(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_value);
}


TEST_F(PropertyValueTests, NamePropertyReadType) {
	std::string expected_value = "This is a name value!";
	PType expected_type = PType::NAME_PROPERTY;
	property_value->set_name(expected_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, NamePropertyReadStringValue) {
	std::string expected_value = "This is a name value!";
	property_value->set_name(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_value);
}


TEST_F(PropertyValueTests, BoolPropertyReadType) {
	bool expected_value = true;
	PType expected_type = PType::BOOL_PROPERTY;
	property_value->set_bool(expected_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, BoolPropertyReadStringValueTrue) {
	bool expected_value = true;
	std::string expected_string_value = std::to_string(expected_value);
	property_value->set_bool(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_string_value);
}


TEST_F(PropertyValueTests, BoolPropertyReadStringValueFalse) {
	bool expected_value = false;
	std::string expected_string_value = std::to_string(expected_value);
	property_value->set_bool(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_string_value);
}


TEST_F(PropertyValueTests, QWordPropertyReadType) {
	std::uint64_t expected_value = 43759465593;
	PType expected_type = PType::QWORD_PROPERTY;
	property_value->set_qword(expected_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, QWordPropertyReadStringValue) {
	std::uint64_t expected_value = 43759465593;
	std::string expected_string_value = std::to_string(expected_value);
	property_value->set_qword(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_string_value);
}


TEST_F(PropertyValueTests, BytePropertyReadType) {
	std::string byte_identifier = "Byte identifier!";
	std::string byte_value = "Byte value!";
	PType expected_type = PType::BYTE_PROPERTY;
	property_value->set_byte(byte_identifier, byte_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, BytePropertyReadStringValue) {
	std::string byte_identifier = "Byte identifier!";
	std::string byte_value = "Byte value!";
	std::string expected_output = byte_identifier + ": " + byte_value;
	property_value->set_byte(byte_identifier, byte_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_output);
}


TEST_F(PropertyValueTests, FloatPropertyReadType) {
	float expected_value = 123.6857f;
	PType expected_type = PType::FLOAT_PROPERTY;
	property_value->set_float(expected_value);
	EXPECT_EQ(property_value->get_type(), expected_type);
}


TEST_F(PropertyValueTests, FloatPropertyReadStringValue) {
	float expected_value = 123.6857f;
	std::string expected_string_value = std::to_string(expected_value);
	property_value->set_float(expected_value);
	EXPECT_EQ(property_value->get_value_as_string(), expected_string_value);
}


TEST_F(PropertyValueTests, ArrayPropertyReadType) {
	PType expected_type = PType::ARRAY_PROPERTY;
	Property properties[3] = {
		Property(),
		Property(),
		Property(),
	};
	std::vector<Property> property_list;
	for (int i = 0; i < 3; i++) {
		property_list.push_back(properties[i]);
	}
	property_value->set_array(property_list);
	EXPECT_EQ(property_value->get_type(), expected_type);
}

// TOOD: Need more indepth Array unit tests
TEST_F(PropertyValueTests, ArrayPropertyReadStringValue) {
	std::string expected_string_value = "None, None, None";
	Property properties[3] = {
		Property(),
		Property(),
		Property(),
	};
	std::vector<Property> property_list;
	for (int i = 0; i < 3; i++) {
		property_list.push_back(properties[i]);
	}
	property_value->set_array(property_list);
	EXPECT_EQ(property_value->get_value_as_string(), expected_string_value);
}
