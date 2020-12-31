#include "CodeBody.h"
#include "Variable.h"
#include <string>

using namespace std;

#pragma region Parameters
class Parameter
{
public:
	Parameter()
	{
	}

	~Parameter()
	{
	}

	string name, typeName;
private:

};

class DefaultParameter : public Parameter
{
public:
	DefaultParameter();
	~DefaultParameter();

private:

};

DefaultParameter::DefaultParameter()
{
}

DefaultParameter::~DefaultParameter()
{
}

class Params : public Parameter
{
public:
	Params();
	~Params();

private:

};

Params::Params()
{
}

Params::~Params()
{
}
#pragma endregion

#pragma region Functions
class Function
{
public:
	Function()
	{
	}

	~Function()
	{
	}

	CodeBody* body;
	string name;
	Parameter* params;
	Security security;
private:

};

class DefaultFunction : public Function
{
public:
	DefaultFunction();
	~DefaultFunction();

private:

};

DefaultFunction::DefaultFunction()
{
}

DefaultFunction::~DefaultFunction()
{
}

class StaticFunction : public Function
{
public:
	StaticFunction();
	~StaticFunction();

private:

};

StaticFunction::StaticFunction()
{
}

StaticFunction::~StaticFunction()
{
}

class AbstractFunction : public Function
{
public:
	AbstractFunction();
	~AbstractFunction();

private:

};

AbstractFunction::AbstractFunction()
{
}

AbstractFunction::~AbstractFunction()
{
}

class FuncAlias : public Function
{
public:
	FuncAlias();
	~FuncAlias();

	string aliasedName;
private:

};

FuncAlias::FuncAlias()
{
}

FuncAlias::~FuncAlias()
{
}
#pragma endregion

#pragma region Constructors

class Constructor
{
public:
	Constructor()
	{
	}

	~Constructor()
	{
	}

private:

};

class DefaultCtor : public Constructor
{
public:
	DefaultCtor();
	~DefaultCtor();

private:

};

DefaultCtor::DefaultCtor()
{
}

DefaultCtor::~DefaultCtor()
{
}

class NamedCtor : public Constructor
{
public:
	NamedCtor();
	~NamedCtor();

	string name;
private:

};

NamedCtor::NamedCtor()
{
}

NamedCtor::~NamedCtor()
{
}
#pragma endregion
