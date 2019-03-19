/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String hello("Hello ");
		String world("world!");
		String helloWorld(hello + world);

		assert(hello == "Hello ");
		assert(world == "world!");
		assert(helloWorld == "Hello world!");
	}
	{
		String i('I');
		String null;
		String space(' ');
		String love("love");
		String concat(i + null + space + love + space + "CS2!");

		assert(concat == "I love CS2!");
	}
	{
		String newLine('\n'), period('.'), space(' '), comma(','), give("Give"), a('a'), man("man"),
			program("program"), frustrate("frustrate"), him("him"), day("day"), teach("Teach"), to("to"), lifetime("lifetime");

		String concat(give + space + a + space + man + space + a + space + program + comma + space + frustrate + space + him +
			space + a + space + day + period + newLine + teach + space + a + space + man + space + to + space + program + comma +
			space + frustrate + space + him + space + a + space + lifetime + period);

		assert(concat == "Give a man a program, frustrate him a day.\nTeach a man to program, frustrate him a lifetime.");
	}
	{
		String s1("test");
		String s2("ing");
		s1 += s2;
		assert(s1 == "testing");
	}
	std::cout << "[UNIT TEST]: Concatenation test ran successfully\n";
	return 0;
}

