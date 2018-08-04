/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/11/17
 *  File: PropertyType.hpp
 *  Description:
 *    PropertyType represents the type of property that can be found in
 *  a Rocket League replay file.
 *****************************************************************************/

#ifndef PROPERTY_TYPE_H
#define PROPERTY_TYPE_H

#include <map>
#include <string>

namespace ReplayParser {

  enum class PType {
    NONE,
    INT_PROPERTY,
    STR_PROPERTY,
    NAME_PROPERTY,
    BOOL_PROPERTY,
    QWORD_PROPERTY,
    BYTE_PROPERTY,
    FLOAT_PROPERTY,
    ARRAY_PROPERTY
  };

  class PropertyType {
    public:
      static std::string property_type_to_string(PType property_type);
      static PType string_to_property_type(const std::string& property_type);

    private:
      static const std::map<PType, std::string>& type_string_map();
  };

} // namespace ReplayParser

#endif
