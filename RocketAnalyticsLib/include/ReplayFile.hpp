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

#include "Netstream.hpp"
#include "ReplayHeader.hpp"
#include "ReplayKeyframes.hpp"
#include "ReplayLevels.hpp"
#include "ReplayReplicatedPackages.hpp"
#include "ReplayTickInformation.hpp"
#include <cstdint>
#include <fstream>
#include <string>

namespace ReplayParser {

	class ReplayFile {
	  public:
	    explicit ReplayFile(std::string& file);

	    ReplayHeader header();
	    ReplayLevels levels();
	    ReplayKeyframes keyframes();
      Netstream netstream();
      ReplayTickInformation tick_information();
      ReplayReplicatedPackages replicated_packages();

	  private:
	    std::string r_file_path;

	    ReplayHeader r_header;
	    ReplayLevels r_levels;
	    ReplayKeyframes r_keyframes;
      Netstream r_netstream;
      ReplayTickInformation r_tick_information;
      ReplayReplicatedPackages r_replicated_packages;
	};

} // namespace ReplayParser

#endif
