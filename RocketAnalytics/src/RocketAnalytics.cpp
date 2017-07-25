// Author: Michael Doyle
// Date: 6/10/17
// RocketAnalytics.cpp


#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "../include/ReplayPropertyTypes.hpp"
#include "../include/Replay.hpp"


int main() {


	std::cout << "~~~ Attempting to convert all Type Enums to String ~~~\n";
	for (int i = ReplayProperty::Type::None; i < ReplayProperty::Type::ArrayProperty; i++) {
		std::cout << ReplayProperty::type_to_string(static_cast<ReplayProperty::Type>(i)) << '\n';
	}
	std::cout << "~~~ Finished converting all Type Enums to String ~~~\n" << std::endl;


	Replay replay_file("Testing/0A797CAB49E97F824000D9BB757BF7F9.replay");
	replay_file.parse();

	std::cout << replay_file.to_string() << std::endl;
	std::cout << "Replay Count: " << Replay::replay_count() << std::endl;

	_getch();

	return 0;
}