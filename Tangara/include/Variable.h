#include <string>

using namespace std;

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