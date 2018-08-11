/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/12/17
 *  File: PropertyValue.cpp
 *****************************************************************************/

#include "../../include/properties/ByteValue.hpp"
#include "../../include/properties/Property.hpp"
#include "../../include/properties/PropertyType.hpp"
#include "../../include/properties/PropertyValue.hpp"
#include "../../third-party/include/json.hpp"

namespace ReplayParser {

  PropertyValue::PropertyValue() : property_type{PType::NONE} {}

  PropertyValue::PropertyValue(const PropertyValue &propertyValue) 
  : property_type{PType::NONE} {
    PType type = propertyValue.property_type;
    if (type == PType::INT_PROPERTY) {
      set_int(propertyValue.property_value.int32); // NOLINT
    }
    else if (type == PType::STR_PROPERTY) {
      set_string(propertyValue.property_value.string); // NOLINT
    }
    else if (type == PType::NAME_PROPERTY) {
      set_name(propertyValue.property_value.string); // NOLINT
    }
    else if (type == PType::BOOL_PROPERTY) {
      set_bool(propertyValue.property_value.int8); // NOLINT
    }
    else if (type == PType::QWORD_PROPERTY) {
      set_qword(propertyValue.property_value.int64); // NOLINT
    }
    else if (type == PType::BYTE_PROPERTY) {
      set_byte(propertyValue.property_value.byte); // NOLINT
    }
    else if (type == PType::FLOAT_PROPERTY) {
      set_float(propertyValue.property_value.f); // NOLINT
    }
    else if (type == PType::ARRAY_PROPERTY) {
      set_array(propertyValue.property_value.list); // NOLINT
    }
    else {
      set_none();
    }
  }

  PropertyValue &PropertyValue::operator=(const PropertyValue& propertyValue) {
    PType type = propertyValue.property_type;
    if (type == PType::INT_PROPERTY) {
      set_int(propertyValue.property_value.int32); // NOLINT
    }
    else if (type == PType::STR_PROPERTY) {
      set_string(propertyValue.property_value.string); // NOLINT
    }
    else if (type == PType::NAME_PROPERTY) {
      set_name(propertyValue.property_value.string); // NOLINT
    }
    else if (type == PType::BOOL_PROPERTY) {
      set_bool(propertyValue.property_value.int8); // NOLINT
    }
    else if (type == PType::QWORD_PROPERTY) {
      set_qword(propertyValue.property_value.int64); // NOLINT
    }
    else if (type == PType::BYTE_PROPERTY) {
      set_byte(propertyValue.property_value.byte); // NOLINT
    }
    else if (type == PType::FLOAT_PROPERTY) {
      set_float(propertyValue.property_value.f); // NOLINT
    }
    else if (type == PType::ARRAY_PROPERTY) {
      set_array(propertyValue.property_value.list); // NOLINT
    }
    else {
      set_none();
    }
    return *this;
  }

  PropertyValue::~PropertyValue() {
    deconstruct_union_values_if_necessary();
  }

  void PropertyValue::set_none() {
    property_type = PType::NONE;
  }

  void PropertyValue::set_int(const std::uint32_t int32) {
    deconstruct_union_values_if_necessary();
    property_type = PType::INT_PROPERTY;
    property_value.int32 = int32; // NOLINT
  }

  void PropertyValue::set_string(const std::string& string) {
    deconstruct_union_values_if_necessary();
    property_type = PType::STR_PROPERTY;
    new (&property_value.string) std::string(string); // NOLINT
  }

  void PropertyValue::set_name(const std::string& name) {
    deconstruct_union_values_if_necessary();
    property_type = PType::NAME_PROPERTY;
    new (&property_value.string) std::string(name); // NOLINT 
  }

  void PropertyValue::set_bool(const std::uint8_t int8) {
    deconstruct_union_values_if_necessary();
    property_type = PType::BOOL_PROPERTY;
    property_value.int8 = int8; // NOLINT
  }

  void PropertyValue::set_qword(const std::uint64_t qword) {
    deconstruct_union_values_if_necessary();
    property_type = PType::QWORD_PROPERTY;
    property_value.int64 = qword; // NOLINT
  }

  void PropertyValue::set_byte(const ByteValue& byte) {
    deconstruct_union_values_if_necessary();
    property_type = PType::BYTE_PROPERTY;
    new (&property_value.byte) ByteValue(byte); // NOLINT
  }

  void PropertyValue::set_byte(const std::string& identifier,
  const std::string& value) {
    deconstruct_union_values_if_necessary();
    property_type = PType::BYTE_PROPERTY;
    new (&property_value.byte) ByteValue(identifier, value); // NOLINT
  }

  void PropertyValue::set_float(const float f) {
    deconstruct_union_values_if_necessary();
    property_type = PType::FLOAT_PROPERTY;
    property_value.f = f; // NOLINT
  }

  void PropertyValue::set_array(
  const std::vector<std::vector<Property>>& property_list) {
    deconstruct_union_values_if_necessary();
    property_type = PType::ARRAY_PROPERTY;
    new (&property_value.list) std::vector< std::vector<Property> >(property_list); // NOLINT
  }

  void PropertyValue::deconstruct_union_values_if_necessary() {
    if (property_type == PType::STR_PROPERTY) {
      property_value.string.~basic_string(); // NOLINT
    }
    else if (property_type == PType::NAME_PROPERTY) {
      property_value.string.~basic_string(); // NOLINT
    }
    else if (property_type == PType::BYTE_PROPERTY) {
      property_value.byte.~ByteValue(); // NOLINT
    }
    else if (property_type == PType::ARRAY_PROPERTY) {
      property_value.list.~vector(); // NOLINT
    }
  }

  PType PropertyValue::get_type() const {
    return property_type;
  }

  std::string PropertyValue::get_value_as_string() const {
    if (property_type == PType::INT_PROPERTY) {
      std::uint32_t stored_value = property_value.int32; // NOLINT
      std::string converted_value = std::to_string(stored_value);
      return converted_value;
    }
    if (property_type == PType::STR_PROPERTY) {
      std::string stored_value = property_value.string; // NOLINT
      return stored_value;
    }
    if (property_type == PType::NAME_PROPERTY) {
      std::string stored_value = property_value.string; // NOLINT
      return stored_value;
    }
    if (property_type == PType::BOOL_PROPERTY) {
      bool stored_value = property_value.int8; // NOLINT
      return stored_value == true ? "1" : "0"; // NOLINT
    }
    if (property_type == PType::QWORD_PROPERTY) {
      std::uint64_t stored_value = property_value.int64; // NOLINT
      std::string converted_value = std::to_string(stored_value);
      return converted_value;
    }
    if (property_type == PType::BYTE_PROPERTY) {
      ByteValue byte = property_value.byte; // NOLINT
      std::string byte_identifier = byte.get_id();
      std::string byte_value = byte.get_value();
      std::string converted_value = byte_identifier + ": " + byte_value;
      return converted_value;
    }
    if (property_type == PType::FLOAT_PROPERTY) {
      float stored_value = property_value.f; // NOLINT
      std::string converted_value = std::to_string(stored_value);
      return converted_value;
    }
    if (property_type == PType::ARRAY_PROPERTY) {
      std::string converted_value = array_properties_to_string();
      return converted_value;
    }
    return "None";
  }

  std::string PropertyValue::array_properties_to_string() const {
    nlohmann::json serialized_props;
    auto& array_props = property_value.list; // NOLINT
    for (const auto& property : array_props) {
      nlohmann::json prop;
      for (const auto& prop_value : property) {
        if (prop_value.get_type() == PType::NONE) { continue; }
        prop[prop_value.get_name()] = prop_value.get_value_as_string();
      }
      serialized_props.push_back(prop);
    }
    return serialized_props.dump(4);
  }

  PropertyValue::UValue::UValue() {} // NOLINT

  PropertyValue::UValue::~UValue() {} // NOLINT

} // namespace ReplayParser
