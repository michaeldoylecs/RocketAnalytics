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

namespace rocketanalytics {
  
  class ReplayTick {
    public:
      ReplayTick() = default;
      ReplayTick(std::string type, std::uint32_t frame);

      void set_type(const std::string& type);
      void set_frame(const uint32_t& frame);
      std::string type() const;
      std::uint32_t frame() const;
    private:
      std::string tick_type;
      std::uint32_t tick_frame{};
  };
  
} // namespace rocketanalytics

#endif
