/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/10/17
 *  File: Property.hpp
 *  Description:
 *    Property represents a piece of data from a Rocket League replay file.
 *****************************************************************************/

#ifndef PROPERTY_H
#define PROPERTY_H

#include "PropertyValue.hpp"
#include <vector>
#include <string>
#include <cstdint>

namespace rocketanalytics {

  enum class PType;

  class Property {
    public:
      Property();
      Property(const Property &property) = default;

      void set_none();
      void set_int(const std::string& name, const std::uint32_t& value);
      void set_string(const std::string& name, const std::string& value);
      void set_name(const std::string& name, const std::string& value);
      void set_bool(const std::string& name, const std::uint8_t& value);
      void set_qword(const std::string& name, const std::uint64_t& value);
      void set_byte(const std::string& name, const std::string& identifier,
                    const std::string& value);
      void set_float(const std::string& name, const float& value);
      void set_array(const std::string& name,
                     const std::vector<std::vector<Property>>& value);

      bool operator== (const Property& rhs) const;

      std::string name() const;
      PType type() const;
      PropertyValue value() const;
      std::string value_as_string() const;
      std::string to_string() const;
      std::string serialize_json() const;

    private:
      std::string property_name;
      PropertyValue property_value;
  };

} // namespace rocketanalytics

#endif
