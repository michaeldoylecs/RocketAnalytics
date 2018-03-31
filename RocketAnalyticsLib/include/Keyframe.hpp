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
		float time;
		uint32_t frame;
		uint32_t filePosition;
	};

}

#endif
