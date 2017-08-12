// Author: Michael Doyle
// Date: 8/10/17
// Property.hpp

#ifndef PROPERTY_H
#define PROPERTY_H

#include "PropertyType.hpp"
#include <string>

namespace ReplayParser {

	class Property {
		public:
			Property(std::string name);
			std::string get_name();
			PType get_type();
			// TODO: Property value

		protected:
			std::string name;
			PType type = PType::NONE;

	};

}

#endif