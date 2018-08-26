/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/17/18
 * File: ReplayTick.cpp
 * Description:
 *   Represents a Tick in a Rocket League replay file.
 *****************************************************************************/

#include "../include/ReplayTick.hpp"
#include <utility>

namespace rocketanalytics {

  ReplayTick::ReplayTick(std::string type, std::uint32_t frame)
    : tick_type{std::move(type)}, tick_frame{frame} {}

  void ReplayTick::set_type(const std::string &type) { tick_type = type; }

  void ReplayTick::set_frame(const std::uint32_t &frame) {
    tick_frame = frame;
  }

  std::string ReplayTick::type() const {
    return tick_type;
  }

  std::uint32_t ReplayTick::frame() const {
    return tick_frame;
  }

} // namespace rocketanalytics
