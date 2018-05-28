/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	7/23/17
 *	File:	ReplayFile.hpp
 *	Description:
 *		ReplayFile contains all of the information stored in a Rocket League
 *	replay file. 
 *****************************************************************************/

#ifndef REPLAYFILE_HPP
#define REPLAYFILE_HPP

#include "ReplayHeader.hpp"
#include "ReplayKeyframes.hpp"
#include "ReplayLevels.hpp"
#include <cstdint>
#include <fstream>
#include <string>

namespace ReplayParser {

	class ReplayFile {
		public:
			explicit ReplayFile(const std::string &filepath);

			ReplayHeader get_header();
			ReplayLevels get_levels();
			ReplayKeyframes get_keyframes();

		private:
			std::string replay_file_path;

			ReplayHeader replay_header;
			ReplayLevels replay_levels;
			ReplayKeyframes replay_keyframes;
	};

} // namespace ReplayParser

#endif
