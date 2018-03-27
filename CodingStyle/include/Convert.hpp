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
  using std::ostringstream;
	istringstream iss(input);
	iss >> output;
}
