// Author: Michael Doyle
// Date: 8/11/17
// PropertyTests.cpp

#include "../../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../../RocketAnalyticsLib/include/properties/Property.hpp"
#include "../../../RocketAnalyticsLib/include/properties/PropertyType.hpp"

using namespace rocketanalytics;

struct PropertyTests : ::testing::Test {
  Property *property;
  std::string property_name = "This is a property name!";
  PType property_type = PType::NONE;

  PropertyTests() {
    property = new Property();
  }

  ~PropertyTests() {
    delete property;
  }

};

TEST_F(PropertyTests, NonePropertyNameReadTest) {
  EXPECT_EQ(property->name(), "None");
}

TEST_F(PropertyTests, NonePropertytypeReadTest) {
  EXPECT_EQ(property->type(), PType::NONE);
}

TEST_F(PropertyTests, NonePropertyValueReadTest) {
  EXPECT_EQ(property->value_as_string(), "None");
}

TEST_F(PropertyTests, NonePropertyToStringTest) {
  std::string expected_to_string_value = "None: None";
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, IntPropertyNameReadTest) {
  std::uint32_t given_value = 6983547;
  property->set_int(property_name, given_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, IntPropertyTypeReadTest) {
  std::uint32_t given_value = 6983547;
  property->set_int(property_name, given_value);
  EXPECT_EQ(property->type(), PType::INT_PROPERTY);
}

TEST_F(PropertyTests, IntPropertyValueReadTest) {
  std::uint32_t given_value = 6983547;
  std::string converted_value = std::to_string(given_value);
  property->set_int(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), converted_value);
}

TEST_F(PropertyTests, IntPropertyToStringTest) {
  std::uint32_t given_value = 6983547;
  std::string converted_value = std::to_string(given_value);
  std::string expected_to_string_value = property_name + ": " + converted_value;
  property->set_int(property_name, given_value);
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, StrPropertyNameReadTest) {
  std::string given_value = "This is a string value!";
  property->set_string(property_name, given_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, StrPropertyTypeReadTest) {
  std::string given_value = "This is a string value!";
  property->set_string(property_name, given_value);
  EXPECT_EQ(property->type(), PType::STR_PROPERTY);
}

TEST_F(PropertyTests, StrPropertyValueReadTest) {
  std::string given_value = "This is a string value!";
  property->set_string(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), given_value);
}

TEST_F(PropertyTests, StrPropertyToStringTest) {
  std::string given_value = "This is a string value!";
  property->set_string(property_name, given_value);
  std::string expected_to_string_value = property_name + ": " + given_value;
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, NamePropertyNameReadTest) {
  std::string given_value = "This is a name value!";
  property->set_name(property_name, given_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, NamePropertyTypeReadTest) {
  std::string given_value = "This is a name value!";
  property->set_name(property_name, given_value);
  EXPECT_EQ(property->type(), PType::NAME_PROPERTY);
}

TEST_F(PropertyTests, NamePropertyValueReadTest) {
  std::string given_value = "This is a name value!";
  property->set_name(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), given_value);
}

TEST_F(PropertyTests, NamePropertyToStringTest) {
  std::string given_value = "This is a name value!";
  property->set_name(property_name, given_value);
  std::string expected_to_string_value = property_name + ": " + given_value;
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, BoolPropertyNameReadTest) {
  bool given_value = true;
  property->set_bool(property_name, given_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, BoolPropertyTypeReadTest) {
  bool given_value = true;
  property->set_bool(property_name, given_value);
  EXPECT_EQ(property->type(), PType::BOOL_PROPERTY);
}

TEST_F(PropertyTests, BoolPropertyTrueValueReadTest) {
  bool given_value = true;
  std::string converted_value = std::to_string(given_value);
  property->set_bool(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), converted_value);
}

TEST_F(PropertyTests, BoolPropertyFalseValueReadTest) {
  bool given_value = false;
  std::string converted_value = std::to_string(given_value);
  property->set_bool(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), converted_value);
}

TEST_F(PropertyTests, BoolPropertyToStringTest) {
  bool given_value = false;
  std::string converted_value = std::to_string(given_value);
  std::string expected_to_string_value = property_name + ": " + converted_value;
  property->set_bool(property_name, given_value);
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, QWordPropertyNameReadTest) {
  std::uint64_t given_value = 478568658609;
  property->set_qword(property_name, given_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, QWordPropertyTypeReadTest) {
  std::uint64_t given_value = 478568658609;
  property->set_qword(property_name, given_value);
  EXPECT_EQ(property->type(), PType::QWORD_PROPERTY);
}

TEST_F(PropertyTests, QWordPropertyValueReadTest) {
  std::uint64_t given_value = 478568658609;
  std::string converted_value = std::to_string(given_value);
  property->set_qword(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), converted_value);
}

TEST_F(PropertyTests, QWordPropertyToStringTest) {
  std::uint64_t given_value = 478568658609;
  std::string converted_value = std::to_string(given_value);
  std::string expected_to_string_value = property_name + ": " + converted_value;
  property->set_qword(property_name, given_value);
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, BytePropertyNameReadTest) {
  std::string byte_identifier = "Byte identifier!";
  std::string byte_value = "Byte value!";
  property->set_byte(property_name, byte_identifier, byte_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, BytePropertyTypeReadTest) {
  std::string byte_identifier = "Byte identifier!";
  std::string byte_value = "Byte value!";
  property->set_byte(property_name, byte_identifier, byte_value);
  EXPECT_EQ(property->type(), PType::BYTE_PROPERTY);
}

TEST_F(PropertyTests, BytePropertyValueReadTest) {
  std::string byte_identifier = "Byte identifier!";
  std::string byte_value = "Byte value!";
  std::string expected_value = byte_identifier + ": " + byte_value;
  property->set_byte(property_name, byte_identifier, byte_value);
  EXPECT_EQ(property->value_as_string(), expected_value);
}

TEST_F(PropertyTests, BytePropertyToStringTest) {
  std::string byte_identifier = "Byte identifier!";
  std::string byte_value = "Byte value!";
  std::string expected_to_string_value = property_name + ": " + byte_identifier + ": " + byte_value;
  property->set_byte(property_name, byte_identifier, byte_value);
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

TEST_F(PropertyTests, FloatPropertyNameReadTest) {
  float given_value = 478.45f;
  property->set_float(property_name, given_value);
  EXPECT_EQ(property->name(), property_name);
}

TEST_F(PropertyTests, FloatPropertyTypeReadTest) {
  float given_value = 478.45f;
  property->set_float(property_name, given_value);
  EXPECT_EQ(property->type(), PType::FLOAT_PROPERTY);
}

TEST_F(PropertyTests, FloatPropertyValueReadTest) {
  float given_value = 478.45f;
  std::string converted_value = std::to_string(given_value);
  property->set_float(property_name, given_value);
  EXPECT_EQ(property->value_as_string(), converted_value);
}

TEST_F(PropertyTests, FloatPropertyToStringTest) {
  float given_value = 478.45f;
  std::string converted_value = std::to_string(given_value);
  std::string expected_to_string_value = property_name + ": " + converted_value;
  property->set_float(property_name, given_value);
  EXPECT_EQ(property->to_string(), expected_to_string_value);
}

