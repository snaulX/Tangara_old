#include "Parser.h"

using namespace std;

Parser::Parser()
{
	index = 0;
	addstemplate("package", package);
}

Parser::~Parser()
{
}

Parser::Parser(string c) : Parser()
{
	code = c;
}

void Parser::parse()
{
	for (index = 0; index < code.length(); index++)
	{
		skipws();
		if (iswalpha(code[index]))
		{
			parseKeyword(getKeyword());
		}
		else
		{
			//pass
		}
	}
}

void Parser::error(string message)
{
	cerr << message << endl;
}

string Parser::getKeyword()
{
	string keyword = "";
	for (; index < code.length(); index++)
	{
		char c = code[index];
		if (!iswspace(c) && !iswpunct(c))
			keyword += c;
		else
			return keyword;
	}
	return "";
}

void Parser::isExprEnd()
{
	skipws();
	if (code[index] == ';')
	{
		index++;
	}
	else
	{
		error("Excepted semicolon");
	}
}

void Parser::package()
{
	skipws();
	packageName = getKeyword();
	isExprEnd();
}

void Parser::parseKeyword(string keyword)
{
	/*auto f = strongTemplates[keyword];
	auto t = strongTemplates.find(keyword);
	if (t != strongTemplates.end())
	{
	}
	//if (f != nullptr)
		//(this->*f)();*/

	if (keyword == "package") package();
	else
	{
		// is not keyword
		char c = code[index];
		if (iswpunct(c))
		{
			if (c == '.')
			{
				// this keyword is callable object
			}
		}
	}
}

void Parser::skipws()
{
	for (; index < code.length(); index++)
	{
		if (!iswspace(code[index]))
			return;
	}
}
