#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

std::vector<std::string> SpiltStringStream(std::string input) {

	std::istringstream buffer(input);
	std::istream_iterator<std::string> begin(buffer), end;

	std::vector<std::string> output(begin, end); // done!

	return output;
}
