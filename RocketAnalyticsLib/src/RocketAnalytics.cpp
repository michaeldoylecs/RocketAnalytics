/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	8/16/18
 *	File:	RocketAnalytics.cpp
 *****************************************************************************/

#include "../include/RocketAnalytics.hpp"

namespace rocketanalytics {

  ReplayFile::ReplayFile(std::string file)
    : d_ptr(new ReplayFileImpl(std::move(file))) {}

  ReplayHeader ReplayFile::header() {
    return d_ptr->header();
  }

  std::vector<std::string> ReplayFile::levels() {
    return d_ptr->levels();
  }

  std::vector<Keyframe> ReplayFile::keyframes() {
    return d_ptr->keyframes();
  }

  Netstream ReplayFile::netstream() {
    return d_ptr->netstream();
  }

  std::vector<ReplayTick> ReplayFile::tick_information() {
    return d_ptr->tick_information();
  }

  std::vector<std::string> ReplayFile::replicated_packages() {
    return d_ptr->replicated_packages();
  }

  std::vector<std::string> ReplayFile::object_table() {
    return d_ptr->object_table();
  }

  std::vector<std::string> ReplayFile::name_table() {
    return d_ptr->name_table();
  }

  std::vector<std::pair<std::string, std::uint32_t>>
  ReplayFile::class_index_map() {
    return d_ptr->class_index_map();
  }

  std::vector<ClassNetCacheObject> ReplayFile::class_net_cache() {
    return d_ptr->class_net_cache();
  }

  std::string ReplayFile::serialize_to_json() {
    return d_ptr->serialize_to_json();
  }

} // namespace rocketanalytics
