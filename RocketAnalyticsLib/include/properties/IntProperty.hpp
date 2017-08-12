// Author: Michael Doyle
// Date: 8/11/17
// IntProperty.hpp

#ifndef INT_PROPERTY_H
#define INT_PROPERTY_H

#include "Property.hpp"
#include <cstdint>

namespace ReplayParser {

	class IntProperty: public Property{
		public:
			IntProperty(std::string name, std::uint32_t value);
			std::uint32_t get_value();

		private:
			std::uint32_t value;
	};

}

#endif