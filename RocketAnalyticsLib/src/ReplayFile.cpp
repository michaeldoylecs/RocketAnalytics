/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/10/17
 *  File: ReplayFile.cpp
 *****************************************************************************/

#include "../include/ReplayFile.hpp"
#include "../include/BinaryReader.hpp"

namespace rocketanalytics {

  ReplayFileImpl::ReplayFileImpl(std::string file)
  : r_file_path(std::move(file)) {
    try {
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
    } catch (const std::runtime_error &e) {
      throw;
    }
  }

  std::vector<std::string> ReplayFileImpl::deserialize_levels(BinaryReader& br) {
    std::vector<std::string> levels;
    std::uint32_t level_count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < level_count; i++) {
      auto level = br.read_length_prefixed_string();
      levels.push_back(level);
    }
    return levels;
  }

  std::vector<Keyframe> ReplayFileImpl::deserialize_keyframes(BinaryReader& br) {
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
  ReplayFileImpl::deserialize_tick_information(BinaryReader& br) {
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
  ReplayFileImpl::deserialize_replicated_packages(BinaryReader& br) {
    std::vector<std::string> replicated_packages;
    uint32_t count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < count; ++i) {
      auto package = br.read_length_prefixed_string();
      replicated_packages.push_back(package);
    }
    return replicated_packages;
  }

  std::vector<std::string>
  ReplayFileImpl::deserialize_object_table(BinaryReader& br) {
    std::vector<std::string> object_table;
    std::uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      object_table.push_back(std::string(br.read_length_prefixed_string()));
    }
    return object_table;
  }

  std::vector<std::string>
  ReplayFileImpl::deserialize_name_table(BinaryReader& br) {
    std::vector<std::string> name_table;
    uint32_t count = br.read_aligned_uint32();
    for (std::uint32_t i = 0; i < count; ++i) {
      name_table.push_back(std::string(br.read_length_prefixed_string()));
    }
    return name_table;
  }

  std::vector<std::pair<std::string, std::uint32_t>>
  ReplayFileImpl::deserialize_class_index_map(BinaryReader& br) { 
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
  ReplayFileImpl::deserialize_class_net_cache(BinaryReader& br) {
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

  ReplayHeader ReplayFileImpl::header() {
    return r_header;
  }

  std::vector<std::string> ReplayFileImpl::levels() {
    return r_levels;
  }

  std::vector<Keyframe> ReplayFileImpl::keyframes() {
    return r_keyframes;
  }

  Netstream ReplayFileImpl::netstream() {
    return r_netstream;
  }

  std::vector<ReplayTick> ReplayFileImpl::tick_information() {
    return r_tick_information;
  }

  std::vector<std::string> ReplayFileImpl::replicated_packages() {
    return r_replicated_packages;
  }

  std::vector<std::string> ReplayFileImpl::object_table() {
    return r_object_table;
  }

  std::vector<std::string> ReplayFileImpl::name_table() {
    return r_name_table;
  }

  std::vector<std::pair<std::string, std::uint32_t>>
  ReplayFileImpl::class_index_map() {
    return r_class_index_map;
  }

  std::vector<ClassNetCacheObject> ReplayFileImpl::class_net_cache() {
    return r_class_net_cache;
  }

  std::string ReplayFileImpl::serialize_to_json() {
    nlohmann::json replay;
    replay["header"] = header_to_json();
    replay["levels"] = levels_to_json();
    replay["keyframes"] = keyframes_to_json();
    replay["tickInformation"] = tick_information_to_json();
    replay["replicatedPackages"] = replicated_packages_to_json();
    replay["objectTable"] = object_table_to_json(); 
    replay["nameTable"] = name_table_to_json();
    replay["cacheIndexMap"] = class_index_map_to_json();
    replay["classNetCache"] = class_net_cache_to_json();
    return replay.dump(4);
  }

  nlohmann::json ReplayFileImpl::header_to_json() const {
    nlohmann::json header_json;
    header_json["fileInfo"]["headerSize"] = r_header.size();
    header_json["fileInfo"]["crc"] = r_header.crc1();
    header_json["fileInfo"]["version"] = r_header.version();
    header_json["fileInfo"]["identifier"] = r_header.replay_id();
    header_json["properties"] = properties_to_json();
    header_json["bodySize"] = r_header.body_size();
    header_json["crc2"] = r_header.crc2();
    return header_json;
  }

  nlohmann::json ReplayFileImpl::properties_to_json() const {
    nlohmann::json prop_json;
    auto properties = r_header.properties();
    for (const auto& prop : properties) {
      if (prop.type() == PType::NONE) { continue; }
      auto prop_value = nlohmann::json::parse(prop.serialize_json());
      prop_json.merge_patch(prop_value);
    }
    return prop_json;
  }

  nlohmann::json ReplayFileImpl::levels_to_json() const {
    nlohmann::json levels_json;
    for (const auto& level : r_levels) {
      levels_json.push_back(level);
    }
    return levels_json;
  } 

  nlohmann::json ReplayFileImpl::keyframes_to_json() const {
    nlohmann::json keyframes_json;
    for (const auto& keyframe : r_keyframes) {
      nlohmann::json kf_json = {
        {"time", keyframe.time()},
        {"frame", keyframe.frame()},
        {"filePosition", keyframe.filePos()}
      };
      keyframes_json.push_back(kf_json);
    }
    return keyframes_json;
  }

  nlohmann::json ReplayFileImpl::tick_information_to_json() const {
    nlohmann::json ticks_json;
    for (const auto& tick : r_tick_information) {
      nlohmann::json t_json = {
        {"type", tick.type()},
        {"frame", tick.frame()}
      };
      ticks_json.push_back(t_json);
    }
    return ticks_json;
  }

  nlohmann::json ReplayFileImpl::replicated_packages_to_json() const {
    nlohmann::json packages_json;
    for (const auto& package : r_replicated_packages) {
      packages_json.push_back(package);
    }
    return packages_json;
  }

  nlohmann::json ReplayFileImpl::object_table_to_json() const {
    nlohmann::json table_json;
    for (const auto& object : r_object_table) {
      table_json.push_back(object);
    }
    return table_json;
  }

  nlohmann::json ReplayFileImpl::name_table_to_json() const {
    nlohmann::json table_json;
    for (const auto& name : r_name_table) {
      table_json.push_back(name);
    }
    return table_json;
  }

  nlohmann::json ReplayFileImpl::class_index_map_to_json() const {
    nlohmann::json class_index_json;
    for (const auto& [c, i] : r_class_index_map) {
      nlohmann::json temp_pair = {
        {"class", c},
        {"index", i}
      };
      class_index_json.push_back(temp_pair);
    }
    return class_index_json;
  }

  nlohmann::json ReplayFileImpl::class_net_cache_to_json() const {
    nlohmann::json net_cache_json;
    for (const auto& cache_obj : r_class_net_cache) {
      nlohmann::json cache_obj_json = {
        {"index", cache_obj.index()},
        {"parent", cache_obj.parent()},
        {"id", cache_obj.id()},
        {"propLength", cache_obj.prop_length()}
      };
      nlohmann::json props_json;
      auto props = cache_obj.properties();
      for (const auto& [index, id] : props) {
        nlohmann::json prop_json = {
          {"index", index},
          {"id", id}
        };
        props_json.push_back(prop_json);
      }
      cache_obj_json["properties"] = props_json;
      net_cache_json.push_back(cache_obj_json);
    }
    return net_cache_json;
  }

} // namespace rocketanalytics
