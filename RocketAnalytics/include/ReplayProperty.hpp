// Author: Michael Doyle
// Date: 6/20/17
// ReplayProperty.hpp


#ifndef REPLAY_PROPERTY_H
#define REPLAY_PROPERTY_H

#include <string>
#include <cstdint>
#include <vector>
#include "ReplayPropertyTypes.hpp"
#include "ReplayPropertyValue.hpp"

namespace ReplayProperty {

	class Property {
		public:
			// Constructors & Destructors
			Property(); // TODO: Make overloaded Property constructors
			~Property(); // TODO: Make Property destructors.

			// Member Getters
			std::string		key();
			Type			type();
			Value *			value();
			std::string		value_to_string();

			// Setters
			void			set_none();
			void			set_int(std::int32_t i);
			void			set_str(std::string str);
			void			set_name(std::string name);
			void			set_bool(bool b);
			void			set_qword(std::int64_t qword);
			void			set_byte(std::int8_t byte);
			void			set_float(float f);
			void			set_array(std::vector<std::vector<Property *>> vector);



	private:
		// Members
		std::string key_;
		Value value_;
	};
	

	/* REMOVED CODE
	// Replay Property struct
	struct Property {
		std::string key;
		Type type;
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
	};
	*/

}
#endif