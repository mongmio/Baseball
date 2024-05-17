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
			if ('0' > ch || '9' < ch)
			{
				throw invalid_argument("must be number");
			}
		}
		bool existence[10]{ false };
		for (auto ch : guessing)
		{
			if (existence[(ch - '0')] == true)
			{
				throw invalid_argument("must not have same number");
			}
			existence[(ch - '0')] = true;
		}
	}
	string solution;
	
};

Baseball::Baseball(string _solution) : solution(_solution)
{
}

Baseball::~Baseball()
{
}