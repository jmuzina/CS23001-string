/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String s("hello");
		int l_at = s.findch(0, 'l'), l_at_1 = s.findch(3, 'l'),
			e_at = s.findch(1, 'e'), o_at = s.findch(0, 'o'),
			t_not_found = s.findch(0, 't'), h_at = s.findch(0, 'h');

		assert(l_at == 2);
		assert(l_at_1 == 3);
		assert(e_at == 1);
		assert(o_at == 4);
		assert(t_not_found == -1);
		assert(h_at == 0);
	}
	std::cout << "[UNIT TEST]: Find char test ran successfully.\n";
	return 0;
}
