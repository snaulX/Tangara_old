#include <vector>
#include <string>
#include <fstream>
#include "Class.h"

using namespace std;

static class Project
{
public:
	static vector<Class> classes;
	static vector<Function> functions;
	static vector<Variable> variables;
	static vector<CodeBody> bodies;
	static vector<string> usingNamespaces;
	static ofstream tokensStream;

	static void writeTokens(string path)
	{
		tokensStream.open(path);
	}
};
