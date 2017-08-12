// Author: Michael Doyle
// Date: 8/12/17
// StrProperty.hpp

#ifndef STR_PROPERTY_H
#define STR_PROPERTY_H

#include "Property.hpp"

namespace ReplayParser {

	class StrProperty : public Property {
		public:
			StrProperty(std::string name, std::string value);
			std::string get_value();

		private:
			std::string value;
	};

}

#endif