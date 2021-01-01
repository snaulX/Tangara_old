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

class Params : public Parameter
{
public:
	Params();
	~Params();

private:

};
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

class StaticFunction : public Function
{
public:
	StaticFunction();
	~StaticFunction();

private:

};

class AbstractFunction : public Function
{
public:
	AbstractFunction();
	~AbstractFunction();

private:

};

class FuncAlias : public Function
{
public:
	FuncAlias();
	~FuncAlias();

	string aliasedName;
private:

};
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

class NamedCtor : public Constructor
{
public:
	NamedCtor();
	~NamedCtor();

	string name;
private:

};
#pragma endregion
