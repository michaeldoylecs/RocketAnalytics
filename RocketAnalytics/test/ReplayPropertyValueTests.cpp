// Author: Michael Doyle
// Date: 7/18/17
// ReplayPropertyValueTests.hpp

#include "gtest/gtest.h"
#include "../include/ReplayPropertyValue.hpp"

using namespace ReplayProperty;

class ReplayPropertyValueTest: public ::testing::Test {

	public:
		Value* value;

		// Constructor
		ReplayPropertyValueTest() {
			value = new Value;
		}

		// Called prior to TEST completion
		void SetUp() {

		}

		// Called after TEST completes
		void TearDown() {

		}

		// Destructor
		virtual ~ReplayPropertyValueTest() {
			delete value;
		}
};

TEST_F (ReplayPropertyValueTest, CanSetInt) {
	value->set_int(5);
	EXPECT_EQ ("5", value->to_string());
}