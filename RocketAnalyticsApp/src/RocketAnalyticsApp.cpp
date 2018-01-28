// RocketAnalyticsApp.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include "BinaryReader.hpp"
#include "ReplayHeader.hpp"

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
		cout << "Version: " << b_reader.read_aligned_uint32() << "."
			<< b_reader.read_aligned_uint32() << endl;
		cout << "ReplayIdentifier: " << b_reader.read_length_prefixed_string() << endl;
		cout << "---END TESTING BinaryReader---" << "\n" << endl;
	}
	catch (const std::runtime_error &e) {
		e.what();
	}
}

void test_replay_header(const string file_path) {
	try {
		cout << "---BEGIN TESTING ReplayHeader---" << endl;
		cout << "Filepath: " << file_path << endl;
		BinaryReader b_reader(file_path);
		ReplayHeader* replay_header = ReplayHeader::deserialize_header(b_reader);

		cout << "Header size: " << replay_header->get_header_size() << endl;
		cout << "CRC1: " << replay_header->get_crc1() << endl;
		cout << "Version: " << replay_header->get_version_string() << endl;
		cout << "Version major: " << replay_header->get_version_major() << endl;
		cout << "Version minor: " << replay_header->get_version_minor() << endl;
		cout << "Replay Identifier: " << replay_header->get_replay_identifier() << endl;

		cout << "Properties:" << endl;
		for (int i = 0; i < replay_header->get_properties().size(); i++) {
			cout << " > " << replay_header->get_properties().at(i).to_string() << endl;
		}

		cout << "Body Size: " << replay_header->get_body_size() << endl;
		cout << "CRC2: " << replay_header->get_crc2() << endl;
		cout << "---END TESTING ReplayHeader---" << "\n" << endl;
	}
	catch (const std::runtime_error &e) {
		e.what();
	}
}

int main() {
	try {
		const string file_path = "../Testing/0A797CAB49E97F824000D9BB757BF7F9.replay";
		test_binary_reader(file_path);
		test_replay_header(file_path);
	}
	catch (const std::runtime_error &e) {
		e.what();
	}
	std::cin.get();
	return 0;
}
