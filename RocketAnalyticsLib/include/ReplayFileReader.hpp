/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 7/23/17
 *  File: ReplayFileReader.hpp
 *  Description:
 *    ReplayFileReader handles the logic in reading Rocket League replay
 *  files.
 *****************************************************************************/

#ifndef REPLAYFILEREADER_HPP
#define REPLAYFILEREADER_HPP

#include <cstdint>
#include <fstream>
#include <string>

namespace ReplayParser {

  class ReplayFile;

  class ReplayFileReader {
    public:
      ReplayFileReader() = default;
      explicit ReplayFileReader(std::string& filepath);
      ~ReplayFileReader();

      int8_t read_int8();
      int32_t read_int32();
      int64_t read_int64();
      float read_float();
      bool read_bool();
      std::string read_string(int length);

    private:
      std::ifstream replay_file_stream;
      std::string replay_file_path;
  };

} // namespace ReplayParser

#endif
