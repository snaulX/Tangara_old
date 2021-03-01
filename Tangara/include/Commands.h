#include <vector>
#include <string>
#include <fstream>

using namespace std;

#define COMMAND(name, bytecode) class name : public Command \
{ \
public: \
	name() \
	{ \
	} \
\
	~name() \
	{ \
	} \
\
	void write(ofstream* stream) \
	{\
		if (stream->is_open()) \
		{ \
			stream->write((char*)bytecode, sizeof(bytecode)); \
		} \
	}\
}

class Command
{
public:
	Command();

	~Command();

	void write(ofstream* stream);
};

class Callable : public Command
{
public:
	Callable()
	{
	}
	Callable(vector<string> keywords)
	{
		this->keywords = keywords;
	}

	~Callable()
	{
	}

	void write(ofstream *stream)
	{
		if (stream->is_open())
		{
			stream->write((char*)0, sizeof(0));
		}
	}
private:
	vector<string> keywords;
};

COMMAND(NullableCall, 1);
COMMAND(Assign, 2);
COMMAND(Statement, 3);

