#include "pch.h"
#include "../Baseball/Baseball.cpp"

class BaseballTest : public testing::Test
{
protected:
	Baseball game{"123"};
};
TEST_F(BaseballTest, InvaidLengthOfParameter) {
	EXPECT_THROW(game.guess("12"), length_error);
	EXPECT_THROW(game.guess("1212"), length_error);
}

TEST_F(BaseballTest, InvaidArgumentOfParameter) {
	EXPECT_THROW(game.guess("12s"), invalid_argument);
	EXPECT_THROW(game.guess("aaa"), invalid_argument);
}
