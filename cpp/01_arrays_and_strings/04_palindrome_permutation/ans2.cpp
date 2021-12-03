/*
 * Check whether how many characters which appears odd number of times.
 *
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(N)
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
	unordered_map<char, int> mp;
	size_t cnt = 0;

	for (size_t i = 0; i < str.length(); ++i) {
		char c = tolower(str[i]);
		if (!is_lower_case_alphabet(c))
			continue;

		mp[c]++;
		
		if (mp[c] % 2 == 1)
			++cnt;
		else
			--cnt;
	}

	return cnt <= 1;
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
