/******************************************************************************
 *  Author: Michael Doyle
 *  Date: 8/12/17
 *  File: ByteValue.hpp
 *  Description:
 *    ByteValue represents the 'ByteValue' property type found in Rocket
 *  League replay files. The name does not have any connection to it's size or
 *  inner workings.
 *****************************************************************************/

#ifndef BYTE_VALUE_H
#define BYTE_VALUE_H

#include <string>

namespace rocketanalytics {

  class ByteValue {
    public:
      ByteValue() = default;
      ByteValue(const std::string& id, const std::string& value);
      std::string id();
      std::string value();

    private:
      std::string byte_id;
      std::string byte_value;
  };
  
} // namespace rocketanalytics

#endif
