#include <vector>
#include <string>
#include <map>
#include "Template.h"
#include "File.h"

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
	static File* currentFile;
private:
	void skipws();
	void package();
};
