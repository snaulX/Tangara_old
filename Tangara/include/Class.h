#include <string>
#include "Function.h"

using namespace std;

class Class
{
public:
	Class()
	{
	}

	~Class()
	{
	}

	string name;
	Security security;
private:

};

class DefaultClass : public Class
{
public:
	DefaultClass();
	~DefaultClass();

	DefaultCtor* defaultCtor;
	NamedCtor* namedCtors;
	DefaultCtor* overloadCtors;
private:

};

DefaultClass::DefaultClass()
{
}

DefaultClass::~DefaultClass()
{
}

class StaticClass : public Class
{
public:
	StaticClass();
	~StaticClass();

private:

};

StaticClass::StaticClass()
{
}

StaticClass::~StaticClass()
{
}

class TypeAlias : public Class
{
public:
	TypeAlias();
	~TypeAlias();

	string aliasedName;
private:

};

TypeAlias::TypeAlias()
{
}

TypeAlias::~TypeAlias()
{
}
