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

	/*
	std::ofstream out("test.bin", std::ios_base::binary);
	int x(13);
	out.write(reinterpret_cast<char*>(&x), sizeof(int));

	std::ifstream in("test.bin", std::ios_base::binary);
	int x(0);

	in.read(reinterpret_cast<char*>(&x), sizeof(int));

	std::cout << x;

	std::string filepath = "Resources/0A797CAB49E97F824000D9BB757BF7F9.replay";
	std::ifstream binary_reader(filepath, std::ios::binary);
	binary_reader.seekg(0, std::ostream::beg);

	std::int32_t raw_int;
	//char raw_char;
	binary_reader.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
	//binary_reader.read(&raw_char, sizeof(raw_char));
	std::cout << "output: " << std::hex << std::setw(2)
		<< std::setfill('0') << raw_int << std::endl;
	//std::cout << "output: " << raw_int << std::endl;

	binary_reader.close();
	*/


	Replay replay_file("Testing/0A797CAB49E97F824000D9BB757BF7F9.replay");
	replay_file.parse();

	std::cout << replay_file.to_string() << std::endl;
	std::cout << "Replay Count: " << Replay::replay_count() << std::endl;

	_getch();

	return 0;
}
