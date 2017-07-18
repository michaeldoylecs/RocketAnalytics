// Author: Michael Doyle
// Date: 7/7/17
// ReplayProperty.cpp


#include "../include/ReplayProperty.hpp"
#include "../include/ReplayPropertyTypes.hpp"
#include "../include/ReplayPropertyValue.hpp"

namespace ReplayProperty {

	Property::Property() {
		value_.set_none();
	}


	Property::~Property() {	
		// TODO: Make Property destructor
	}


	// Read Property key
	std::string Property::key() {
		return key_;
	}


	// Read Property type
	Type Property::type() {
		return value_.type();
	}


	Value * Property::value() {
		return &value_;
	}


	// Read Property value (as string)
	std::string Property::value_to_string() {
		std::string value_string;
		value_string = value_.to_string();
		return value_string;
	}


	void Property::set_none() {
		value_.set_none();
	}


	void Property::set_int(int32_t i) {
		value_.set_int(i);
	}


	void Property::set_str(std::string str) {
		value_.set_str(str);
	}


	void Property::set_name(std::string name) {
		value_.set_name(name);
	}


	void Property::set_bool(bool b) {
		value_.set_bool(b);
	}


	void Property::set_qword(std::int64_t qword) {
		value_.set_qword(qword);
	}


	void Property::set_byte(std::int8_t byte) {
		value_.set_byte(byte);
	}


	void Property::set_float(float f) {
		value_.set_float(f);
	}


	void Property::set_array(std::vector<std::vector<Property *>> vector) {
		value_.set_array(vector);
	}
}