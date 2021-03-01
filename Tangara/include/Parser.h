#include <vector>
#include <string>
#include <map>
#include <iostream> // for debug
#include "Project.h"

using namespace std;

#if CSHARP || CPP
#define USE_KEYWORD "using"
#define PACKAGE_KEYWORD "namespace"
#else
#define USE_KEYWORD "use"
#define PACKAGE_KEYWORD "package"
#endif
#define CLASS_KEYWORD "class"
#define FUNCTION_KEYWORD "fun"
#define VARIABLE_KEYWORD "var"
#define PUBLIC_KEYWORD "public"
#define PRIVATE_KEYWORD "private"
#define PROTECTED_KEYWORD "protected"
#define INTERNAL_KEYWORD "internal"

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
private:
	void skipws();
	void package();
	void use();
	void parseKeyword(string keyword);
	void isExprEnd();
	string getKeyword();
	char current();
	CodeBody* main;
};
