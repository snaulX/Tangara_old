#include <vector>
#include <string>

using namespace std;

class Parser
{
public:
	Parser();
	Parser(string c);
	~Parser();

	void parse();

	string code;
	int index;

private:
	void skipws();
};
