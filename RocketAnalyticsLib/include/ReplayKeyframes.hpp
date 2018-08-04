/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	2/19/18
 *	File:	ReplayKeyframes.hpp
 *	Description:
 *		Represents a a Replay's Keyframes.
 *****************************************************************************/

#ifndef REPLAYKEYFRAMES_HPP
#define REPLAYKEYFRAMES_HPP

#include "BinaryReader.hpp"
#include "Keyframe.hpp"
#include <cstdint>
#include <vector>

namespace ReplayParser {

	class Keyframe;

	class ReplayKeyframes {
	public:
    static ReplayKeyframes deserialize_keyframes(BinaryReader& binary_reader);

    void add(Keyframe keyframe);
    bool remove(Keyframe keyframe);
    Keyframe get(int index);
    uint32_t count();

	private:
    std::vector<Keyframe> keyframes;
	};

} // namespace ReplayParser

#endif
