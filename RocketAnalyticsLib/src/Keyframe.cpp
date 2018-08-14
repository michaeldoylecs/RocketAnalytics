/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 3/31/18
 *  File: Keyframe.cpp
 *****************************************************************************/

#include "../include/Keyframe.hpp"

using std::uint32_t;

namespace ReplayParser {

  Keyframe::Keyframe(float time, uint32_t frame, uint32_t filePos) {
    k_time = time;
    k_frame = frame;
    k_filePos = filePos;
  }

  float Keyframe::time() const {
    return k_time;
  }

  uint32_t Keyframe::frame() const {
    return k_frame;
  }

  uint32_t Keyframe::filePos() const {
    return k_filePos;
  }

  bool Keyframe::operator==(const Keyframe &k1) const {
    return (k_time == k1.k_time &&
      k_frame == k1.k_frame &&
      k_filePos == k1.k_filePos);
  }
  
  bool Keyframe::operator!=(const Keyframe &k1) const {
    return (k_time != k1.k_time ||
      k_frame != k1.k_frame ||
      k_filePos != k1.k_filePos);
  }
} // namespace ReplayParser
