#include "pch.h"
#include "../Baseball/Baseball.cpp"

class BaseballTest : public testing::Test
{
protected:
	Baseball game{"123"};
	void assertIllegalArgument(string guessing)
	{
		try
		{
			game.guess(guessing);
			FAIL();
		}
		catch (exception e)
		{
			// PASS
		}
	}
};

TEST_F(BaseballTest, InvaidArgumentOfParameter) {
	assertIllegalArgument("12");
	assertIllegalArgument("1212");
	assertIllegalArgument("12s");
	assertIllegalArgument("aaa");
	assertIllegalArgument("121");
}


TEST_F(BaseballTest, Solved) {
	auto result = game.guess("123");

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballTest, OneStrikeTwoBall) {
	auto result = game.guess("145");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballTest, TwoStrikeOneBall) {
	auto result = game.guess("125");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(1, result.balls);
}