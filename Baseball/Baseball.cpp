#include <string>
#include <stdexcept>

using namespace std;
struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(string _solution);
	~Baseball();
	GuessResult guess(string guessing)
	{
		verifyArgument(guessing);
		GuessResult result{};
		if (solution == guessing)
		{
			result.solved = true;
			result.strikes = 3;
			result.balls = 0;
		}
		return result;
	}
private:
	void verifyArgument(std::string& guessing)
	{
		if (3 != guessing.size())
		{
			throw length_error("must be 3 letters");
		}
		for (auto ch : guessing)
		{
			if (isNumber(ch)) continue;
			throw invalid_argument("must be number");
		}
		if (hasSameNumber(guessing))
		{
			throw invalid_argument("must not have same number");
		}
	}

	bool hasSameNumber(std::string& guessing)
	{
		return (guessing[0] == guessing[1]) ||
			(guessing[1] == guessing[2]) ||
			(guessing[2] == guessing[0]);
	}

	bool isNumber(char ch)
	{
		return '0' <= ch && '9' >= ch;
	}
	string solution;
	
};

Baseball::Baseball(string _solution) : solution(_solution)
{
}

Baseball::~Baseball()
{
}