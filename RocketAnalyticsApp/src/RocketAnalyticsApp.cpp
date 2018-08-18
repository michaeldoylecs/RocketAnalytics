// RocketAnalyticsApp.cpp : Defines the entry point for the console application.

#include "../../RocketAnalyticsLib/include/BinaryReader.hpp"
#include "../../RocketAnalyticsLib/include/RocketAnalytics.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace rocketanalytics; // NOLINT

void test_binary_reader(const std::string& file_path) {
  try {
    std::cout << "---BEGING TESTING BinaryReader---" << std::endl;
    std::cout << "Filepath: " << file_path << std::endl;
    BinaryReader b_reader(file_path);
    std::cout << "Headersize: " << b_reader.read_aligned_uint32() << std::endl;
    std::cout << "CRC: " << b_reader.read_aligned_uint32() << std::endl;
    std::cout << "Version: " << b_reader.read_aligned_uint32() << "." <<
      b_reader.read_aligned_uint32() << std::endl;
    std::cout << "ReplayIdentifier: " <<
      b_reader.read_length_prefixed_string() << std::endl;
    std::cout << "---END TESTING BinaryReader---" << "\n" << std::endl;
  } catch (const std::runtime_error &e) {
    e.what();
  }
}

void test_replay(const std::string& file_path) {
  try {
    std::cout << "---BEGIN TESTING ReplayFile---" << std::endl;
    std::cout << "Filepath: " << file_path << std::endl;
    ReplayFile replay = ReplayFile(file_path);

    std::cout << "Header size: " <<
      replay.header().size() << std::endl;
    std::cout << "CRC1: " << replay.header().crc1() << std::endl;
    std::cout << "Version: " << replay.header().version() << std::endl;
    std::cout << "Version major: " <<
      replay.header().version_major() << std::endl;
    std::cout << "Version minor: " <<
      replay.header().version_minor() << std::endl;
    std::cout << "Replay Identifier: " <<
      replay.header().replay_id() << std::endl;

    std::cout << "Properties:" << std::endl;
    for (size_t i = 0; i < replay.header().properties().size(); i++) {
      std::cout << " > " <<
        replay.header().properties().at(i).to_string() << std::endl;
    }

    std::cout << "Body Size: " << replay.header().body_size() << std::endl;
    std::cout << "CRC2: " << replay.header().crc2() << std::endl;

    std::cout << "Replay Levels:" << std::endl;
    for (size_t i = 0; i < replay.levels().size(); i++) {
      std::cout << "> " << replay.levels().at(i) << std::endl;
    }

    std::cout << "Replay Keyframes:" << std::endl;
    for (size_t i = 0; i < replay.keyframes().size(); i++) {
      std::cout << i << ")\n\t" << std::fixed << std::setprecision(4) <<
        "> " << replay.keyframes().at(i).time() << "\n\t" <<
        "> " << replay.keyframes().at(i).frame() << "\n\t" <<
        "> " << replay.keyframes().at(i).filePos() << std::endl;
    }

    std::cout << "Replay Netstream: " << "NOT IMPLEMENTED" << std::endl;

    std::cout << "Replay Tick Information" << std::endl;
    for (size_t i = 0; i < replay.tick_information().size(); ++i) {
      std::cout << i << ")\n\t"
        << "> " << replay.tick_information().at(i).type() << "\n\t"
        << "> " << replay.tick_information().at(i).frame() << std::endl;
    }

    std::cout << "Replicated Packages" << std::endl;
    for (size_t i = 0; i < replay.replicated_packages().size(); ++i) {
      std::cout << i << ")\t"
        << replay.replicated_packages().at(i) << std::endl;
    }

    std::cout << "Object Table" << std::endl;
    for (size_t i = 0; i < replay.object_table().size(); ++i) {
      std::cout << i << ")\t"
        << replay.object_table().at(i) << std::endl;
    }

    std::cout << "Name Table" << std::endl;
    for (size_t i = 0; i < replay.name_table().size(); ++i) {
      std::cout << i << ")\t"
        << replay.name_table().at(i) << std::endl;
    }

    std::cout << "Class Index Map" << std::endl;
    for (size_t i = 0; i < replay.class_index_map().size(); ++i) {
      std::cout << i << ")\n\t"
        << "> " << replay.class_index_map().at(i).first << "\n\t"
        << "> " << replay.class_index_map().at(i).second << std::endl;
    }

    std::cout << "Class Net Cache" << std::endl;
    for (size_t i = 0; i < replay.class_net_cache().size(); ++i) {
      std::cout << i << ")\n\t"
        << "> " << replay.class_net_cache().at(i).index() << "\n\t"
        << "> " << replay.class_net_cache().at(i).parent() << "\n\t"
        << "> " << replay.class_net_cache().at(i).id() << "\n\t"
        << "> " << replay.class_net_cache().at(i).prop_length() << std::endl;
      for (size_t p_i = 0; p_i < replay.class_net_cache().at(i).prop_length(); ++p_i) {
        if (p_i == 0) {std::cout << "\tproperties:\n";}
        std::cout << "\t" << p_i << ")\t("
          << replay.class_net_cache().at(i).properties().at(p_i).first << ", "
          << replay.class_net_cache().at(i).properties().at(p_i).second << ")" << std::endl;
      }
    }

    std::cout << "---END TESTING ReplayFile---" << "\n" << std::endl;
  } catch (const std::runtime_error &e) {
    e.what();
  }
}

void test_replay_to_json(const std::string& file_path) {
  try {
    std::cout << "---BEGIN TESTING ReplayFile---" << std::endl;
    
    std::cout << "Filepath: " << file_path << std::endl;
    ReplayFile replay = ReplayFile(file_path);
    std::cout << "Serialize to JSON:" << std::endl;
    std::cout << replay.serialize_to_json() << std::endl;
    
    std::cout << "---END TESTING ReplayFile---" << "\n" << std::endl;
  } catch (const std::runtime_error &e) {
    e.what();
  }
}

int main() {
  try {
    std::string file_path = "../Testing/0A797CAB49E97F824000D9BB757BF7F9.replay";
    test_replay_to_json(file_path);
  }
  catch (const std::runtime_error &e) {
    e.what();
  }
  return 0;
}
