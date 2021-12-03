/*
 * Count up how many times each character appears and check if only one 
 * character which appears odd number of times exists.
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

	for (size_t i = 0; i < str.length(); ++i) {
		char c = tolower(str[i]);
		if (!is_lower_case_alphabet(c)) continue;
		mp[c]++;
	}

	bool has_odd = false;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		if (itr->second % 2 == 1) {
			if (has_odd)
				return false;
			else
				has_odd = true;
		}
	}

	return true;
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
