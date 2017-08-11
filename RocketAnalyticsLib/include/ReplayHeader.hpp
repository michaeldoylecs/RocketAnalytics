// Author: Michael Doyle
// Date: 8/10/17
// ReplayHeader.hpp

#ifndef REPLAY_HEADER_H
#define REPLAY_HEADER_H

#include "Version.hpp"
#include <cstdint>
#include <string>

namespace ReplayParser {
	
	class ReplayHeader {
		public:


		private:
			std::uint32_t header_size;
			std::uint32_t crc1;
			Version version;
			std::string replay_identifier;
			// TODO: Property list
			std::uint32_t body_size;
			std::uint32_t crc2;
	};

}

#endif