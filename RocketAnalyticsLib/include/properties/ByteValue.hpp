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
			/*
			 *	Default constructor.
			 */
			ByteValue();

			/*
			 *	Constructs a copy of a given ByteValue.
			 */
			ByteValue(const ByteValue &byte);

			/*
			 *	Constructs a ByteValue given its identifier and value.
			 */
			ByteValue(string identifier, string value);

			/*
			 *	Returns the ByteValue's identifer.
			 */
			string get_identifer();

			/*
			 *	Returns the ByteValue's value.
			 */
			string get_value();

		private:
			/*
			 *	ByteValue data members.
			 */
			string byte_identifier;
			string byte_value;
	};
	
}

#endif
