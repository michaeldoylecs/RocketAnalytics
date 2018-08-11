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
#include "Keyframe.hpp"
#include "ReplayTick.hpp"
#include "../third-party/include/json.hpp"
#include <cstdint>
#include <fstream>
#include <string>
#include <utility>

namespace ReplayParser {

	class ReplayFile {
	  public:
	    explicit ReplayFile(std::string file);

	    ReplayHeader header();
      std::vector<std::string> levels();
      std::vector<Keyframe> keyframes();
      Netstream netstream();
      std::vector<ReplayTick> tick_information();
      std::vector<std::string> replicated_packages();
      std::vector<std::string> object_table();
      std::vector<std::string> name_table();
      std::vector<std::pair<std::string, std::uint32_t>> class_index_map();
      std::vector<ClassNetCacheObject> class_net_cache();
      std::string serialize_to_json();

	  private:
	    std::string r_file_path;
	    ReplayHeader r_header;
      std::vector<std::string> r_levels;
      std::vector<Keyframe> r_keyframes;
      Netstream r_netstream;
      std::vector<ReplayTick> r_tick_information;
      std::vector<std::string> r_replicated_packages;
      std::vector<std::string> r_object_table;
      std::vector<std::string> r_name_table;
      std::vector<std::pair<std::string, std::uint32_t>> r_class_index_map;
      std::vector<ClassNetCacheObject> r_class_net_cache;

      std::vector<std::string> deserialize_levels(BinaryReader& br);
      std::vector<Keyframe> deserialize_keyframes(BinaryReader& br);
      std::vector<ReplayTick> deserialize_tick_information(BinaryReader& br);
      std::vector<std::string> deserialize_replicated_packages(BinaryReader& br);
      std::vector<std::string> deserialize_object_table(BinaryReader& br);
      std::vector<std::string> deserialize_name_table(BinaryReader& br);
      std::vector<std::pair<std::string, std::uint32_t>>
        deserialize_class_index_map(BinaryReader& br);
      std::vector<ClassNetCacheObject>
        deserialize_class_net_cache(BinaryReader& br);
     
      nlohmann::json header_to_json() const;
      nlohmann::json properties_to_json() const;
      nlohmann::json levels_to_json() const;
      nlohmann::json keyframes_to_json() const;
      nlohmann::json tick_information_to_json() const;
      nlohmann::json replicated_packages_to_json() const;
      nlohmann::json object_table_to_json() const;
      nlohmann::json name_table_to_json() const;
      nlohmann::json class_index_map_to_json() const;
      nlohmann::json class_net_cache_to_json() const;
	};

} // namespace ReplayParser

#endif
