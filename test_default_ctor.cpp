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
		assert(empty == '\0');

		String empty1;
		assert(empty == empty1);

		String notEmpty('a');
		assert(empty != notEmpty);

		assert(empty == "");
		assert(empty[0] == '\0');
	}

	std::cout << "[UNIT TEST]: Default Ctor test ran successfully\n";
	return 0;
}
