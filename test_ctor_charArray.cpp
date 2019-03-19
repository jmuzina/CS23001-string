/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String abc("abc");

		assert(abc == "abc");
		assert(abc[0] == 'a');
		assert(abc[1] == 'b');
		assert(abc[2] == 'c');
		assert(abc[3] == '\0');
		assert(abc != "abcd");

		String xyz("xyz");
		assert(xyz == "xyz");
		assert(abc != xyz);
	}
	std::cout << "[UNIT TEST]: C-str char array ctor test ran successfully\n";
	return 0;
}
