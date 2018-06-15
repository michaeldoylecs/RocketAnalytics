// RocketAnalyticsApp.cpp : Defines the entry point for the console application.

#include "../../RocketAnalyticsLib/include/BinaryReader.hpp"
#include "../../RocketAnalyticsLib/include/ReplayFile.hpp"
#include "../../RocketAnalyticsLib/include/ReplayHeader.hpp"
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

void test_replay(const string file_path) {
	try {
		cout << "---BEGIN TESTING ReplayFile---" << endl;
		cout << "Filepath: " << file_path << endl;
		ReplayFile replay = ReplayFile(file_path);

		cout << "Header size: " <<
			replay.get_header().get_header_size() << endl;
		cout << "CRC1: " << replay.get_header().get_crc1() << endl;
		cout << "Version: " << replay.get_header().get_version() << endl;
		cout << "Version major: " <<
			replay.get_header().get_version_major() << endl;
		cout << "Version minor: " <<
			replay.get_header().get_version_minor() << endl;
		cout << "Replay Identifier: " <<
			replay.get_header().get_replay_identifier() << endl;

		cout << "Properties:" << endl;
		for (uint32_t i = 0; i < replay.get_header().get_properties().size(); i++) {
			cout << " > " <<
				replay.get_header().get_properties().at(i).to_string() << endl;
		}

		cout << "Body Size: " << replay.get_header().get_body_size() << endl;
		cout << "CRC2: " << replay.get_header().get_crc2() << endl;

		cout << "Replay Levels:" << endl;
		for (uint32_t i = 0; i < replay.get_levels().get_level_count(); i++) {
			cout << "> " << replay.get_levels().get_levels().at(i) << endl;
		}

		cout << "Replay Keyframes:" << endl;
		for (uint32_t i = 0; i < replay.get_keyframes().count(); i++) {
			cout << i << ")\n\t" << std::fixed << std::setprecision(4) <<
				"> " << replay.get_keyframes().get(i).time() << "\n\t" <<
				"> " << replay.get_keyframes().get(i).frame() << "\n\t" <<
				"> " << replay.get_keyframes().get(i).filePosition() << endl;
		}

		cout << "---END TESTING ReplayFile---" << "\n" << endl;
	} catch (const std::runtime_error &e) {
		e.what();
	}
}

int main() {
	try {
		const string file_path =
			"../Testing/0A797CAB49E97F824000D9BB757BF7F9.replay";
		test_binary_reader(file_path);
		test_replay(file_path);
	}
	catch (const std::runtime_error &e) {
		e.what();
	}
	std::cin.get();
	return 0;
}
