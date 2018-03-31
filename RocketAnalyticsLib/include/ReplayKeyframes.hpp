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
#include "BinaryReader.hpp"

using std::uint32_t;
using std::vector;

namespace ReplayParser {

	class Keyframe;

	class ReplayKeyframes {
	public:
		ReplayKeyframes deserialize_keyframes(BinaryReader& binary_reader);

		void add(Keyframe);
		bool remove(Keyframe);
		Keyframe get(int index);
		int count();

	private:
		vector<Keyframe> keyframes;
	};

}

#endif
