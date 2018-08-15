/******************************************************************************
 * Author: Michael Doyle
 * Date: 6/16/18
 * File: Netstream.cpp
 * Description:
 *   Represents the Netstream data of a Rocket League replay file.
 *****************************************************************************/

#include "../include/Netstream.hpp"
#include "../include/BinaryReader.hpp"

namespace rocketanalytics {

  Netstream Netstream::deserialize_netstream(BinaryReader& br) {
    Netstream netstream;
    netstream.length = br.read_aligned_uint32();
    netstream.data = br.read_bytes(netstream.length);
    return netstream;
  }

} // namespace rocketanalytics
