/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/18/18
 * File: ReplayTickInformation.hpp
 * Description:
 *   Represents the Tick Information of a Rocket League replay file.
 *****************************************************************************/

#ifndef REPLAYTICKINFORMATION_HPP
#define REPLAYTICKINFORMATION_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace ReplayParser {

  class ReplayTick;
  class BinaryReader;

  class ReplayTickInformation {
    public:
      ReplayTickInformation();
      ~ReplayTickInformation();
      static ReplayTickInformation deserialize_tick_information(BinaryReader& br);

      void add(ReplayTick tick);
      void add(std::string type, std::uint32_t frame);
      ReplayTick get(int index);
      int count();
    
    private:
      std::vector<ReplayTick> replay_ticks;
  };

}

#endif
