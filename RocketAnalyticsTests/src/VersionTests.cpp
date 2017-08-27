// Author: Michael Doyle
// Date: 8/10/17
// VersionTests.cpp

#include "Version.hpp"
#include "gtest/gtest.h"

using namespace ReplayParser;

struct VersionTestParam {
	std::uint32_t version_major;
	std::uint32_t version_minor;

	VersionTestParam(std::uint32_t major, std::uint32_t minor) {
		version_major = major;
		version_minor = minor;
	}
};


struct VersionTests :testing::TestWithParam<VersionTestParam> {
	Version* version;

	VersionTests() {
		version = new Version(GetParam().version_major, GetParam().version_minor);
	}

	~VersionTests() {
		delete version;
	}
};


TEST_P(VersionTests, GetMajorValue) {
	EXPECT_EQ(version->get_major_value(), GetParam().version_major);
}


TEST_P(VersionTests, GetMinorValue) {
	EXPECT_EQ(version->get_minor_value(), GetParam().version_minor);
}


TEST_P(VersionTests, ToString) {
	std::string correct_version_string = GetParam().version_major + "." + GetParam().version_minor;
	EXPECT_EQ(version->to_string(), correct_version_string);
}


INSTANTIATE_TEST_CASE_P(VersionTests, VersionTests, ::testing::Values(
	VersionTestParam(0, 0),
	VersionTestParam(45, 4),
	VersionTestParam(867, 13)
));
