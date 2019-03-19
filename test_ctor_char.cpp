/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String s('a');
		assert(s[0] == 'a');
		assert(s[1] == '\0');
		assert(s == 'a');
	}
	{
		String s('x');
		assert(s[0] == 'x');
		assert(s[1] == '\0');
		assert(s == 'x');
		assert(s != "xx");
	}
	std::cout << "[UNIT TEST]: Character Constructor ran successfully\n";
	return 0;
}
