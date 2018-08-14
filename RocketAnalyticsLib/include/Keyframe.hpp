/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 2/19/18
 *  File: Keyframe.hpp
 *  Description:
 *    Represents a Keyframe.
 *****************************************************************************/

#ifndef KEYFRAME_HPP
#define KEYFRAME_HPP

#include <cstdint>

namespace ReplayParser {

  class Keyframe {
  public:
    Keyframe(float time, std::uint32_t frame, std::uint32_t filePos);

    float time() const;
    std::uint32_t frame() const;
    std::uint32_t filePos() const;

    bool operator==(const Keyframe &k1) const;
    bool operator!=(const Keyframe &k1) const;

  private:
    float k_time;
    std::uint32_t k_frame;
    std::uint32_t k_filePos;
  };

} // namespace ReplayParser

#endif
