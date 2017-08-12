// Author: Michael Doyle
// Date: 8/12/17
// PropertyValue.hpp

#ifndef PROPERTY_VALUE_H
#define PROPERTY_VALUE_H

#include "Property.hpp"
#include <cstdint>

namespace ReplayParser {
	enum PType;

	class PropertyValue {
		public:
			PropertyValue();
			PType get_type();

		private:
			PType property_type;
			union {
				std::uint64_t int64;
				std::uint32_t int32;
				std::int8_t int8;
				std::string string;
				float f;
				bool b;
				// TODO: Byte Property
				// TODO: Array Property
			} value;
 	};

}

#endif