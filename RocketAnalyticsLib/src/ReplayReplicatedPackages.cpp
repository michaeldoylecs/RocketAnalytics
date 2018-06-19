/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayReplicatedPackages.cpp
 * Description:
 *   Represents the replicated Packages in a Rocket League replay file
 *****************************************************************************/

#include "../include/ReplayReplicatedPackages.hpp"

namespace ReplayParser {

  ReplayReplicatedPackages::ReplayReplicatedPackages() = default;

  ReplayReplicatedPackages::~ReplayReplicatedPackages() = default;

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
