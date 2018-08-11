/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/10/17
 *  File: ReplayFile.cpp
 *****************************************************************************/

#include "../include/ReplayFile.hpp"
#include "../include/BinaryReader.hpp"
#include "../third-party/include/json.hpp"

namespace ReplayParser {

  ReplayFile::ReplayFile(std::string file)
  : r_file_path(std::move(file)) {
    BinaryReader br = BinaryReader(r_file_path);
    r_header = ReplayHeader::deserialize_header(br);
    r_levels = deserialize_levels(br);
    r_keyframes = deserialize_keyframes(br);
    r_netstream = Netstream::deserialize_netstream(br);
    br.read_aligned_uint32(); // Read empty int for debug_log
    r_tick_information = deserialize_tick_information(br);
    r_replicated_packages = deserialize_replicated_packages(br);
    r_object_table = deserialize_object_table(br);
    r_name_table = deserialize_name_table(br);
    r_class_index_map = deserialize_class_index_map(br);
    r_class_net_cache = deserialize_class_net_cache(br);
    br.close();
  }

  std::vector<std::string> ReplayFile::deserialize_levels(BinaryReader& br) {
    std::vector<std::string> levels;
    std::uint32_t level_count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < level_count; i++) {
      auto level = br.read_length_prefixed_string();
      levels.push_back(level);
    }
    return levels;
  }

  std::vector<Keyframe> ReplayFile::deserialize_keyframes(BinaryReader& br) {
    std::vector<Keyframe> keyframes;
    std::uint32_t keyframe_count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < keyframe_count; ++i) {
      auto time = br.read_aligned_float();
      auto frame = br.read_aligned_uint32();
      auto filePos = br.read_aligned_uint32();
      keyframes.emplace_back(Keyframe(time, frame, filePos));
    }
    return keyframes;
  }

  std::vector<ReplayTick>
  ReplayFile::deserialize_tick_information(BinaryReader& br) {
    std::vector<ReplayTick> tick_information;
    std::uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      auto type = br.read_length_prefixed_string();
      auto frame = br.read_aligned_uint32();
      tick_information.emplace_back(ReplayTick(type, frame));
    }
    return tick_information;
  }

  std::vector<std::string>
  ReplayFile::deserialize_replicated_packages(BinaryReader& br) {
    std::vector<std::string> replicated_packages;
    uint32_t count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < count; ++i) {
      auto package = br.read_length_prefixed_string();
      replicated_packages.push_back(package);
    }
    return replicated_packages;
  }

  std::vector<std::string>
  ReplayFile::deserialize_object_table(BinaryReader& br) {
    std::vector<std::string> object_table;
    std::uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      object_table.push_back(std::string(br.read_length_prefixed_string()));
    }
    return object_table;
  }

  std::vector<std::string>
  ReplayFile::deserialize_name_table(BinaryReader& br) {
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

  std::vector<ClassNetCacheObject>
  ReplayFile::deserialize_class_net_cache(BinaryReader& br) {
    std::vector<ClassNetCacheObject> class_net_cache;
    uint32_t count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < count; ++i) {
      std::uint32_t index = br.read_aligned_uint32();
      std::uint32_t parent = br.read_aligned_uint32();
      std::uint32_t id = br.read_aligned_uint32();
      std::uint32_t prop_length = br.read_aligned_uint32();
      std::vector<std::pair<std::uint32_t, std::uint32_t>> properties;
      for (std::uint32_t i = 0; i < prop_length; ++i) {
        std::uint32_t prop_index = br.read_aligned_uint32();
        std::uint32_t prop_id = br.read_aligned_uint32();
        properties.emplace_back(prop_index, prop_id);
      }
      class_net_cache.emplace_back(
        ClassNetCacheObject(index, parent, id, prop_length, properties)
      );
    }
    return class_net_cache;
  }

  ReplayHeader ReplayFile::header() {
    return r_header;
  }

  std::vector<std::string> ReplayFile::levels() {
    return r_levels;
  }

  std::vector<Keyframe> ReplayFile::keyframes() {
    return r_keyframes;
  }

  Netstream ReplayFile::netstream() {
    return r_netstream;
  }

  std::vector<ReplayTick> ReplayFile::tick_information() {
    return r_tick_information;
  }

  std::vector<std::string> ReplayFile::replicated_packages() {
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

  std::vector<ClassNetCacheObject> ReplayFile::class_net_cache() {
    return r_class_net_cache;
  }

  std::string ReplayFile::serialize_to_json() {
    nlohmann::json replay;

    // File information
    replay["header"]["file_info"]["header_size"] = r_header.get_header_size();
    replay["header"]["file_info"]["crc"] = r_header.get_crc1();
    replay["header"]["file_info"]["version"] = r_header.get_version();
    replay["header"]["file_info"]["identifier"] = r_header.get_replay_identifier();

    // Properties
    auto properties = r_header.get_properties();
    for (auto prop : properties) {
      replay["header"]["properties"][prop.get_name()] = prop.get_value_as_string();
    }

    replay["header"]["body_size"] = r_header.get_body_size();
    replay["header"]["crc2"] = r_header.get_crc2();

    // Levels
    auto levels = r_levels;
    for (size_t i = 0; i < levels.size(); i++) {
      replay["levels"][std::to_string(i)] = levels[i];
    }

    return replay.dump(4);
  }

} // namespace ReplayParser
