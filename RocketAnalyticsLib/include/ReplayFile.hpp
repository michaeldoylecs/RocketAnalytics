// Author: Michael Doyle
// Date: 7/23/17
// ReplayFileReader.hpp

#ifndef REPLAY_FILE_H
#define REPLAY_FILE_H

#include <ReplayHeader.hpp>
#include <cstdint>
#include <string>
#include <fstream>

namespace ReplayParser {

	class ReplayFile {
		public:
			ReplayFile(std::string filepath);
			~ReplayFile();

		private:
			std::string replay_file_path;

			ReplayHeader replay_header;
			void read_header_values();
	};

}
#endif
