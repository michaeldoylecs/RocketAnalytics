/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayTickInformation.hpp
 * Description:
 *   Represents the Tick Information of a Rocket League replay file.
 *****************************************************************************/

#ifndef REPLAYTICKINFORMATION_HPP
#define REPLAYTICKINFORMATION_HPP

#include "ReplayTick.hpp"
#include <cstdint>
#include <string>
#include <vector>

namespace ReplayParser {

  class BinaryReader;

  class ReplayTickInformation {
    public:
      ReplayTickInformation();
      ~ReplayTickInformation();
      static ReplayTickInformation deserialize_tick_information(BinaryReader& br);

      void add(const ReplayTick& tick);
      void add(const std::string& type, uint32_t frame);
      ReplayTick get(int index);
      int count();
    
    private:
      std::vector<ReplayTick> replay_ticks;
  };

} // namespace ReplayParser

#endif
