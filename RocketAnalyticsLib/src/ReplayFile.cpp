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
    br.read_aligned_uint32(); // Read empty int for debug_log
    r_tick_information =
      ReplayTickInformation::deserialize_tick_information(br);
    r_replicated_packages =
      ReplayReplicatedPackages::deserialize_replicated_packages(br);
    r_object_table = deserialize_object_table(br);
    r_name_table = deserialize_name_table(br);
    r_class_index_map = deserialize_class_index_map(br);
    br.close();
	}

  std::vector<std::string> ReplayFile::deserialize_object_table(BinaryReader& br) {
    std::vector<std::string> object_table;
    std::uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      object_table.push_back(std::string(br.read_length_prefixed_string()));
    }
    return object_table;
  }

  std::vector<std::string> ReplayFile::deserialize_name_table(BinaryReader& br) {
    std::vector<std::string> name_table;
    uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      name_table.push_back(std::string(br.read_length_prefixed_string()));
    }
    return name_table;
  }

  std::vector<std::pair<std::string, std::uint32_t>>
  ReplayFile::deserialize_class_index_map(BinaryReader& br) { 
    std::vector<std::pair<std::string, std::uint32_t>> class_index_map;
    std::uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      std::string object = br.read_length_prefixed_string();
      std::uint32_t index = br.read_aligned_uint32();
      class_index_map.emplace_back(object, index);
    }
    return class_index_map;
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

  std::vector<std::string> ReplayFile::object_table() {
    return r_object_table;
  }

  std::vector<std::string> ReplayFile::name_table() {
    return r_name_table;
  }

  std::vector<std::pair<std::string, std::uint32_t>>
  ReplayFile::class_index_map() {
    return r_class_index_map;
  }

} // namespace ReplayParser
