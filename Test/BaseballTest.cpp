#include "pch.h"
#include "../Baseball/Baseball.cpp"

TEST(BaseballTest, InvaidLengthOfParameter) {
	Baseball game{"123"};
	EXPECT_THROW(game.guess("12"), length_error);
	EXPECT_THROW(game.guess("1212"), length_error);
}

TEST(BaseballTest, InvaidArgumentOfParameter) {
	Baseball game{ "123" };
	EXPECT_THROW(game.guess("12s"), invalid_argument);
	EXPECT_THROW(game.guess("aaa"), invalid_argument);
}
