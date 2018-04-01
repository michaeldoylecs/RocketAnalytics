/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	2/19/18
 *	File:	ReplayKeyframes.hpp
 *	Description:
 *		Represents a a Replay's Keyframes.
 *****************************************************************************/

#ifndef REPLAY_KEYFRAMES_H
#define REPLAY_KEYFRAMES_H

#include <cstdint>
#include <vector>
#include "BinaryReader.hpp"
#include "keyframe.hpp"

namespace ReplayParser {

	class Keyframe;

	class ReplayKeyframes {
	public:
		static ReplayKeyframes deserialize_keyframes(BinaryReader& binary_reader);

		void add(Keyframe);
		bool remove(Keyframe);
		Keyframe get(int index);
		size_t count();

	private:
		std::vector<Keyframe> keyframes;
	};

}

#endif
