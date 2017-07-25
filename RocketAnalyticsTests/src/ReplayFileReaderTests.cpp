// Author: Michael Doyle
// Date: 7/25/17
// ReplayFileReaderTests.hpp

#include "gtest/gtest.h"
#include "../include/ReplayFileReader.hpp"

struct ReplayFileReaderTest : testing::Test {
	std::string replay_path = "D:\\Library\\Development\\Projects\\RocketAnalytics\\RocketAnalyticsTests\\Testing\\0A797CAB49E97F824000D9BB757BF7F9.replay";
	ReplayParser::ReplayFileReader* replay_reader;
	
	ReplayFileReaderTest() {
		replay_reader = new ReplayParser::ReplayFileReader(replay_path);
	}

	virtual void SetUp() {}

	virtual void TearDown() {}

	virtual ~ReplayFileReaderTest() {
		delete replay_reader;
	}
};

TEST_F(ReplayFileReaderTest, ReadFirst4Bytes) {
	std::int32_t test_int = replay_reader->read_int32();
	EXPECT_EQ(6859, test_int);
}