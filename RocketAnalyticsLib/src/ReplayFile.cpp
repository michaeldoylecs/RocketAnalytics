/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	8/10/17
 *	File:	ReplayFile.cpp
 *****************************************************************************/

#include "ReplayFile.hpp"
#include "BinaryReader.hpp"

namespace ReplayParser {

	ReplayFile::ReplayFile(std::string filepath) {
		replay_file_path = filepath;
		BinaryReader file_reader = BinaryReader(replay_file_path);
		replay_header = ReplayHeader::deserialize(file_reader);
		replay_levels = ReplayLevels::deserialize_levels(file_reader);
		replay_keyframes = ReplayKeyframes::deserialize_keyframes(file_reader);
		file_reader.close();
	}

	ReplayHeader ReplayFile::get_header() {
		return replay_header;
	}

	ReplayLevels ReplayFile::get_levels() {
		return replay_levels;
	}

	ReplayKeyframes ReplayFile::get_keyframes() {
		return replay_keyframes;
	}

}
