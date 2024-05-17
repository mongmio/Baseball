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

