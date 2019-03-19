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
		String def("def");
		String ddf("ddf");

		assert(abc < def);
		assert(ddf < def);
	}
	{
		String joe("Joe");
		String joseph("Joseph");
		String john("John");

		assert(joe < joseph);
		assert(!(john < joe));
	}
	std::cout << "[UNIT TEST]: Less than test ran successfully\n";
	return 0;
}