/******************************************************************************
*	Author:	Michael Doyle
*	Date:	2/19/18
*	File:	ReplayKeyframes.hpp
*	Description:
*		Represents a a Replay's Keyframes.
******************************************************************************/

#ifndef REPLAY_KEYFRAMES_H
#define REPLAY_KEYFRAMES_H

#include <cstdint>
#include <vector>

using std::uint32_t;
using std::vector;

namespace ReplayParser {

	class Keyframe;

	class ReplayKeyframes {
	public:
		void add(Keyframe);
		bool remove(Keyframe);
		Keyframe get(int index);
		uint32_t count();

	private:
		vector<Keyframe> keyframes;
	};

}

#endif
