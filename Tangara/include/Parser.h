#include <vector>
#include <string>
#include <map>
#include <iostream> // for debug
#include "Project.h"

using namespace std;

#define addstemplate(key, value) strongTemplates.insert(make_pair(string(key), &value))

class Parser
{
public:
	Parser();
	Parser(string c);
	~Parser();

	void parse();
	void error(string message);

	string code, packageName;
	int index;
	map<string, void(Parser::*)()> strongTemplates;
private:
	void skipws();
	void package();
	void parseKeyword(string keyword);
	void isExprEnd();
	string getKeyword();
};
