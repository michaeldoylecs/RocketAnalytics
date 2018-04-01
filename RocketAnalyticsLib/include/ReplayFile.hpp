/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	7/23/17
 *	File:	ReplayFile.hpp
 *	Description:
 *		ReplayFile contains all of the information stored in a Rocket League
 *	replay file. 
 *****************************************************************************/

#ifndef REPLAY_FILE_H
#define REPLAY_FILE_H

#include <cstdint>
#include <string>
#include <fstream>
#include "ReplayHeader.hpp"
#include "ReplayLevels.hpp"
#include "ReplayKeyframes.hpp"

namespace ReplayParser {

	class ReplayFile {
		public:
			ReplayFile(std::string filepath);

			ReplayHeader get_header();
			ReplayLevels get_levels();
			ReplayKeyframes get_keyframes();

		private:
			std::string replay_file_path;

			ReplayHeader replay_header;
			ReplayLevels replay_levels;
			ReplayKeyframes replay_keyframes;
	};

}
#endif
