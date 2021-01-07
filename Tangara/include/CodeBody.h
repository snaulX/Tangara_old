#include "Commands.h"
#include <vector>

using namespace std;

class CodeBody
{
public:
	CodeBody()
	{
		hash = 0;
		commands = vector<Command>();
	}
	~CodeBody();
	
	void addCommand(Command c)
	{
		commands.push_back(c);
	}

	int hash;
private:
	vector<Command> commands;
};