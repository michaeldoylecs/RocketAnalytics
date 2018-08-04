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

#include "ClassNetCacheObject.hpp"
#include "Netstream.hpp"
#include "ReplayHeader.hpp"
#include "ReplayKeyframes.hpp"
#include "ReplayLevels.hpp"
#include "ReplayReplicatedPackages.hpp"
#include "ReplayTickInformation.hpp"
#include <cstdint>
#include <fstream>
#include <string>
#include <utility>

namespace ReplayParser {

	class ReplayFile {
	  public:
	    explicit ReplayFile(std::string file);

	    ReplayHeader header();
	    ReplayLevels levels();
	    ReplayKeyframes keyframes();
      Netstream netstream();
      ReplayTickInformation tick_information();
      ReplayReplicatedPackages replicated_packages();
      std::vector<std::string> object_table();
      std::vector<std::string> name_table();
      std::vector<std::pair<std::string, std::uint32_t>> class_index_map();
      std::vector<ClassNetCacheObject> class_net_cache();

	  private:
	    std::string r_file_path;
	    ReplayHeader r_header;
	    ReplayLevels r_levels;
	    ReplayKeyframes r_keyframes;
      Netstream r_netstream;
      ReplayTickInformation r_tick_information;
      ReplayReplicatedPackages r_replicated_packages;
      std::vector<std::string> r_object_table;
      std::vector<std::string> r_name_table;
      std::vector<std::pair<std::string, std::uint32_t>> r_class_index_map;
      std::vector<ClassNetCacheObject> r_class_net_cache;

      std::vector<std::string> deserialize_object_table(BinaryReader& br);
      std::vector<std::string> deserialize_name_table(BinaryReader& br);
      std::vector<std::pair<std::string, std::uint32_t>>
        deserialize_class_index_map(BinaryReader& br);
      std::vector<ClassNetCacheObject>
        deserialize_class_net_cache(BinaryReader& br);
	};

} // namespace ReplayParser

#endif
