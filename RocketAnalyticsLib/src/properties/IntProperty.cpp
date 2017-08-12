// Author: Michael Doyle
// Date: 8/11/17
// IntProperty.cpp

#include "IntProperty.hpp"

namespace ReplayParser {

	IntProperty::IntProperty(std::string name, std::uint32_t value): Property(name) {
		this->type = PType::INT_PROPERTY;
		this->value = value;
	}


	std::uint32_t IntProperty::get_value() {
		return value;
	}

}