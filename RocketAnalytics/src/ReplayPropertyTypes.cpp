// Author: Michael Doyle
// Date: 7/15/17
// ReplayPropertyTypes.cpp


#include "../include/ReplayPropertyTypes.hpp"

namespace ReplayProperty {

	// Convert Type ENUM to String
	std::string type_to_string(Type p_type) {
		return PROPERTY_TYPE_STRINGS[p_type];
	}

}