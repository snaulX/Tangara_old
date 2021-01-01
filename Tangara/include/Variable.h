#include <string>

using namespace std;

enum Security
{
	PUBLIC,
	PRIVATE,
	PROTECTED,
	INTERNAL
};

class Variable
{
public:
	Variable()
	{
	}

	~Variable()
	{
	}

	string name;
	string type;
	Security security;
private:

};


class DefaultVar : public Variable
{
public:
	DefaultVar();
	~DefaultVar();

private:

};

class StaticVariable
{
public:
	StaticVariable();
	~StaticVariable();

private:

};