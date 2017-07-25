// Author: Michael Doyle
// Date: 7/25/17
// TypeSizeTest.cpp

#include <cstdint>
#include <string>
#include <iostream>
#include "../include/TypeSizeTest.hpp"

namespace RocketAnalyticsTests {

	void print_data_types() {
		std::cout 
			<< "~~~~~{ Data Types }~~~~~\n"
			<< "Type: int8_t\t\t size: " << sizeof(std::int8_t) << "\n"
			<< "Type: int32_t\t\t size: " << sizeof(std::int32_t) << "\n"
			<< "Type: int64_t\t\t size: " << sizeof(std::int64_t) << "\n"
			<< "Type: float\t\t size: " << sizeof(float) << "\n"
			<< "Type: bool\t\t size: " << sizeof(bool) << "\n"
			<< "Type: string\t\t size: " << sizeof(std::string) << "\n"
			<< "~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}

}