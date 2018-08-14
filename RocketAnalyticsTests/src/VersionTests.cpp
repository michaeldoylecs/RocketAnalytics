// Author: Michael Doyle
// Date: 8/10/17
// VersionTests.cpp

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../RocketAnalyticsLib/include/Version.hpp"

using ReplayParser::Version;
using std::string;
using std::to_string;
using std::uint32_t;

struct VersionTestParam {
  uint32_t version_major;
  uint32_t version_minor;

  VersionTestParam(uint32_t major, uint32_t minor) {
    version_major = major;
    version_minor = minor;
  }
};

struct VersionTests :testing::TestWithParam<VersionTestParam> {
  Version* version;

  VersionTests() {
    version = new Version(GetParam().version_major, GetParam().version_minor);
  }

  ~VersionTests() override {
    delete version;
  }
};

TEST_P(VersionTests, GetMajorValue) {
  EXPECT_EQ(version->major_value(), GetParam().version_major);
}

TEST_P(VersionTests, GetMinorValue) {
  EXPECT_EQ(version->minor_value(), GetParam().version_minor);
}

TEST_P(VersionTests, ToString) {
  std::string correct_version_string = to_string(GetParam().version_major) +
                  "." + to_string(GetParam().version_minor);
  EXPECT_EQ(version->to_string(), correct_version_string);
}

INSTANTIATE_TEST_CASE_P(VersionTests, VersionTests, ::testing::Values(
  VersionTestParam(0, 0),
  VersionTestParam(45, 4),
  VersionTestParam(867, 13)
));
