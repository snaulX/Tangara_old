


class Template
{
	//pass
};

class StrongTemplate : public Template
{
public:
	StrongTemplate();

	const char* keyword;

	void Parse(char* line);
};