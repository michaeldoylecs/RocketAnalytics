/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayReplicatedPackages.cpp
 * Description:
 *   Represents the replicated Packages in a Rocket League replay file
 *****************************************************************************/

#include "../include/BinaryReader.hpp"
#include "../include/ReplayReplicatedPackages.hpp"


namespace ReplayParser {

  ReplayReplicatedPackages::ReplayReplicatedPackages() = default;

  ReplayReplicatedPackages::~ReplayReplicatedPackages() = default;

  ReplayReplicatedPackages ReplayReplicatedPackages::deserialize_replicated_packages(BinaryReader& br) {
    ReplayReplicatedPackages replicated_packages;
    uint32_t count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < count; ++i) {
      replicated_packages.add(br.read_length_prefixed_string());
    }
    return replicated_packages;
  }

  void ReplayReplicatedPackages::add(std::string package) {
    replicated_packages.push_back(package);
  }

  std::string ReplayReplicatedPackages::get(int index) {
    return replicated_packages.at(index);
  }

  int ReplayReplicatedPackages::count() {
    return replicated_packages.size();
  }

}
