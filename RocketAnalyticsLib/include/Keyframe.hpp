/******************************************************************************
*	Author:	Michael Doyle
*	Date:	2/19/18
*	File:	Keyframe.hpp
*	Description:
*		Represents a Keyframe.
******************************************************************************/

#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <cstdint>

using std::uint32_t;

namespace ReplayParser {

	class Keyframe {
	public:
		Keyframe(float time, uint32_t frame, uint32_t filePosition);

		float time();
		uint32_t frame();
		uint32_t filePosition();

		bool operator==(const Keyframe& keyframe);

	private:
		float timeStamp;
		uint32_t frameNum;
		uint32_t filePos;
	};

}

#endif
