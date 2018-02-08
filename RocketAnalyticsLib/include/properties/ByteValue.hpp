/******************************************************************************
*	Author:	Michael Doyle
*	Date:	8/12/17
*	File:	ByteValue.hpp
*	Description:
*		ByteValue represents the 'ByteValue' property type found in Rocket
*	League replay files. The name does not have any connection to it's size or
*	inner workings.
******************************************************************************/

#ifndef BYTE_VALUE_H
#define BYTE_VALUE_H

#include <string>

using std::string;

namespace ReplayParser {

	class ByteValue {
		public:
			ByteValue();
			ByteValue(const ByteValue &byte);
			ByteValue(string identifier, string value);
			string get_identifer();
			string get_value();

		private:
			string byte_identifier;
			string byte_value;
	};
	
}

#endif
