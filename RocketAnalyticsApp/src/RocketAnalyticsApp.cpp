// RocketAnalyticsApp.cpp : Defines the entry point for the console application.

#include <iostream>
#include "BinaryReader.hpp"

using std::cout;
using std::endl;
using namespace ReplayParser;

int main() {
	cout << "---BEGING TESTING BinaryReader---" << endl;
	BinaryReader b_reader("../../Testing/TestReplay.replay");
	cout << "Headersize: " << b_reader.read_padded_uint32() << endl;
	cout << "CRC: " << b_reader.read_padded_uint32() << endl;
	cout << "Version: " << b_reader.read_padded_uint32() << "."
		<< b_reader.read_padded_uint32() << endl;
	cout << "ReplayIdentifier: " << b_reader.read_padded_string() << endl;
	cout << "---END TESTING BinaryReader---" << endl;
	std::cin.get();
	return 0;
}
