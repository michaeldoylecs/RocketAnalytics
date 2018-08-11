/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/17/18
 * File: ReplayTick.cpp
 * Description:
 *   Represents a Tick in a Rocket League replay file.
 *****************************************************************************/

#include "../include/ReplayTick.hpp"
#include <utility>

namespace ReplayParser {

  ReplayTick::ReplayTick(std::string type, std::uint32_t frame)
    : tick_type{std::move(type)}, tick_frame{frame} {}

  void ReplayTick::set_type(const std::string &type) { this->tick_type = type; }

  void ReplayTick::set_frame(const std::uint32_t &frame) {
    this->tick_frame = frame;
  }

  std::string ReplayTick::type() const {
    return this->tick_type;
  }

  std::uint32_t ReplayTick::frame() const {
    return this->tick_frame;
  }

} // namespace ReplayParser
