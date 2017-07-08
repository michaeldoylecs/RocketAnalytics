// Author: Michael Doyle
// Date: 7/7/17
// ReplayProperty.cpp


#include <memory>
#include "ReplayProperty.hpp"

namespace ReplayProperty {

	// Convert Type ENUM to String
	std::string type_to_string(Type p_type) {
		return PROPERTY_TYPE_STRINGS[p_type];
	}

	// Create Property in memory
	Property * create_property() {
		Property * property_ptr = new Property;
		return property_ptr;
	}

	// Destroy Property in memory
	void destroy_property(Property * property) {
		delete property;
	}

}