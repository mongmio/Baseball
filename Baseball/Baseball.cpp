#include <string>
#include <stdexcept>

using namespace std;

class Baseball
{
public:
	Baseball(string _solution);
	~Baseball();
	bool guess(string guessing)
	{
		verifyArgument(guessing);
		return false;
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
		if ((guessing[0] == guessing[1]) ||
			(guessing[1] == guessing[2]) ||
			(guessing[2] == guessing[0]))
		{
			throw invalid_argument("must not have same number");
		}
	}
	bool hasSameNumber(bool  existence[10], char ch)
	{
		if (existence[(ch - '0')] == false)
		{
			existence[(ch - '0')] = true;
			return false;
		}
		return true;
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