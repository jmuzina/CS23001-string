/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"
#include <cassert>

int main() {
	{
		String test("Hello-World,-my-name-is-Joe!");
		std::vector<String> vec = test.split('-');

		assert(vec[0] == "Hello");
		assert(vec[0].length() == 5);
		assert(vec[1] == "World,");
		assert(vec[1].length() == 6);
		assert(vec[2] == "my");
		assert(vec[2].length() == 2);
		assert(vec[3] == "name");
		assert(vec[3].length() == 4);
		assert(vec[4] == "is");
		assert(vec[4].length() == 2);
		assert(vec[5] == "Joe!");
		assert(vec[5].length() == 4);
		assert(vec.size() == 6);
	}
	{
		String test("+Th+is s +entence is   +de+signed to    \n test+ m+y spl+it method!+");
		std::vector<String> vec = test.split('+');

		assert(vec[0] == "");
		assert(vec[0].length() == 0);
		assert(vec[1] == "Th");
		assert(vec[1].length() == 2);
		assert(vec[2] == "is s ");
		assert(vec[2].length() == 5);
		assert(vec[3] == "entence is   ");
		assert(vec[3].length() == 13);
		assert(vec[4] == "de");
		assert(vec[4].length() == 2);
		assert(vec[5] == "signed to    \n test");
		assert(vec[5].length() == 19);
		assert(vec.size() == 10);
	}
	{
		String test("This sentence will not be split!");
		std::vector<String> vec = test.split('\n');

		assert(vec[0] == "This sentence will not be split!");
		assert(vec.size() == 1);
	}
	{
		String test("Supercalifragilisticexpialidocious");
		std::vector<String> vec = test.split('a'); // Superc lifr gilisticexpi licodious

		assert(vec[0] == "Superc");
		assert(vec[1] == "lifr");
		assert(vec[2] == "gilisticexpi");
		assert(vec[3] == "lidocious");
	}
	{
		String s("-a--b-");
		std::vector<String> vec = s.split('-');

		assert(vec[0] == "");
		assert(vec[1] == "a");
		assert(vec[2] == "");
		assert(vec[3] == "b");
		assert(vec[4] == "");
		assert(vec.size() == 5);
	}
	{
		String noDelims("This String will not be split and will be one whole String in the vector!");
		std::vector<String> vec = noDelims.split('_');

		assert(vec.size() == 1);
		assert(vec[0] == "This String will not be split and will be one whole String in the vector!");
	}
	std::cout << "[UNIT TEST]: Split to vector test ran successfully.\n";
	return 0;
}
