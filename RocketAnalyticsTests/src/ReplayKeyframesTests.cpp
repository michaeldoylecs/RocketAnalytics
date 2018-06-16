/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/16/18
 * File: ReplayKeyframesTests.cpp
 * Description:
 *   Unit tests for the ReplayKeyframes class
 *****************************************************************************/

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../RocketAnalyticsLib/include/ReplayKeyframes.hpp"

using ReplayParser::ReplayKeyframes;
using ReplayParser::Keyframe;

struct ReplayKeyframesTests: testing::Test {
  ReplayKeyframes keyframes;
  Keyframe keyframe_0 = Keyframe(0, 0, 0);
  Keyframe keyframe_1 = Keyframe(3.456, 23, 325764);
  Keyframe keyframe_2 = Keyframe(9.4537, 23456, 32554735);
  Keyframe keyframe_3 = Keyframe(435.3253, 234253, 57546345);

  ReplayKeyframesTests() {
    keyframes.add(keyframe_0);
    keyframes.add(keyframe_1);
  }

  ~ReplayKeyframesTests() override = default;
};

TEST_F(ReplayKeyframesTests, ReplayKeyframesGetTest) {  
  EXPECT_EQ(keyframes.get(0), keyframe_0);
  EXPECT_EQ(keyframes.get(1), keyframe_1);
}

TEST_F(ReplayKeyframesTests, ReplayKeyframesAddTest) {
  EXPECT_ANY_THROW(keyframes.get(2));
  keyframes.add(keyframe_2);
  EXPECT_EQ(keyframes.get(0), keyframe_0);
  EXPECT_EQ(keyframes.get(1), keyframe_1);
  EXPECT_EQ(keyframes.get(2), keyframe_2);

  EXPECT_ANY_THROW(keyframes.get(3));
  keyframes.add(keyframe_3);
  EXPECT_EQ(keyframes.get(0), keyframe_0);
  EXPECT_EQ(keyframes.get(1), keyframe_1);
  EXPECT_EQ(keyframes.get(2), keyframe_2);
  EXPECT_EQ(keyframes.get(3), keyframe_3);
}

TEST_F(ReplayKeyframesTests, ReplayKeyframesRemoveByIndexTest) {  
  EXPECT_TRUE(keyframes.remove(keyframes.get(1)));
  EXPECT_EQ(keyframes.get(0), keyframe_0);
  EXPECT_ANY_THROW(keyframes.get(1));

  EXPECT_TRUE(keyframes.remove(keyframes.get(0)));
  EXPECT_ANY_THROW(keyframes.get(0));
}

TEST_F(ReplayKeyframesTests, ReplayKeyframesRemoveByValueTest) {  
  EXPECT_TRUE(keyframes.remove(keyframe_1));
  EXPECT_EQ(keyframes.get(0), keyframe_0);
  EXPECT_ANY_THROW(keyframes.get(1));

  EXPECT_TRUE(keyframes.remove(keyframe_0));
  EXPECT_ANY_THROW(keyframes.get(0));
}
