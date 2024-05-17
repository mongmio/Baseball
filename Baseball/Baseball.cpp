#include <string>
#include <stdexcept>

using namespace std;

class Baseball
{
public:
	Baseball(string _solution);
	~Baseball();
	bool guess(string str)
	{
		if (3 != str.size())
		{
			throw length_error("must be 3 letters");
		}
		return false;
	}
private:
	string solution;
};

Baseball::Baseball(string _solution) : solution(_solution)
{
}

Baseball::~Baseball()
{
}