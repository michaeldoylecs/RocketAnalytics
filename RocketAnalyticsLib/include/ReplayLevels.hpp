/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 1/28/18
 *  File: ReplayLevels.hpp
 *  Description:
 *    ReplayLevels contains all of the maps included in the Rocket League
 *  replay file.
 *****************************************************************************/

#ifndef REPLAY_LEVELS_H
#define REPLAY_LEVELS_H

#include "BinaryReader.hpp"

using std::vector;
using std::string;

namespace rocketanalytics {

  class ReplayLevels {
  public:
    static ReplayLevels deserialize_levels(BinaryReader& binary_reader);

    vector<string> get_levels();
    size_t get_level_count();

  private:
    vector<string> levels;
  };

}

#endif
