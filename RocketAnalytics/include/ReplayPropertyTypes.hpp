// Author: Michael Doyle
// Date: 7/15/17
// ReplayPropertyTypes.hpp


#ifndef REPLAY_PROPERTY_TYPES_H
#define REPLAY_PROPERTY_TYPES_H

#include <string>

namespace ReplayProperty {

	// Replay Property Types
	enum Type {
		None = 0,
		IntProperty = 1, StrProperty = 2,
		NameProperty = 3, BoolProperty = 4,
		QWordProperty = 5, ByteProperty = 6,
		FloatProperty = 7, ArrayProperty = 8,
	};

	// Convert Type ENUM to String
	std::string type_to_string(Type p_type);

}
#endif
