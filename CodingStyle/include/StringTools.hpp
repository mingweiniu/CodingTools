#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

std::vector<std::string> SpiltString(std::string input) {

	std::istringstream buffer(input);
	std::istream_iterator<std::string> begin(buffer), end;

	std::vector<std::string> output(begin, end); // done!

	return output;
}


template<class T>
void Turn(const std::string &input, T &output) {
	std::istringstream(input) >> output;
}

template<class T>
void Turn(const T &input, std::string &output) {
	std::ostringstream oss;
	oss << input;
	output = oss.str();
}
