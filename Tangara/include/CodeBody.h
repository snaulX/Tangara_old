#include "Commands.h"
#include <vector>

using namespace std;

class CodeBody
{
public:
	CodeBody();
	~CodeBody();

	vector<ICommand> body;
private:

};

CodeBody::CodeBody()
{
	body = vector<ICommand>();
}

CodeBody::~CodeBody()
{
	//delete body.data;
}