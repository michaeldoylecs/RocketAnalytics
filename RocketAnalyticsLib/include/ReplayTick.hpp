/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/17/18
 * File: ReplayTick.hpp
 * Description:
 *   Represents a Tick in a Rocket League replay file.
 *****************************************************************************/

#ifndef REPLAYTICK_HPP
#define REPLAYTICK_HPP

#include <cstdint>
#include <string>

namespace ReplayParser {
  
  class ReplayTick {
    public:
      ReplayTick();
      ReplayTick(std::string type, std::uint32_t frame);
      ~ReplayTick();

      void set_type(std::string type);
      void set_frame(uint32_t frame);
      std::string type();
      std::uint32_t frame();
    private:
      std::string tick_type;
      std::uint32_t tick_frame;
  };
  
}

#endif
