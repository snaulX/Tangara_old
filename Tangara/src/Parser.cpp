#include "Parser.h"

using namespace std;

Parser::Parser()
{
	index = 0;
}

Parser::~Parser()
{
}

Parser::Parser(string c)
{
	code = c;
	index = 0;
}

void Parser::parse()
{
	//pass
}

void Parser::skipws()
{
	//pass
}
