// Author: Michael Doyle
// Date: 7/16/17
// ReplayPropertyValue.cpp


#include "../include/ReplayPropertyTypes.hpp"
#include "../include/ReplayProperty.hpp"
#include "../include/ReplayPropertyValue.hpp"


namespace ReplayProperty {
	
	Value::Value() {
		set_none();
	}


	Value::~Value() {
		destroy_value();
	}


	Type Value::type() {
		return type_;
	}


	void Value::set_none() {
		destroy_value();
		type_ = Type::None;
	}


	void Value::set_int(int32_t i) {
		destroy_value();
		type_ = Type::IntProperty;
		value_.i32 = i;
	}


	void Value::set_str(std::string str) {
		destroy_value();
		type_ = Type::StrProperty;
		new (&value_.s) std::string(std::move(str)); // HACK: Is this the proper way to move strings?
	}


	void Value::set_name(std::string name) {
		destroy_value();
		type_ = Type::NameProperty;
		new (&value_.s) std::string(std::move(name)); // HACK: Is this the proper way to move strings?
	}


	void Value::set_bool(bool b) {
		destroy_value();
		type_ = Type::BoolProperty;
		value_.b = b;
	}


	void Value::set_qword(std::int64_t qword) {
		destroy_value();
		type_ = Type::QWordProperty;
		value_.i64 = qword;
	}


	void Value::set_byte(std::int8_t byte) {
		destroy_value();
		type_ = Type::ByteProperty;
		value_.i8 = byte;
	}


	void Value::set_float(float f) {
		destroy_value();
		type_ = Type::FloatProperty;
		value_.f = f;
	}


	void Value::set_array(std::vector<std::vector<Property *>> vector) {
		destroy_value();
		type_ = Type::ArrayProperty;
		value_.v = vector; // HACK: Is this proper?
	}


	// Read Property value (as string)
	// TODO: FIX THIS FUNCTION
	std::string Value::to_string() {
		std::string value_string;

		// HACK(?): Is there a better way to do this?
		if (this->type() == ArrayProperty) { // HACK: Optimize reading vectors as string
			std::vector<std::vector<Property *>> full_property_array(value_.v);
			std::vector<std::vector<Property *>> full_property_array_copy(value_.v);
			std::vector<Property *> property_array;
			Property * property;
			while (!(full_property_array.empty())) {
				value_string += "\n\t[";

				// Take Array of Properties from Property vector
				property_array = full_property_array.back();
				full_property_array.pop_back();

				while (!(property_array.empty())) {
					// Take Property from Array of Properties
					property = property_array.back();
					property_array.pop_back();

					value_string += property->key();
					value_string += ": ";
					value_string += property->value_to_string();

					if (property_array.empty()) {
						break;
					}
					else {
						value_string += ", ";
					}
				} // While end

				value_string += "]";
			} // While end

			this->value_.v = full_property_array_copy;
		}
		else if (this->type() == IntProperty) {
			value_string = std::to_string(this->value_.i32);
		}
		else if (this->type() == StrProperty || this->type() == NameProperty) {
			value_string = this->value_.s;
		}
		else if (this->type() == BoolProperty) {
			this->value_.b ? value_string = "True" : value_string = "False";
		}
		else if (this->type() == QWordProperty) {
			value_string = std::to_string(this->value_.i64);
		}
		else if (this->type() == ByteProperty) {
			value_string = std::to_string(this->value_.i8);
		}
		else if (this->type() == FloatProperty) {
			value_string = std::to_string(this->value_.f);
		}
		return value_string;
	}


	void Value::destroy_value() {
	
		switch (type_) {
			case StrProperty:
				(&value_.s)->std::string::~basic_string();
				break;
			case NameProperty:
				(&value_.s)->std::string::~basic_string();
				break;
			case ArrayProperty:
				if (value_.s.empty()) {
					(&value_.v)->std::vector< std::vector<Property *> >::~vector();
				}
				break;
			default:
				value_.i64 = 0;

		}

		type_ = None;

	}


	Value::UValue::UValue() {
		i64 = 0;
	}


	Value::UValue::~UValue() {}

}
