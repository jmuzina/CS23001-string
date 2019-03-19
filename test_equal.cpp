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
		String j('j');
		assert(empty != j);
	}
	{
		String abc1("abc");
		String abc2("abc");
		assert(abc1 == abc2);
	}
	{
		String helloWorld("Hello World!");
		assert(helloWorld == "Hello World!");
		assert(helloWorld != "HelloWorld!");
		assert(helloWorld[20] == '\0');
		assert(helloWorld != "HelloWorld! ");
	}
	std::cout << "[UNIT TEST]: Comparison test ran successfully\n";
	return 0;
}
