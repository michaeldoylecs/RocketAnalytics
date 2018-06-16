// Author: Michael Doyle
// Date: 8/24/17
// ReplayHeaderTests.cpp

#include "../../build/googletest-src/googletest/include/gtest/gtest.h"
#include "../../RocketAnalyticsLib/include/ReplayHeader.hpp"

using ReplayParser::ReplayHeader;
using ReplayParser::BinaryReader;
using ReplayParser::Property;

Property init_property_0() {
  Property prop;
  prop.set_int("TeamSize", 1);
  return prop;
}

Property init_property_5() {
  std::vector<std::vector<Property>> properties;
  properties.resize(2);
  Property prop;
  
  prop.set_string("Name", "literally the worst");
  properties.at(0).push_back(prop);
  prop.set_byte("Platform", "OnlinePlatform", "OnlinePlatform_Steam");
  properties.at(0).push_back(prop);
  prop.set_qword("OnlineID", 76561198351926391);
  properties.at(0).push_back(prop);
  prop.set_int("Team", 0);
  properties.at(0).push_back(prop);
  prop.set_int("Score", 1325);
  properties.at(0).push_back(prop);
  prop.set_int("Goals", 14);
  properties.at(0).push_back(prop);
  prop.set_int("Assists", 0);
  properties.at(0).push_back(prop);
  prop.set_int("Saves", 2);
  properties.at(0).push_back(prop);
  prop.set_int("Shots", 17);
  properties.at(0).push_back(prop);
  prop.set_bool("bBot", 0);
  properties.at(0).push_back(prop);
  prop.set_none();
  properties.at(0).push_back(prop);

  prop.set_string("Name", "AfroSeiun");
  properties.at(1).push_back(prop);
  prop.set_byte("Platform", "OnlinePlatform", "OnlinePlatform_Steam");
  properties.at(1).push_back(prop);
  prop.set_qword("OnlineID", 76561198132249981);
  properties.at(1).push_back(prop);
  prop.set_int("Team", 1);
  properties.at(1).push_back(prop);
  prop.set_int("Score", 265);
  properties.at(1).push_back(prop);
  prop.set_int("Goals", 1);
  properties.at(1).push_back(prop);
  prop.set_int("Assists", 0);
  properties.at(1).push_back(prop);
  prop.set_int("Saves", 2);
  properties.at(1).push_back(prop);
  prop.set_int("Shots", 3);
  properties.at(1).push_back(prop);
  prop.set_bool("bBot", 0);
  properties.at(1).push_back(prop);
  prop.set_none();
  properties.at(1).push_back(prop); 

  Property array_prop;
  array_prop.set_array("PlayerStats", properties);
  return array_prop;
}

Property init_property_6 () {
  Property prop;
  prop.set_string("ReplayName", "Thing happened to Afro");
  return prop;
}

Property init_property_12 () {
  Property prop;
  prop.set_float("RecordFPS", 30.0);
  return prop;
}

Property init_property_17 () {
  Property prop;
  prop.set_name("MapName", "trainstation_p");
  return prop;
}

struct ReplayHeaderTest :testing::Test {
	ReplayHeader replay_header;
	const std::string FILE_PATH = "../Testing/0A797CAB49E97F824000D9BB757BF7F9.replay";
	const std::uint32_t EXPECTED_HEADER_SIZE = 6859;
	const std::uint32_t EXPECTED_CRC1 = 1488016315;
	const std::uint32_t EXPECTED_VERSION_MAJOR = 868;
	const std::uint32_t EXPECTED_VERSION_MINOR = 14;
	const std::string EXPECTED_REPLAY_IDENTIFIER = "TAGame.Replay_Soccar_TA";
  Property EXPECTED_REPLAY_PROPERTY_0 = init_property_0();
  Property EXPECTED_REPLAY_PROPERTY_5 = init_property_5();
  Property EXPECTED_REPLAY_PROPERTY_6 = init_property_6();
  Property EXPECTED_REPLAY_PROPERTY_12 = init_property_12();
  Property EXPECTED_REPLAY_PROPERTY_17 = init_property_17();
  const std::uint32_t EXPECTED_BODY_SIZE = 647031;
	const std::uint32_t EXPECTED_CRC2 = 1405296084;

	ReplayHeaderTest() {
		BinaryReader binary_reader(FILE_PATH);
		replay_header = ReplayHeader::deserialize_header(binary_reader);
	}

	~ReplayHeaderTest() override = default;
};

TEST_F(ReplayHeaderTest, DeserializeHeader) {
	EXPECT_EQ(replay_header.get_header_size(), EXPECTED_HEADER_SIZE);
	EXPECT_EQ(replay_header.get_crc1(), EXPECTED_CRC1);
	EXPECT_EQ(replay_header.get_version_major(), EXPECTED_VERSION_MAJOR);
	EXPECT_EQ(replay_header.get_version_minor(), EXPECTED_VERSION_MINOR);
	EXPECT_EQ(replay_header.get_replay_identifier(), EXPECTED_REPLAY_IDENTIFIER);
	EXPECT_EQ(replay_header.get_properties().at(0), EXPECTED_REPLAY_PROPERTY_0);
	EXPECT_EQ(replay_header.get_properties().at(5), EXPECTED_REPLAY_PROPERTY_5);
	EXPECT_EQ(replay_header.get_properties().at(6), EXPECTED_REPLAY_PROPERTY_6);
	EXPECT_EQ(replay_header.get_properties().at(12), EXPECTED_REPLAY_PROPERTY_12);
	EXPECT_EQ(replay_header.get_properties().at(17), EXPECTED_REPLAY_PROPERTY_17);
  EXPECT_EQ(replay_header.get_body_size(), EXPECTED_BODY_SIZE);
	EXPECT_EQ(replay_header.get_crc2(), EXPECTED_CRC2);
}

