/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String empty, alsoEmpty;
		alsoEmpty = empty;
		assert(alsoEmpty == empty);
	}
	{
		String helloWorld("Hello world!"), alsoHelloWorld;
		alsoHelloWorld = helloWorld;
		assert(alsoHelloWorld == "Hello world!");
	}
	{
		String drSeuss("i LikE gReEN EgGS AnD HAM"), alsoDrSeuss;
		alsoDrSeuss = drSeuss;
		assert(alsoDrSeuss == "i LikE gReEN EgGS AnD HAM");
	}
	std::cout << "[UNIT TEST]: Assignment copy test ran successfully.\n";
	return 0;
}