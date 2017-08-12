// Author: Michael Doyle
// Date: 8/10/17
// Property.hpp

#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

namespace ReplayParser {

	class Property {
		public:
			Property(std::string name);
			std::string get_name();
			//TODO: PropertyType get_type();

		protected:
			std::string name;
			//TODO: PropertyType type;
	};

}

#endif