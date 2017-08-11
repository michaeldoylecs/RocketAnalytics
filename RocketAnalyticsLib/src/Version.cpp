// Author: Michael Doyle
// Date: 8/10/17
// Version.cpp

#include "Version.hpp"

namespace ReplayParser {

	Version::Version(std::uint32_t major, std::uint32_t minor) {
		this->major = major;
		this->minor = minor;
	}


	Version::~Version() {
	}


	std::string Version::version() {
		std::string return_string;
		return_string = major + "." + minor;
		return return_string;
	}
}