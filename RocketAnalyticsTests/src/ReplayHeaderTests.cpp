// Author: Michael Doyle
// Date: 8/24/17
// ReplayHeaderTests.cpp

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../RocketAnalyticsLib/include/ReplayHeader.hpp"

using ReplayParser::ReplayHeader;
using ReplayParser::BinaryReader;

struct ReplayHeaderTest :testing::Test {
	ReplayHeader replay_header;
	const std::string FILE_PATH = "../Testing/0A797CAB49E97F824000D9BB757BF7F9.replay";
	const std::uint32_t EXPECTED_HEADER_SIZE = 6859;
	const std::uint32_t EXPECTED_CRC1 = 1488016315;
	const std::uint32_t EXPECTED_VERSION_MAJOR = 868;
	const std::uint32_t EXPECTED_VERSION_MINOR = 14;
	const std::string EXPECTED_REPLAY_IDENTIFIER = "TAGame.Replay_Soccar_TA";
	// const EXPECTED_REPLAY_PROPERTIES
	const std::uint32_t EXPECTED_BODY_SIZE = 647031;
	const std::uint32_t EXPECTED_CRC2 = 1405296084;

	ReplayHeaderTest() {
		BinaryReader binary_reader(FILE_PATH);
		replay_header = ReplayHeader::deserialize_header(binary_reader);
	}

	~ReplayHeaderTest() = default;
};

TEST_F(ReplayHeaderTest, DeserializeHeader) {
	EXPECT_EQ(replay_header.get_header_size(), EXPECTED_HEADER_SIZE);
	EXPECT_EQ(replay_header.get_crc1(), EXPECTED_CRC1);
	EXPECT_EQ(replay_header.get_version_major(), EXPECTED_VERSION_MAJOR);
	EXPECT_EQ(replay_header.get_version_minor(), EXPECTED_VERSION_MINOR);
	EXPECT_EQ(replay_header.get_replay_identifier(), EXPECTED_REPLAY_IDENTIFIER);
	// TODO: Replay Properties Tests
	EXPECT_EQ(replay_header.get_body_size(), EXPECTED_BODY_SIZE);
	EXPECT_EQ(replay_header.get_crc2(), EXPECTED_CRC2);
}

