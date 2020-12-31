#include "Parser.h"

using namespace std;

Parser::Parser()
{
	index = 0;
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
	//pass
}

void Parser::skipws()
{
	//pass
}
