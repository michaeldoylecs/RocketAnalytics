// RocketAnalyticsApp.cpp : Defines the entry point for the console application.

#include "../../RocketAnalyticsLib/include/BinaryReader.hpp"
#include "../../RocketAnalyticsLib/include/ReplayFile.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using namespace ReplayParser;

void test_binary_reader(const string file_path) {
	try {
		cout << "---BEGING TESTING BinaryReader---" << endl;
		cout << "Filepath: " << file_path << endl;
		BinaryReader b_reader(file_path);
		cout << "Headersize: " << b_reader.read_aligned_uint32() << endl;
		cout << "CRC: " << b_reader.read_aligned_uint32() << endl;
		cout << "Version: " << b_reader.read_aligned_uint32() << "." <<
			b_reader.read_aligned_uint32() << endl;
		cout << "ReplayIdentifier: " <<
			b_reader.read_length_prefixed_string() << endl;
		cout << "---END TESTING BinaryReader---" << "\n" << endl;
	} catch (const std::runtime_error &e) {
		e.what();
	}
}

void test_replay(string& file_path) {
	try {
		cout << "---BEGIN TESTING ReplayFile---" << endl;
		cout << "Filepath: " << file_path << endl;
		ReplayFile replay = ReplayFile(file_path);

		cout << "Header size: " <<
			replay.header().get_header_size() << endl;
		cout << "CRC1: " << replay.header().get_crc1() << endl;
		cout << "Version: " << replay.header().get_version() << endl;
		cout << "Version major: " <<
			replay.header().get_version_major() << endl;
		cout << "Version minor: " <<
			replay.header().get_version_minor() << endl;
		cout << "Replay Identifier: " <<
			replay.header().get_replay_identifier() << endl;

		cout << "Properties:" << endl;
		for (size_t i = 0; i < replay.header().get_properties().size(); i++) {
			cout << " > " <<
				replay.header().get_properties().at(i).to_string() << endl;
		}

		cout << "Body Size: " << replay.header().get_body_size() << endl;
		cout << "CRC2: " << replay.header().get_crc2() << endl;

		cout << "Replay Levels:" << endl;
		for (size_t i = 0; i < replay.levels().get_level_count(); i++) {
			cout << "> " << replay.levels().get_levels().at(i) << endl;
		}

		cout << "Replay Keyframes:" << endl;
		for (size_t i = 0; i < replay.keyframes().count(); i++) {
			cout << i << ")\n\t" << std::fixed << std::setprecision(4) <<
				"> " << replay.keyframes().get(i).time() << "\n\t" <<
				"> " << replay.keyframes().get(i).frame() << "\n\t" <<
				"> " << replay.keyframes().get(i).filePosition() << endl;
		}

    cout << "Replay Netstream: " << "NOT IMPLEMENTED" << endl;

    cout << "Replay Tick Information" << endl;
    for (int i = 0; i < replay.tick_information().count(); ++i) {
      cout << i << ")\n\t"
        << "> " << replay.tick_information().get(i).type() << "\n\t"
        << "> " << replay.tick_information().get(i).frame() << endl;
    }

    cout << "Replicated Packages" << endl;
    for (int i = 0; i < replay.replicated_packages().count(); ++i) {
      cout << i << ")\t"
        << replay.replicated_packages().get(i) << endl;
    }

    cout << "Object Table" << endl;
    for (size_t i = 0; i < replay.object_table().size(); ++i) {
      cout << i << ")\t"
        << replay.object_table().at(i) << endl;
    }

    cout << "Name Table" << endl;
    for (size_t i = 0; i < replay.name_table().size(); ++i) {
      cout << i << ")\t"
        << replay.name_table().at(i) << endl;
    }

    cout << "Class Index Map" << endl;
    for (size_t i = 0; i < replay.class_index_map().size(); ++i) {
      cout << i << ")\n\t"
        << "> " << replay.class_index_map().at(i).first << "\n\t"
        << "> " << replay.class_index_map().at(i).second << endl;
    }

    cout << "Class Net Cache" << endl;
    for (size_t i = 0; i < replay.class_net_cache().size(); ++i) {
      cout << i << ")\n\t"
        << "> " << replay.class_net_cache().at(i).index() << "\n\t"
        << "> " << replay.class_net_cache().at(i).parent() << "\n\t"
        << "> " << replay.class_net_cache().at(i).id() << "\n\t"
        << "> " << replay.class_net_cache().at(i).prop_length() << endl;
    }

		cout << "---END TESTING ReplayFile---" << "\n" << endl;
	} catch (const std::runtime_error &e) {
		e.what();
	}
}

int main() {
	try {
		string file_path =
			"../Testing/0A797CAB49E97F824000D9BB757BF7F9.replay";
		//test_binary_reader(file_path);
		test_replay(file_path);
	}
	catch (const std::runtime_error &e) {
		e.what();
	}
	std::cin.get();
	return 0;
}
