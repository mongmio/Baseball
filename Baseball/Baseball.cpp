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
	GuessResult getResult(std::string& guessing);
private:
	void verifyArgument(std::string& guessing);

	bool hasSameNumber(std::string& guessing);

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
	for (auto ch : guessing)
	{
		if (solution_map[ch - '0'] == true)
		{
			result.strikes++;
		}
		else
		{
			result.balls++;
		}
	}
	if (result.strikes == 3)
	{
		result.solved = true;
	}
	return result;
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
