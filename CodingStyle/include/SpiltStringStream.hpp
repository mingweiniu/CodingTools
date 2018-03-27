#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

std::vector<std::string> SpiltStringStream(std::string input) {

	using std::istringstream;
	using std::istream_iterator;
	using std::string;
	using std::vector;

	istringstream buffer(input);
	istream_iterator<string> begin(buffer), end;

	return vector<string>(begin, end);
}
