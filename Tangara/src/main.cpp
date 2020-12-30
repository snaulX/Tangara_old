#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    string line, code;

    ifstream in(argv[1]);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            code.append(line);
        }
    }
    in.close();
	Parser parser = Parser(code);
    parser.parse();
	return 0;
}