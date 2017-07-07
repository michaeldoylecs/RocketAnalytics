// Author: Michael Doyle
// Date: 6/20/17
// ReplayProperty.hpp


#ifndef REPLAY_PROPERTY_H
#define REPLAY_PROPERTY_H

#include <string>
#include <cstdint>
#include <vector>

namespace ReplayProperty {

	const char * PROPERTY_NONE = "None";

	enum Type {
		IntProperty = 0, StrProperty = 1,
		NameProperty = 2, BoolProperty = 3,
		QWordProperty = 4, ByteProperty = 5,
		FloatProperty = 6, ArrayProperty = 7
	};


	const char * PROPERTY_TYPE_STRINGS[] = { "IntProperty", "StrProperty",
											"NameProperty", "BoolProperty",
											"QWordProperty", "ByteProperty",
											"FloatProperty", "ArrayProperty" };

	std::string property_type_to_string(Type p_type) {
		return PROPERTY_TYPE_STRINGS[p_type];
	}


	struct Property {
		std::int32_t key_length;
		std::string key;
		ReplayProperty::Type type;
		union value {
			std::int64_t i64;
			std::int32_t i32;
			float f;
			bool b;
			std::string s;
			std::vector<Property> v;
		}value;
	};

}

#endif