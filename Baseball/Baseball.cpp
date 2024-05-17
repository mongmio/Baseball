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
	void buildSolutionMap(string& solution);
	~Baseball();
	GuessResult guess(string guessing);
private:
	GuessResult getResult(string& guessing);
	bool isSolved(int strikes);
	int countStrike(string& guessing);
	int countBall(string& guessing);
	bool isStrike(char ch);
	void verifyArgument(string& guessing);
	bool hasSameNumber(string& guessing);
	bool isNumber(char ch);
	bool solution_map[10]{ false };
};

Baseball::Baseball(string _solution)
{
	buildSolutionMap(_solution);
}

void Baseball::buildSolutionMap(string& solution)
{
	for (auto ch : solution)
	{
		solution_map[ch - '0'] = true;
	}
}

Baseball::~Baseball()
{
}

GuessResult Baseball::guess(string guessing)
{
	verifyArgument(guessing);
	return getResult(guessing);
}

GuessResult Baseball::getResult(std::string& guessing)
{
	GuessResult result{};
	result.strikes = countStrike(guessing);
	result.balls = countBall(guessing);
	result.solved = isSolved(result.strikes);

	return result;
}

bool Baseball::isSolved(int strikes)
{
	return strikes == 3;
}

int Baseball::countStrike(string& guessing)
{
	int count = 0;
	for (auto ch : guessing)
	{
		if (isStrike(ch)) count++;
	}
	return count;
}

int Baseball::countBall(std::string& guessing)
{
	int count = 0;
	for (auto ch : guessing)
	{
		if (!isStrike(ch)) count++;
	}
	return count;
}


bool Baseball::isStrike(char ch)
{
	return solution_map[ch - '0'];
}

inline void Baseball::verifyArgument(std::string& guessing)
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

inline bool Baseball::hasSameNumber(std::string& guessing)
{
	return (guessing[0] == guessing[1]) ||
		(guessing[1] == guessing[2]) ||
		(guessing[2] == guessing[0]);
}

inline bool Baseball::isNumber(char ch)
{
	return '0' <= ch && '9' >= ch;
}
