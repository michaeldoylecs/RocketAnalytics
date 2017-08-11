// Author: Michael Doyle
// Date: 8/10/17
// VersionTests.cpp

#include "Version.hpp"
#include "gtest/gtest.h"
#include <cstdint>

using namespace ReplayParser;

TEST (VersionTests, VersionSetAndGet) {
	Version *version;
	int amount_of_tests = 3;
	std::uint32_t major_value[3] = { 0, 45, 867 };
	std::uint32_t minor_value[3] = { 0, 4, 13 };

	for (int index = 0; index < amount_of_tests; index++) {
		version = new Version(major_value[index], minor_value[index]);
		EXPECT_EQ(version->major, major_value[index]);
		EXPECT_EQ(version->minor, minor_value[index]);
		delete version;
	}
}


TEST(VersionTests, VersionToString) {
	Version *version;
	int amount_of_tests = 3;
	std::uint32_t major_value[3] = { 0, 45, 867 };
	std::uint32_t minor_value[3] = { 0, 4, 13 };

	for (int index = 0; index < amount_of_tests; index++) {
		version = new Version(major_value[index], minor_value[index]);
		std::string correct_version_string = major_value[index] + "." + minor_value[index];
		EXPECT_EQ(version->version(), correct_version_string);
		delete version;
	}
}