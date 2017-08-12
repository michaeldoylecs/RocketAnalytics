// Author: Michael Doyle
// Date: 8/11/17
// Property.cpp

#include "properties\Property.hpp"

namespace ReplayParser {

	Property::Property(std::string name) {
		this->name = name;
	}


	std::string Property::get_name() {
		return name;
	}

}