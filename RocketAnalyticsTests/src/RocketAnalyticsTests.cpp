// Author: Michael Doyle
// Date: 7/25/17
// TestsMain.cpp

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
