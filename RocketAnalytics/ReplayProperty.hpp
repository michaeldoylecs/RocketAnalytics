// Author: Michael Doyle
// Date: 6/20/17
// ReplayProperty.hpp


#ifndef REPLAY_PROPERTY_H
#define REPLAY_PROPERTY_H

#include <string>
#include <cstdint>
#include <vector>

namespace ReplayProperty {

	// Replay Property Types
	enum Type {
		None = 0,
		IntProperty = 1, StrProperty = 2,
		NameProperty = 3, BoolProperty = 4,
		QWordProperty = 5, ByteProperty = 6,
		FloatProperty = 7, ArrayProperty = 8,
	};

	// String representation of Type enums
	const char * PROPERTY_TYPE_STRINGS[] = {"None", 
											"IntProperty", "StrProperty",
											"NameProperty", "BoolProperty",
											"QWordProperty", "ByteProperty",
											"FloatProperty", "ArrayProperty" };
	
	// Replay Property struct
	struct Property {
		std::string key;
		ReplayProperty::Type type;
		union value {
			std::int64_t i64;
			std::int32_t i32;
			std::int8_t i8;
			float f;
			bool b;
			std::string s;
			std::vector<std::vector<Property *>> v;
			value() {}
			~value() {}
		}value;
		Property() {}
		~Property() {}
		// HACK: (?) Property contructors may be a hack
	};


	// Functions

	// Convert Type ENUM to String
	std::string type_to_string(Type p_type);

	// Create Property in memory
	Property * create_property();

	// Destroy Property in memory
	void destroy_property(Property * property);

}
#endif