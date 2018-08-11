/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/11/17
 *  File: Property.cpp
 *****************************************************************************/

#include "../../include/properties/PropertyValue.hpp"
#include "../../include/properties/Property.hpp"
#include "../../third-party/include/json.hpp"

namespace ReplayParser {

  Property::Property() {
    set_none();
  }

  void Property::set_none() {
    property_name = "None";
    property_value.set_none();
  }

  void Property::set_int(const std::string& name, const std::uint32_t& value) {
    property_name = name;
    property_value.set_int(value);
  }

  void Property::set_string(const std::string& name, const std::string& value) {
    property_name = name;
    property_value.set_string(value);
  }

  void Property::set_name(const std::string& name, const std::string& value) {
    property_name = name;
    property_value.set_name(value);
  }

  void Property::set_bool(const std::string& name, const std::uint8_t& value) {
    property_name = name;
    property_value.set_bool(value);
  }

  void Property::set_qword(const std::string& name, const std::uint64_t& value) {
    property_name = name;
    property_value.set_qword(value);
  }

  void Property::set_byte(const std::string& name,
  const std::string& identifier, const std::string& value) {
    property_name = name;
    ByteValue byte(identifier, value);
    property_value.set_byte(byte);
  }

  void Property::set_float(const std::string& name, const float& value) {
    property_name = name;
    property_value.set_float(value);
  }

  void Property::set_array(const std::string& name,
  const std::vector<std::vector<Property>>& value) {
    property_name = name;
    property_value.set_array(value);
  }

  bool Property::operator== (const Property& rhs) const {
    return (
      (this->property_name == rhs.property_name)
      && (this->property_value.get_value_as_string()
        == rhs.property_value.get_value_as_string())
    );
  }

  std::string Property::get_name() const {
    return property_name;
  }

  PType Property::get_type() const {
    return property_value.get_type();
  }

  PropertyValue Property::get_value() const {
    return property_value;
  }

  std::string Property::get_value_as_string() const {
    return property_value.get_value_as_string();
  }

  // TODO(michaeldoylecs): IMPROVE: Maintain level of abstraction
  std::string Property::to_string() const {
    std::string to_string_value;
    to_string_value += get_name() + ": ";
    if (get_type() == PType::ARRAY_PROPERTY) {
      to_string_value += "\n";
    }
    to_string_value += get_value_as_string();
    return to_string_value;
  }

  std::string Property::serialize_json() const {
    nlohmann::json prop;
    std::string id = get_name();
    if (get_type() == PType::ARRAY_PROPERTY) {
      prop[id] = nlohmann::json::parse(get_value_as_string());
    } else {
      prop[id] = get_value_as_string();
    }
    return prop.dump(4);
  }

} // namespace ReplayParser
