/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String s1("Hello world!");
		String copy(s1);
		assert(copy == "Hello world!");
	}
	{
		String s1;
		String copy(s1);
		assert(copy == "");
	}
	{
		String s1("7389t47ybfhjdskbr76621t3478_=4598762fg 6  983y2465980u83927____");
		String copy(s1);
		assert(copy == "7389t47ybfhjdskbr76621t3478_=4598762fg 6  983y2465980u83927____");
	}
	std::cout << "[UNIT TEST]: Copy ctor test ran successfully.\n";
	return 0;
}

