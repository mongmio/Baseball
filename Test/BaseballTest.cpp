#include "pch.h"
#include "../Baseball/Baseball.cpp"

TEST(BaseballTast, InvaidLengthOfParameter) {
	Baseball game{"123"};
	EXPECT_THROW(game.guess("12"), length_error);
	EXPECT_THROW(game.guess("1212"), length_error);
}