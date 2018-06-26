/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/10/17
 *  File: ReplayHeader.hpp
 *  Description:
 *    ReplayHeader contains the basic information of a Rocket League
 *  replay file. 
 *****************************************************************************/

#ifndef REPLAYHEADER_HPP
#define REPLAYHEADER_HPP

#include "BinaryReader.hpp"
#include "Version.hpp"
#include "properties/Property.hpp"
#include <cstdint>
#include <string>
#include <vector>

namespace ReplayParser {

  class ReplayHeader {
  public:
    ReplayHeader() = default;
    static ReplayHeader deserialize_header(BinaryReader& binary_reader);
    ReplayHeader(const ReplayHeader& other) = default;
    ReplayHeader(ReplayHeader&& other) = default;
    ReplayHeader& operator=(const ReplayHeader& other) = default;
    ReplayHeader& operator=(ReplayHeader&& other) = default;

    ~ReplayHeader() = default;

    uint32_t get_header_size();
    uint32_t get_crc1();
    std::string get_version();
    uint32_t get_version_major();
    uint32_t get_version_minor();
    std::string get_replay_identifier();
    std::vector<Property> get_properties();
    uint32_t get_body_size();
    uint32_t get_crc2();

  private:
    uint32_t header_size{0};
    uint32_t crc1{0};
    Version version;
    std::string replay_identifier;
    std::vector<Property> replay_properties;
    uint32_t body_size{0};
    uint32_t crc2{0};

    void parse_header_size(BinaryReader& binary_reader);
    void parse_crc1(BinaryReader& binary_reader);
    void parse_version(BinaryReader& binary_reader);
    void check_for_empty_bits(BinaryReader& binary_reader);
    void parse_replay_identifier(BinaryReader& binary_reader);
    void parse_properties(BinaryReader& binary_reader,
      std::vector<Property>& properties);
    Property parse_property(BinaryReader& binary_reader);
    void parse_body_size(BinaryReader& binary_reader);
    void parse_crc2(BinaryReader& binary_reader);

  };

} // namespace ReplayParser

#endif
