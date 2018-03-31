/******************************************************************************
*	Author:	Michael Doyle
*	Date:	3/31/18
*	File:	ReplayKeyframes.cpp
******************************************************************************/

#include "Keyframe.hpp"
#include "ReplayKeyframes.hpp"

namespace ReplayParser {

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
}
