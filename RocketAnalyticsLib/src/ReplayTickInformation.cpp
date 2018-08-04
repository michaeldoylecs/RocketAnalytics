/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayTickInformation.cpp
 * Description:
 *   Represents the Tick Information of a Rocket League replay file
 *****************************************************************************/

#include "../include/BinaryReader.hpp"
#include "../include/ReplayTick.hpp"
#include "../include/ReplayTickInformation.hpp"

namespace ReplayParser {

  ReplayTickInformation::ReplayTickInformation() = default;

  ReplayTickInformation::~ReplayTickInformation() = default;

  ReplayTickInformation ReplayTickInformation::deserialize_tick_information(BinaryReader& br) {
    ReplayTickInformation tick_information;
    uint32_t count = br.read_aligned_uint32();
    for (uint32_t i = 0; i < count; ++i) {
      std::string type = br.read_length_prefixed_string();
      std::uint32_t frame = br.read_aligned_uint32();
      tick_information.add(type, frame);
    }
    return tick_information;
  }

  void ReplayTickInformation::add(const ReplayTick& tick) {
    replay_ticks.push_back(tick);
  }

  void ReplayTickInformation::add(const std::string& type, uint32_t frame) {
    ReplayTick tick = ReplayTick(type, frame);
    add(tick);
  }

  ReplayTick ReplayTickInformation::get(int index) {
    return replay_ticks.at(index);
  }

  int ReplayTickInformation::count() {
    return replay_ticks.size();
  }

} // namespace ReplayParser
