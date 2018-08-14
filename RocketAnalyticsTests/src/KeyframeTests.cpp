/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/16/18
 * File: KeyframeTests.cpp
 * Description:
 *   Unit tests for the Keyframe implementation.
 *****************************************************************************/

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../RocketAnalyticsLib/include/Keyframe.hpp"

using ReplayParser::Keyframe;

struct KeyframeTests: testing::Test {
  Keyframe keyframe = Keyframe(0, 0, 0);
  float timeStamp = 47.72253;
  std::uint32_t frameNum = 1042;
  std::uint32_t filePos = 466305;

  KeyframeTests() {
    keyframe = Keyframe(timeStamp, frameNum, filePos);
  }

  ~KeyframeTests() override = default;
};

TEST_F(KeyframeTests, KeyframeAccessTests) {
  EXPECT_EQ(keyframe.time(), timeStamp);
  EXPECT_EQ(keyframe.frame(), frameNum);
  EXPECT_EQ(keyframe.filePos(), filePos);
}
