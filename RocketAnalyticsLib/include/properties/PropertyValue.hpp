// Author: Michael Doyle
// Date: 8/12/17
// PropertyValue.hpp

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
			PropertyValue();
			~PropertyValue();

			PropertyValue(const PropertyValue &propertyValue);
			PropertyValue& operator= (const PropertyValue &propertyValue);

			void set_none();
			void set_int(std::uint32_t int32);
			void set_string(std::string string);
			void set_name(std::string name);
			void set_bool(bool b);
			void set_qword(std::uint64_t qword);
			void set_byte(ByteValue byte);
			void set_byte(std::string identifier, std::string value);
			void set_float(float f);
			void set_array(std::vector<Property> property_list);

			PType get_type();
			std::string get_value_as_string();

		private:
			PType property_type;
			union UValue {
				std::uint64_t int64;
				std::uint32_t int32;
				float f;
				bool b;
				std::string string;
				ByteValue byte;
				std::vector<Property> list;
				UValue(); // HACK: Is this necessary for PropertyValue constructor?
				~UValue();
			} property_value;

			void deconstruct_union_values_if_necessary();
			std::string array_properties_to_string();
	};

}

#endif