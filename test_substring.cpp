/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String helloWorld("Hello World!"), hello(helloWorld.substr(0, 4));
		assert(hello == "Hello");
	}
	{
		String honestAbe("Four score and seven years ago"), four(honestAbe.substr(0, 3)), 
			score(honestAbe.substr(5, 9)),   and_(honestAbe.substr(11, 13)), seven(honestAbe.substr(15, 19)),
			years(honestAbe.substr(21, 25)), ago(honestAbe.substr(27, 29)),  Four_s(honestAbe.substr(0, 5)), 
			e_and_sev(honestAbe.substr(9, 17));

		assert(four == "Four");
		assert(score == "score");
		assert(and_ == "and");
		assert(seven == "seven");
		assert(years == "years");
		assert(ago == "ago");
		assert(Four_s == "Four s");
		assert(e_and_sev == "e and sev");
	}
	std::cout << "[UNIT TEST]: Substring test ran successfully.\n";
	return 0;
}
