// Author: Michael Doyle
// Date: 8/10/17
// VersionTests.cpp

#include "properties\PropertyType.hpp"
#include "gtest\gtest.h"
#include <cstdint>

using namespace ReplayParser;

TEST(PropertyTypeTests, NonePropertyTypeToString) {
	PType type = PType::NONE;
	std::string expected_string_value = "None";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, IntPropertyTypeToString) {
	PType type = PType::INT_PROPERTY;
	std::string expected_string_value = "IntProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, StrPropertyTypeToString) {
	PType type = PType::STR_PROPERTY;
	std::string expected_string_value = "StrProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, NamePropertyTypeToString) {
	PType type = PType::NAME_PROPERTY;
	std::string expected_string_value = "NameProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, BoolPropertyTypeToString) {
	PType type = PType::BOOL_PROPERTY;
	std::string expected_string_value = "BoolProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, QWordPropertyTypeToString) {
	PType type = PType::QWORD_PROPERTY;
	std::string expected_string_value = "QWordProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, BytePropertyTypeToString) {
	PType type = PType::BYTE_PROPERTY;
	std::string expected_string_value = "ByteProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, FloatPropertyTypeToString) {
	PType type = PType::FLOAT_PROPERTY;
	std::string expected_string_value = "FloatProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, ArrayPropertyTypeToString) {
	PType type = PType::ARRAY_PROPERTY;
	std::string expected_string_value = "ArrayProperty";
	std::string converted_string = PropertyType::property_type_to_string(type);
	EXPECT_EQ(converted_string, expected_string_value);
}


TEST(PropertyTypeTests, NoneStringToPropertyType) {
	std::string type_string = "None";
	PType expected_type_value = PType::NONE;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, IntStringToPropertyType) {
	std::string type_string = "IntProperty";
	PType expected_type_value = PType::INT_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, StrStringToPropertyType) {
	std::string type_string = "StrProperty";
	PType expected_type_value = PType::STR_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, NameStringToPropertyType) {
	std::string type_string = "NameProperty";
	PType expected_type_value = PType::NAME_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, BoolStringToPropertyType) {
	std::string type_string = "BoolProperty";
	PType expected_type_value = PType::BOOL_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, QWordStringToPropertyType) {
	std::string type_string = "QWordProperty";
	PType expected_type_value = PType::QWORD_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, ByteStringToPropertyType) {
	std::string type_string = "ByteProperty";
	PType expected_type_value = PType::BYTE_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, FloatStringToPropertyType) {
	std::string type_string = "FloatProperty";
	PType expected_type_value = PType::FLOAT_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, ArrayStringToPropertyType) {
	std::string type_string = "ArrayProperty";
	PType expected_type_value = PType::ARRAY_PROPERTY;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}


TEST(PropertyTypeTests, UnknownStringToPropertyType) {
	std::string type_string = "GambitProperty";
	PType expected_type_value = PType::NONE;
	PType converted_type_value = PropertyType::string_to_property_type(type_string);
	EXPECT_EQ(converted_type_value, expected_type_value);
}
