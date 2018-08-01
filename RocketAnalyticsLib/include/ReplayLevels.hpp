/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	1/28/18
 *	File:	ReplayLevels.hpp
 *	Description:
 *		ReplayLevels contains all of the maps included in the Rocket League
 *	replay file.
 *****************************************************************************/

#ifndef REPLAYLEVELS_HPP
#define REPLAYLEVELS_HPP

#include "BinaryReader.hpp"

namespace ReplayParser {

	class ReplayLevels {
	public:
		static ReplayLevels deserialize_levels(BinaryReader& binary_reader);

    std::vector<std::string> get_levels();
		size_t get_level_count();

	private:
    std::vector<std::string> levels;
	};

} // namespace ReplayParser

#endif
