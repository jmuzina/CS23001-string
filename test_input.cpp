/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>
#include <fstream>

int main() {
	{
		String s, s1;
		assert(s == "");

		std::ifstream test("text.txt");
		if (test.fail()) {
			std::cerr << "text.txt failed to open \n";
			return 1;
		}

		if (!test.eof())
			test >> s;
		if (!test.eof())
			test >> s1;
		s += s1;
		assert(s == "HelloWorld!");
	}
	std::cout << "[UNIT TEST]: Input test ran successfully\n";
	return 0;
}


