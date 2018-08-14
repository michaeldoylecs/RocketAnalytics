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

    uint32_t size() const;
    uint32_t crc1() const;
    std::string version() const;
    uint32_t version_major() const;
    uint32_t version_minor() const;
    std::string replay_id() const;
    std::vector<Property> properties() const;
    uint32_t body_size() const;
    uint32_t crc2() const;

  private:
    uint32_t h_size{0};
    uint32_t h_crc1{0};
    Version h_version;
    std::string h_replay_id;
    std::vector<Property> h_properties;
    uint32_t h_body_size{0};
    uint32_t h_crc2{0};

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
