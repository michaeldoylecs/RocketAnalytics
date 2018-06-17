/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/16/18
 * File: Netstream.hpp
 * Description;
 *   Represents the Netstream data of a Rocket League replay file.
 *****************************************************************************/

#ifndef NETSTREAM_HPP
#define NETSTREAM_HPP

#include <cstdint>
#include <vector>

namespace ReplayParser {
  
  class BinaryReader;
  class Byte;

  class Netstream {
    public:
      Netstream();
      static Netstream deserialize_netstream(BinaryReader& br);

    private:
      std::uint32_t length;
      std::vector<Byte> data;
  };

}

#endif
