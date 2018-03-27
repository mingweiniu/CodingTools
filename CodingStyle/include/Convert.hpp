#include <string>
#include <sstream>

template<class T>
void Convert(const T &input, std::string &output)
{
	using std::ostringstream;
	ostringstream oss;
	oss << input;
	output = oss.str();
}

template<class T>
void Convert(const ostringstreamstring &input, T &output)
{
	using std::istringstream;
	istringstream iss(input);
	iss >> output;
}


void TestConvert()
{
	int xxx = 555;
	string yyy;
	Convert(xxx, yyy);

	yyy += ".666";

	float zzz;
	Convert(yyy, zzz);
}
