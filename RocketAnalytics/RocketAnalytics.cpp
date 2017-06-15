// Author: Michael Doyle
// Date: 6/10/17
// RocketAnalytics.cpp


#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "Replay.hpp"


int main() {
	// THIS IS ALL TESTING INFORMATION
	Replay replay_file("Resources/0A797CAB49E97F824000D9BB757BF7F9.replay");

	std::ifstream replayReader(replay_file.filepath(), std::ios::binary);

	if (!replayReader) {
		std::cout << "Error opening replay" << std::endl;
	}
	else {
		replayReader.seekg(0, std::ostream::beg);

		replay_file.parse(replayReader);

		/*
		replayReader.read(buffer, sizeof(crc) / sizeof(crc[0]));

		int i;
		std::cout << "CRC: ";
		for (i = 0; i < size; i++) {
			std::cout << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)(unsigned char) buffer[i];
			std::cout << " ";
		}
		std::cout << std::endl;
		*/

		replayReader.close();
	}

	std::cout << replay_file.to_string() << std::endl;
	std::cout << "Replay Count: " << Replay::replay_count() << std::endl;

	_getch();

	return 0;
}
