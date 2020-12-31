#include <vector>
#include "Class.h"

using namespace std;

class File
{
public:
	File();

	~File();

private:
	vector<Class> classes;
	vector<Function> functions;
	vector<Variable> variables;
	vector<CodeBody> bodies;
};
