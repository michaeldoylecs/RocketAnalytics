// Author: Michael Doyle
// Date: 8/10/17
// Version.hpp

#ifndef VERSION_H
#define VERSION_H

#include <cstdint>
#include <string>

namespace ReplayParser {

	class Version {
		public:
			std::uint32_t major;
			std::uint32_t minor;

			Version(std::uint32_t major, std::uint32_t minor);
			~Version();
			std::string version();
	};

}

#endif