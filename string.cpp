/**
 * Joseph Muzina
 * String
 * CS 23001
 */

#include "string.hpp"

 // Default ctor
String::String() {
	stringSize = 1;
	str = new char[stringSize];
	str[0] = '\0';
}

// Char ctor
String::String(char c) {
	stringSize = 2;
	str = new char[stringSize];
	str[0] = c;
	str[1] = '\0';
}

// C-Str Ctor
String::String(const char cStr[]) {
	stringSize = strLength(cStr) + 1;
	str = new char[stringSize];

	for (int i = 0; cStr[i] != '\0'; ++i)
		str[i] = cStr[i];

	str[stringSize - 1] = '\0';
}

// Private int ctor
String::String(int tmp) {
	stringSize = tmp + 1;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; ++i)
		str[i] = '\0';
}

// Private int, array ctor
String::String(int size, const char rhs[]) :String(size) {
	for (int i = 0; i < stringSize; ++i)
		str[i] = rhs[i];

	str[stringSize - 1] = '\0';
}

// Copy ctor
String::String(const String& actual) {
	stringSize = actual.stringSize;
	str = new char[stringSize];

	for (int i = 0; i < stringSize; ++i)
		str[i] = actual.str[i];
	str[stringSize - 1] = '\0';
}

// Destructor
String::~String() {
	delete[] str;
}

// Pointer swap
void String::swap(String& rhs) {
	char *tmp = str;
	str = rhs.str;
	rhs.str = tmp;

	int tmpCap = stringSize;
	stringSize = rhs.stringSize;
	rhs.stringSize = tmpCap;
}

// Assignment, uses swap()
String& String::operator=(String rhs) {
	swap(rhs);
	return *this;
}

// Brackets
char& String::operator[](int x) {
	if (x < 0)
		return str[0];

	return str[x];
}

// Const brackets
char String::operator[](int x) const {
	if (x < 0)
		return str[0];

	return str[x];
}

// Number of chars that can be stored
int String::capacity() const {
	return stringSize - 1;
}

// Total length of object
int String::length() const {
	int result = 0;
	while (str[result] != '\0')
		++result;

	return result;
}

// String + String concatenation
String String::operator+(const String& rhs) const {
	const int INIT_LEN = length(), COMBINED_LEN = combinedLen(str, rhs) + 1;
	String concat(COMBINED_LEN);

	// If rhs is a null string, return string as-is
	if (rhs == "")
		return *this;

	int i = 0, rhs_i = 0;
	while (rhs[rhs_i] != '\0') {
		if (i < INIT_LEN) {
			concat.str[i] = str[i];
		}
		else {
			concat.str[i] = rhs[rhs_i];
			++rhs_i;
		}
		++i;
	}
	concat.str[i] = '\0';

	return concat;
}

// String += String compound concatenation
String& String::operator+=(const String& rhs) {
	const int INIT_LEN = length(), RHS_LEN = rhs.length(), COMBINED_LEN = combinedLen(str, rhs) + 1;
	stringSize = INIT_LEN + 1;

	// If rhs is a null string, return string as-is
	// If *this is a null string, return rhs
	if (rhs == "")
		return *this;
	if (str[0] == '\0') {
		resetCapacity(RHS_LEN + 1);
		for (int i = 0; i < RHS_LEN; ++i)
			str[i] = rhs[i];

		str[RHS_LEN] = '\0';
		return *this;
	}
	resetCapacity(COMBINED_LEN);
	for (int i = INIT_LEN, rhs_i = 0; rhs[rhs_i] != '\0'; ++i, ++rhs_i)
		str[i] = rhs[rhs_i];

	return *this;
}

// String == String comparison
bool String::operator==(const String& rhs) const {
	const int HIGHER_LEN = higherLen(str, rhs);

	for (int i = 0; i < HIGHER_LEN; ++i) {
		if (str[i] != rhs[i])
			return false;
	}
	return true;
}

// Lexigraphical comparison
bool String::operator<(const String& rhs) const {
	int i = 0;
	while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))
		++i;

	return str[i] < rhs.str[i];
}

// Returns a substring of a String between two endpoints
String String::substr(int start, int end) const {
	const int LEN = end - start + 2;

	if (start > end)
		return String("");
	else if (start == end)
		return str[start];

	if (start < 0)
		start = 0;
	if (end < 0)
		return "";
	if (start >= length())
		return "";
	if (end >= length())
		end = length() - 1;

	String temp;

	for (int i = 0; ((i < LEN - 1) && (start + i) != end + 1); ++i) {
		temp.resetCapacity(2 + i);
		temp.str[i] = str[start + i];
	}

	return temp;
}

// Returns position of a character if it is found, or -1
int String::findch(int pos, char c) const {
	const int SEARCH_LEN = capacity();

	if (pos < 0)
		pos = 0;

	int foundAt = -1;

	for (int i = pos; i < SEARCH_LEN; ++i) {
		if (str[i] == c) {
			foundAt = i;
			break;
		}
	}
	return foundAt;
}

// Returns position of a string if it is found, or -1
int String::findstr(int pos, const String& searchingFor) const {
	const int THIS_LEN = length(), SEARCH_LEN = searchingFor.length() - 1;

	// If the subset to be searched for is longer than the
	// superset, leave the function
	if (THIS_LEN < SEARCH_LEN + 1)
		return -1;

	// Position within current object's str
	int setPos = pos;

	bool found = false;

	// Searches until end of str or until match is found
	for (; setPos < THIS_LEN; setPos = findch(setPos + 1, searchingFor[0])) {
		if (setPos == -1)
			return -1;

		// Position within matched subset
		int subSetPos = 0;
		int searchPos = setPos + subSetPos;

		// Once the first characters of subsets match, searches along matched subset
		while (str[searchPos + subSetPos] == searchingFor.str[subSetPos] && subSetPos < SEARCH_LEN + 1) {
			// Leaves loop, ends search if the whole substring matches
			if (subSetPos == SEARCH_LEN) {
				found = true;
				return setPos;
			}
			++subSetPos;
		}
		++subSetPos;
	}
	if (!found)
		setPos = -1;

	return setPos;
}

// Splits a string into a vector of substrings based on a deliminating character
std::vector<String> String::split(const char DELIM) const {
	const int LEN = length();

	std::vector<String> result;
	String tmp;

	for (int i = 0; i < LEN; ++i) {
		// If str char is not the delim char, add the str char to our temp String
		if (str[i] != DELIM) {
			tmp += str[i];
		}
		// If the str char is the delim char, add the temporary String to this point to the
		// vector of Strings
		else {
			result.push_back(tmp);
			// Ensures delim chars are not added to the vector
			while (str[i + 1] == DELIM) {
				result.push_back("");
				++i;
			}
			// Resets temp String to the next character in the str array
			tmp = str[++i];
			// If the tmp string is empty and we found a delim char, pushes an empty string onto the vector
			if (tmp == "")
				result.push_back(tmp);
		}
	}
	// Adds last String to vector if it's not null
	if (tmp != '\0')
		result.push_back(tmp);
	// If no delim chars were found, adds the entire str array to the vector
	else if (result.size() == 0)
		result.push_back(*this);

	return result;
}

// Input
std::istream& operator>>(std::istream& in, String& rhs) {
	char c;
	in.get(c);

	int i = 0;
	rhs.stringSize = 1;

	// Skips whitespace characters
	while ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\0')) {
		in.get(c);
	}

	// Adds non-whitespace chars to stream
	while ((c != ' ') && (c != '\t') && (c != '\n') && (c != '\0') && !in.eof()) {
		rhs.resetCapacity(2 + i); // Resizes string array
		rhs.str[i] = c;
		in.get(c);
		++i;
	}
	rhs.str[i] = '\0'; // Sets last char to null terminator

	return in;
}

// Output
std::ostream& operator<<(std::ostream& out, const String& rhs) {
	const int LENGTH = rhs.length(), MAX_LINE_SIZE = 80;

	for (int i = 0; i < LENGTH; ++i) {
		if ((i % MAX_LINE_SIZE == 0) && (i != 0))
			out << '\n';
		out << rhs.str[i];
	}
	return out;
}

// C-str array + String concatenation
String operator+(const char lhs[], const String& rhs) {
	String concat;
	const int COMBINED_LEN = combinedLen(lhs, rhs),
		LHS_LEN = strLength(lhs);

	for (int i = 0; i < COMBINED_LEN; ++i) {
		if (i < LHS_LEN)
			concat[i] = lhs[i];
		else
			concat[i] = rhs[i - LHS_LEN];
	}
	return concat;
}

// Char + String concatenation
String operator+(char c, const String &rhs) {
	String concat(c);

	for (int i = 1; i < rhs.length(); ++i)
		concat[i] = rhs[i];

	return concat;
}

// C-str array == String comparison
bool operator==(const char c[], const String& rhs) {
	const int HIGHER_LEN = higherLen(c, rhs);

	for (int i = 0; i < HIGHER_LEN; ++i) {
		if (c[i] != rhs[i])
			return false;
	}

	return true;
}

// char == String comparison
bool operator==(char c, const String& rhs) {
	return (c == rhs[0]);
}

// C-str array < String lexigraphical comparison
bool operator<(const char c[], const String& rhs) {
	const int HIGHER_LEN = higherLen(c, rhs);

	for (int i = 0; i < HIGHER_LEN; ++i)
		if (c[i] < rhs[i])
			return true;

	return false;
}

// Char < String lexigraphical comparison
bool operator<(char c, const String& rhs) {
	for (int i = 0; i < rhs.length(); ++i)
		if (c < rhs[i])
			return true;

	return false;
}

// String <= String lexigraphical comparison
bool operator<=(const String& lhs, const String& rhs) {
	return ((lhs < rhs) || (lhs == rhs));
}

// String != String comparison
bool operator!=(const String& lhs, const String& rhs) {
	if (lhs == rhs)
		return false;

	return true;
}

// String >= String lexigraphical comparison
bool operator>=(const String& lhs, const String& rhs) {
	if ((lhs == rhs) || (lhs > rhs))
		return true;

	return false;
}

// String > String lexigraphical comparison
bool operator>(const String& lhs, const String& rhs) {
	const int LHS_LEN = lhs.length(), RHS_LEN = rhs.length(),
		HIGHER_LEN = LHS_LEN > RHS_LEN ? LHS_LEN : RHS_LEN;

	for (int i = 0; i < HIGHER_LEN; ++i)
		if (lhs[i] > rhs[i])
			return true;

	return false;
}

// Clean up a string and reset its capacity
void String::resetCapacity(int cap) {
	if (cap < 1)
		cap = 1;

	char *tmp;
	tmp = new char[cap];

	for (int i = 0; i < cap; ++i)
		if (i < length())
			tmp[i] = str[i];
		else
			tmp[i] = '\0';

	delete[] str;
	stringSize = cap;
	str = new char[stringSize];

	for (int i = 0; i < cap; ++i)
		str[i] = tmp[i];

	delete[] tmp;

	str[cap - 1] = '\0';
}

// Length of a C-str array
int strLength(const char str[]) {
	int count = 0;

	while (str[count] != '\0')
		++count;

	return count;
}

// Returns the higher of the two lengths of a C-str array and a String
int higherLen(const char s1[], const String& s2) {
	const int LEN_1 = strLength(s1), LEN_2 = s2.length(),
		result = LEN_1 > LEN_2 ? LEN_1 : LEN_2;

	return result;
}

// Returns combined length of a C-str array and String
int combinedLen(const char lhs[], const String& rhs) {
	return (strLength(lhs) + rhs.length());
}

// Convert a string of integers into an integer
int String::toInt() const {
	const int S_LEN = length();
	int result = 0;

	for (int i = 0; i < S_LEN - 1; i++) {
		int exponent = S_LEN - i - 1;
		result += (str[i] - '0') * power(10, exponent);
	}
	result += (str[S_LEN - 1] - '0');

	return result;
}

// Raise an int base to an int exponent 
int power(const int base, const int exp) {
	if (exp <= 0)
		return 0;

	int result = base;

	for (int i = 1; i < exp; ++i)
		result *= base;

	return result;
}
