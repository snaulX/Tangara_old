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

DefaultVar::DefaultVar()
{
}

DefaultVar::~DefaultVar()
{
}

class StaticVariable
{
public:
	StaticVariable();
	~StaticVariable();

private:

};

StaticVariable::StaticVariable()
{
}

StaticVariable::~StaticVariable()
{
}