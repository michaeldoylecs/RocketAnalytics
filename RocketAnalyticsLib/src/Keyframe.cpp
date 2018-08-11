/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	3/31/18
 *	File:	Keyframe.cpp
 *****************************************************************************/

#include "../include/Keyframe.hpp"

using std::uint32_t;

namespace ReplayParser {

	Keyframe::Keyframe(float time, uint32_t frame, uint32_t filePosition) {
		this->timeStamp = time;
		this->frameNum = frame;
		this->filePos = filePosition;
	}

	float Keyframe::time() const {
		return this->timeStamp;
	}

	uint32_t Keyframe::frame() const {
		return this->frameNum;
	}

	uint32_t Keyframe::filePosition() const {
		return this->filePos;
	}

	bool Keyframe::operator==(const Keyframe &k1) const {
    return (this->timeStamp == k1.timeStamp &&
      this->frameNum == k1.frameNum &&
      this->filePos == k1.filePos);
	}
  
	bool Keyframe::operator!=(const Keyframe &k1) const {
    return (this->timeStamp != k1.timeStamp ||
      this->frameNum != k1.frameNum ||
      this->filePos != k1.filePos);
	}
} // namespace ReplayParser
