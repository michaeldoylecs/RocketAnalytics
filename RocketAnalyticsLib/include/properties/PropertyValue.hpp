/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/12/17
 *  File: PropertyValue.hpp
 *  Description:
 *    PropertyValue represents the value of a property that is found in
 *  Rocket League replay files.
 *****************************************************************************/

#ifndef PROPERTY_VALUE_H
#define PROPERTY_VALUE_H

#include "ByteValue.hpp"
#include "PropertyType.hpp"
#include <string>
#include <cstdint>
#include <vector>

namespace ReplayParser {

  // TODO: Can these be cleaned up?
  class Property;

  class PropertyValue {
    public:
      union UValue {
        std::uint64_t int64;
        std::uint32_t int32;
        std::uint8_t int8;
        float f;
        std::string string;
        ByteValue byte;
        //TODO: Rewrite as custom class (maybe?)
        std::vector< std::vector<Property> > list;
        UValue(); // HACK: Is this necessary for
        ~UValue();  // PropertyValue constructor?
      } property_value;

      PropertyValue();
      ~PropertyValue();

      PropertyValue(const PropertyValue &propertyValue);
      PropertyValue& operator= (const PropertyValue &propertyValue);

      void set_none();
      void set_int(const std::uint32_t int32);
      void set_string(const std::string& string);
      void set_name(const std::string& name);
      void set_bool(const std::uint8_t int8);
      void set_qword(const std::uint64_t qword);
      void set_byte(const ByteValue& byte);
      void set_byte(const std::string& identifier, const std::string& value);
      void set_float(const float f);
      void set_array(const std::vector<std::vector<Property>>& property_list);

      PType get_type() const;
      std::string get_value_as_string() const;

    private:
      PType property_type;

      void deconstruct_union_values_if_necessary();
      std::string array_properties_to_string() const;
  };

} // namespace ReplayParser

#endif
