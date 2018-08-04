/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/11/17
 *  File: PropertyType.cpp
 *****************************************************************************/

#include "../../include/properties/PropertyType.hpp"
#include <iostream>

namespace ReplayParser {

  const std::map<PType, std::string>& PropertyType::type_string_map() {
    try {
      static const std::map<PType, std::string> prop_map {
        {PType::NONE, "None"},
        {PType::INT_PROPERTY, "IntProperty"},
        {PType::STR_PROPERTY, "StrProperty"},
        {PType::NAME_PROPERTY, "NameProperty"},
        {PType::BOOL_PROPERTY, "BoolProperty"},
        {PType::QWORD_PROPERTY, "QWordProperty"},
        {PType::BYTE_PROPERTY, "ByteProperty"},
        {PType::FLOAT_PROPERTY, "FloatProperty"},
        {PType::ARRAY_PROPERTY, "ArrayProperty"}
      };
      return prop_map;
    } catch (std::bad_alloc& e) {
      std::cerr << e.what() << std::endl;
      throw e;
    };
  }

  std::string PropertyType::property_type_to_string(PType property_type) {
    return type_string_map().at(property_type);
  }

  PType PropertyType::string_to_property_type(const std::string& property_type) {
    auto prop_map = type_string_map();
    for (auto&& [key, value] : prop_map) {
      if (value == property_type) {
        return key;
      }
    }
    return PType::NONE;
  }

} // namespace ReplayParser
