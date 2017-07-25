// Author: Michael Doyle
// Date: 7/23/17
// ReplayFileReader.hpp


#ifndef REPLAY_FILE_READER_H
#define REPLAY_FILE_READER_H

#include <cstdint>
#include <string>
#include <fstream>

namespace ReplayParser {

	class ReplayFileReader {

		public:
			// Constructors and Destructors
			ReplayFileReader(std::string filepath);
			~ReplayFileReader();

			// File reading
			std::int8_t		read_int8();				// Return 1 byte from file stream
			std::int32_t	read_int32();				// Return 4 bytes from file stream
			std::int64_t	read_int64();				// Return 8 bytes from file stream
			float			read_float();				// Return float from file stream
			bool			read_bool();				// Return bool from file stream
			std::string		read_string(int length);	// Return string from file stream

		private:
			// Fields
			std::string		filepath;
			std::ifstream	file_stream;

	};

}

#endif