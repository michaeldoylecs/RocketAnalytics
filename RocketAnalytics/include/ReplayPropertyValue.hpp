// Author: Michael Doyle
// Date: 7/16/17
// ReplayPropertyValue.hpp


#ifndef REPLAY_PROPERTY_VALUE_H
#define REPLAY_PROPERTY_VALUE_H

#include <string>
#include <cstdint>
#include <vector>

namespace ReplayProperty {
	
	enum Type;
	class Property;

	class Value {
		public:
			// Constructors & Destructors
			Value();
			~Value();
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
			// Getters
			Type			type();
			std::string		to_string();

		private:
			// Fields
			Type type_;
			union UValue{
				std::int64_t i64;
				std::int32_t i32;
				std::int8_t i8;
				float f;
				bool b;
				std::string s;
				std::vector < std::vector<Property * >> v;
				UValue();
				~UValue();
			}value_;

			// Functions
			void destroy_value();
	};

}
#endif