// Author: Michael Doyle
// Date: 8/10/17
// ReplayHeader.hpp

#ifndef REPLAY_HEADER_H
#define REPLAY_HEADER_H

#include "Property.hpp"
#include "Version.hpp"
#include <cstdint>
#include <string>
#include <vector>

namespace ReplayParser {

	class ReplayHeader {
		public:
			static ReplayHeader deserialize_header();

		private:
			std::uint32_t header_size;
			std::uint32_t crc1;
			Version version;
			std::string replay_identifier;
			std::vector<Property> properties;
			std::uint32_t body_size;
			std::uint32_t crc2;
	};

}

#endif