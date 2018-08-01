/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayReplicatedPackages.hpp
 * Description:
 *   Represents the Replicated Packages in a Rocket League replay file
 *****************************************************************************/

#ifndef REPLAYREPLICATEDPACKAGES_HPP
#define REPLAYREPLICATEDPACKAGES_HPP

#include <string>
#include <vector>

namespace ReplayParser {

  class BinaryReader;

  class ReplayReplicatedPackages {
    public:
      ReplayReplicatedPackages() = default;
      static ReplayReplicatedPackages
        deserialize_replicated_packages(BinaryReader& br);
      
      void add(const std::string& package);
      std::string get(int index);
      int count();

    private:
      std::vector<std::string> replicated_packages;
  };

} // namespace ReplayParser

#endif
