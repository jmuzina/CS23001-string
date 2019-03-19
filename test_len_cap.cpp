/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String empty;
		assert(empty.length() == 0);
		assert(empty.capacity() == 0);
	}
	{
		String hello("hello");
		assert(hello.length() == 5);
		assert(hello.capacity() == 5);
	}
	{
		String thisShouldBe10("10letters!");
		assert(thisShouldBe10.length() == 10);
		assert(thisShouldBe10.capacity() == 10);
	}
	{
		String s("12345678901234567890123456789012345678901234567890");
		assert(s.length() == 50);
		assert(s.capacity() == 50);
	}
	std::cout << "[UNIT TEST]: Length & Capacity test ran successfully\n";
	return 0;
}
