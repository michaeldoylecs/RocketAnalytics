/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	7/23/17
 *	File:	ReplayFileReader.hpp
 *	Description:
 *		ReplayFileReader handles the logic in reading Rocket League replay
 *	files.
 *****************************************************************************/

#ifndef REPLAY_FILE_READER_H
#define REPLAY_FILE_READER_H

#include <cstdint>
#include <string>
#include <fstream>

namespace ReplayParser {

	class ReplayFile;

	class ReplayFileReader {
		public:
			ReplayFileReader();
			ReplayFileReader(std::string filepath);
			~ReplayFileReader();
			std::int8_t	read_int8();
			std::int32_t read_int32();
			std::int64_t read_int64();
			float read_float();
			bool read_bool();
			std::string	read_string(int length);

		private:
			std::ifstream replay_file_stream;
			std::string replay_file_path;
	};

}
#endif
