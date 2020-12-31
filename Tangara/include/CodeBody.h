#include "Commands.h"
#include <vector>

using namespace std;

class CodeBody
{
public:
	CodeBody();
	~CodeBody();

	int hash;
private:

};

CodeBody::CodeBody()
{
	hash = 0;
}

CodeBody::~CodeBody()
{
}