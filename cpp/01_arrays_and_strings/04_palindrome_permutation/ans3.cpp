/*
 * Use a bit array to count up how many characters appears odd number of times.
 *
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool is_lower_case_alphabet(char c) {
	return 'a' <= c && c <= 'z';
}

bool palindrome_permutation(string str)
{
	unsigned int bits = 0;

	for (size_t i = 0; i < str.length(); ++i) {
		char c = tolower(str[i]);
		if (!is_lower_case_alphabet(c))
			continue;

		unsigned int mask = 1 << (c - 'a');
		if (mask & bits)
			bits &= ~mask;
		else
			bits |= mask;
	}

	return (bits & (bits - 1)) == 0;
}


int main(void)
{
	vector<string> inputs({
		"Tact Coa",	// true
		"Hello World",	// false
		"aabbcc"	// true
	});

	for (const auto &i : inputs)
		cout << i << ": " << palindrome_permutation(i) << endl;

	return 0;
}
