#include <vector>
#include <string>

using namespace std;

class Command
{
public:
	Command();

	~Command();

	void write();
private:

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

	void write()
	{
		//pass
	}
private:
	vector<string> keywords;
};

