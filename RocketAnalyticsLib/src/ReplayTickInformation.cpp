/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayTickInformation.cpp
 * Description:
 *   Represents the Tick Information of a Rocket League replay file
 *****************************************************************************/

#include "../include/ReplayTickInformation.hpp"
#include "../include/ReplayTick.hpp"

namespace ReplayParser {

  ReplayTickInformation::ReplayTickInformation() = default;

  ReplayTickInformation::~ReplayTickInformation() = default;

  void ReplayTickInformation::add(ReplayTick tick) {
    replay_ticks.push_back(tick);
  }

  void ReplayTickInformation::add(std::string type, std::uint32_t frame) {
    ReplayTick tick = ReplayTick(type, frame);
    add(tick);
  }

  ReplayTick ReplayTickInformation::get(int index) {
    return replay_ticks.at(index);
  }

  int ReplayTickInformation::count() {
    return replay_ticks.size();
  }

}
