/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	2/19/18
 *	File:	Keyframe.hpp
 *	Description:
 *		Represents a Keyframe.
 *****************************************************************************/

#ifndef KEYFRAME_HPP
#define KEYFRAME_HPP

#include <cstdint>

namespace ReplayParser {

	class Keyframe {
	public:
		Keyframe(float time, std::uint32_t frame, std::uint32_t filePosition);

		float time();
		std::uint32_t frame();
		std::uint32_t filePosition();

		bool operator==(const Keyframe &k1) const;
		bool operator!=(const Keyframe &k1) const;

	private:
		float timeStamp;
		std::uint32_t frameNum;
		std::uint32_t filePos;
	};

} // namespace ReplayParser

#endif
