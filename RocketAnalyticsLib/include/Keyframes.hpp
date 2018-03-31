/******************************************************************************
*	Author:	Michael Doyle
*	Date:	2/19/18
*	File:	Keyframes.hpp
*	Description:
*		Represents a Keyframe.
******************************************************************************/

#ifndef KEYFRAMES_H
#define KEYFRAMES_H

#include <cstdint>
#include <vector>

using std::uint32_t;
using std::vector;

namespace ReplayParser {

	class Keyframe;

	class Keyframes {
	public:
		Keyframes();
		~Keyframes();

		void add(Keyframe);
		void remove(Keyframe);
		Keyframe get(int index);
		uint32_t count();

	private:
		uint32_t keyframeCount;
		vector<Keyframe> keyframes;
	};

}

#endif
