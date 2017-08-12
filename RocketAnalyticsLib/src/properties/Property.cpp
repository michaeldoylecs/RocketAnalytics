// Author: Michael Doyle
// Date: 8/11/17
// Property.cpp

#include "Property.hpp"

namespace ReplayParser {

	Property::Property(std::string name) {
		this->name = name;
		this->type = PType::NONE;
	}


	std::string Property::get_name() {
		return name;
	}


	PType Property::get_type() {
		return type;
	}

}