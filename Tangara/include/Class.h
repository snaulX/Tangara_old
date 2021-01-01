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

class StaticClass : public Class
{
public:
	StaticClass();
	~StaticClass();

private:

};

class TypeAlias : public Class
{
public:
	TypeAlias();
	~TypeAlias();

	string aliasedName;
private:

};
