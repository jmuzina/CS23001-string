/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String s1("This is a sentence containing the word cone so I can make oracle work!");
		
		assert(s1.findstr(0, "cone") == 39);
	}
	{
		String s1("apzx");
		String s2("ape");
		
		assert(s1.findstr(0, s2) == -1);
	}
	{
		String s1("cter65647324234adasdatpe");
		String s2("ape");

		assert(s1.findstr(0, s2) == -1);
	}
	
	{
		String test("test");
		String nope("hello");

		assert(test.findstr(0, nope) == -1);
	}
	
	{
		String s("hello");
		String search("ell");

		int foundAt = s.findstr(0, search);

		assert(foundAt == 1);
	}
	{
		String mlk("I have a dream");
		String search("e a dream");

		int foundAt = mlk.findstr(3, search);

		assert(foundAt == 5);
	}

	{
		String fdr("December 7, 1941 a date which will live in infamy");
		String willLive("will live");

		int foundAt = fdr.findstr(10, willLive);

		assert(foundAt == 30);
	}
	{
		String rocky("Let me tell you something you already know. The world is not all sunshine and rainbows.");
		String rainbow("rainbow");

		int foundAt = rocky.findstr(25, rainbow);

		assert(foundAt == 78);
	}
	{
		String _1984_1("The essential act of war is destruction, not necessarily of human lives, but of the products "),
			_1984_2("of human labour. War is a way of shattering to pieces, or pouring into the stratosphere, or sinking "),
			_1984_3("in the depths of the sea, materials which might otherwise be used to make the masses too "),
			_1984_4("comfortable, and hence, in the long run, too intelligent.");

		String _1984_concat(_1984_1 + _1984_2 + _1984_3 + _1984_4), otherwise("otherwise");
		int foundAt = _1984_concat.findstr(68, otherwise);

		assert(foundAt == 241);
	}
	std::cout << "[UNIT TEST]: Find string test ran successfully.\n";
	return 0;
}

