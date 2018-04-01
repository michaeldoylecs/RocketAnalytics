/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	3/31/18
 *	File:	Keyframe.cpp
 *****************************************************************************/

#include "Keyframe.hpp"

using std::uint32_t;

namespace ReplayParser {

	Keyframe::Keyframe(float time, uint32_t frame, uint32_t filePosition) {
		this->timeStamp = time;
		this->frameNum = frame;
		this->filePos = filePosition;
	}

	float Keyframe::time() {
		return this->timeStamp;
	}

	uint32_t Keyframe::frame() {
		return this->frameNum;
	}

	uint32_t Keyframe::filePosition() {
		return this->filePos;
	}

	bool Keyframe::operator==(const Keyframe &k2) const {
		if (this->timeStamp == k2.timeStamp &&
			this->frameNum == k2.frameNum &&
			this->filePos == k2.filePos) {
			return true;
		}
		return false;
	}
}
