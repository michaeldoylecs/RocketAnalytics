/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	3/31/18
 *	File:	ReplayKeyframes.cpp
 *****************************************************************************/

#include "../include/ReplayKeyframes.hpp"

namespace ReplayParser {

	ReplayKeyframes ReplayKeyframes::deserialize_keyframes(BinaryReader& binary_reader) {
		ReplayKeyframes keyframes;
		uint32_t keyframe_count = binary_reader.read_aligned_uint32();
		for (uint32_t i = 0; i < keyframe_count; ++i) {
			float time = binary_reader.read_aligned_float();
			uint32_t frame = binary_reader.read_aligned_uint32();
			uint32_t filePos = binary_reader.read_aligned_uint32();
			keyframes.add(Keyframe(time, frame, filePos));
		}
		return keyframes;
	}

	void ReplayKeyframes::add(Keyframe keyframe) {
		keyframes.push_back(keyframe);
	}

	bool ReplayKeyframes::remove(Keyframe keyframe) {
		size_t size = this->count();
		int indexToRemove = -1;

		// Check if the keyframe is in the list of keyframes
		for (uint32_t i = 0; i < size; ++i) {
			if (this->keyframes[i] == keyframe) {
				indexToRemove = i;
				break;
			}
		}

		// If the keyframe was found, remove it.
		if (indexToRemove != -1) {
			this->keyframes.erase(keyframes.begin() + indexToRemove);
			return true;
		}

		return false;
	}

	Keyframe ReplayKeyframes::get(int index) {
		return keyframes.at(index);
	}

	uint32_t ReplayKeyframes::count() {
		return keyframes.size();
	}
} // namespace ReplayParser
