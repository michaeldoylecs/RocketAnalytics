// Author: Michael Doyle
// Date: 7/25/17
// TestsMain.cpp

#include "../../GoogleTestTest/arithmetic.h"
#include "gtest/gtest.h"

TEST(SquareTests, Square) {
	EXPECT_EQ(0, square(0));
	EXPECT_EQ(4, square(-2));
}