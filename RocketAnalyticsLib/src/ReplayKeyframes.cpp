/******************************************************************************
*	Author:	Michael Doyle
*	Date:	3/31/18
*	File:	ReplayKeyframes.cpp
******************************************************************************/

#include "Keyframe.hpp"
#include "ReplayKeyframes.hpp"

namespace ReplayParser {

	ReplayKeyframes ReplayKeyframes::deserialize_keyframes(BinaryReader& binary_reader) {
		ReplayKeyframes keyframes;
		float time;
		uint32_t frame;
		uint32_t filePos;
		uint32_t keyframe_count = binary_reader.read_aligned_uint32();
		for (int i = 0; i < keyframe_count; i++) {
			time = binary_reader.read_aligned_float();
			frame = binary_reader.read_aligned_uint32();
			filePos = binary_reader.read_aligned_uint32();
			keyframes.add(Keyframe(time, frame, filePos));
		}
		return keyframes;
	}

	void ReplayKeyframes::add(Keyframe keyframe) {
		keyframes.push_back(keyframe);
	}

	bool ReplayKeyframes::remove(Keyframe keyframe) {
		int size = this->keyframes.size();
		int indexToRemove = NULL;

		// Check if the keyframe is in the list of keyframes
		for (int i = 0; i < size; ++i) {
			if (this->keyframes[i] == keyframe) {
				indexToRemove = i;
				break;
			}
		}

		// If the keyframe was found, remove it.
		if (indexToRemove != NULL) {
			this->keyframes.erase(keyframes.begin() + indexToRemove);
			return true;
		}

		return false;
	}

	Keyframe ReplayKeyframes::get(int index) {
		return keyframes[index];
	}

	int ReplayKeyframes::count() {
		return keyframes.size();
	}
}
