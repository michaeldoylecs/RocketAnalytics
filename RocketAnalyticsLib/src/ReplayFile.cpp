/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	8/10/17
 *	File:	ReplayFile.cpp
 *****************************************************************************/

#include "../include/ReplayFile.hpp"
#include "../include/BinaryReader.hpp"

namespace ReplayParser {

	ReplayFile::ReplayFile(std::string& file): r_file_path(std::move(file)) {
	  BinaryReader br = BinaryReader(r_file_path);
	  r_header = ReplayHeader::deserialize_header(br);
	  r_levels = ReplayLevels::deserialize_levels(br);
	  r_keyframes = ReplayKeyframes::deserialize_keyframes(br);
	  r_netstream = Netstream::deserialize_netstream(br);
    r_tick_information = ReplayTickInformation::deserialize_tick_information(br);
    r_replicated_packages = ReplayReplicatedPackages::deserialize_replicated_packages(br);
    br.close();
	}

	ReplayHeader ReplayFile::header() {
	  return r_header;
	}

	ReplayLevels ReplayFile::levels() {
	  return r_levels;
	}

	ReplayKeyframes ReplayFile::keyframes() {
	  return r_keyframes;
	}

  Netstream ReplayFile::netstream() {
    return r_netstream;
  }

  ReplayTickInformation ReplayFile::tick_information() {
    return r_tick_information;
  }

  ReplayReplicatedPackages ReplayFile::replicated_packages() {
    return r_replicated_packages;
  }

} // namespace ReplayParser
