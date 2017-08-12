// Author: Michael Doyle
// Date: 8/12/17
// StrProperty.cpp

#include "StrProperty.hpp"

namespace ReplayParser {

	StrProperty::StrProperty(std::string name, std::string value) : Property(name) {
		this->type = PType::STR_PROPERTY;
		this->value = value;
	}


	std::string StrProperty::get_value() {
		return value;
	}

}