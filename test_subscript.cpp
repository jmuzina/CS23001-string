/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main(){
	{
		String s;
		assert(s[0]  == '\0');
	}
	{
		String s("hello");
		assert(s[0] == 'h');
		assert(s[1] == 'e');
		assert(s[5] == '\0');
	}
	{
		String s("0123456789012345678901234567890");
		assert(s[29] == '9');
		assert(s[18] == '8');
	}
	std::cout << "[UNIT TEST]: Subscript test ran successfully.\n";
	return 0;
}