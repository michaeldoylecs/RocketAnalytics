/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/17/18
 * File: ReplayTick.cpp
 * Description:
 *   Represents a Tick in a Rocket League replay file.
 *****************************************************************************/

#include "../include/ReplayTick.hpp"

namespace ReplayParser {
  
  ReplayTick::ReplayTick() = default;

  ReplayTick::ReplayTick(std::string type, std::uint32_t frame) {
    this->tick_type = type;
    this->tick_frame = frame;
  }

  ReplayTick::~ReplayTick() = default;

  void ReplayTick::set_type(std::string type) {
    this->tick_type = type;
  }

  void ReplayTick::set_frame(std::uint32_t frame) {
    this->tick_frame = frame;
  }

  std::string ReplayTick::type() {
    return this->tick_type;
  }

  std::uint32_t ReplayTick::frame() {
    return this->tick_frame;
  }

}
