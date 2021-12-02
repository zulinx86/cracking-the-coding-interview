/*
 * Sort the two strings and then compare them in order from front.
 *
 * N: the length of the longer string in the given strings
 * Time complexity: O(N log N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_permutation(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return s1 == s2;
}

int main(void)
{
	vector<pair<string, string>> inputs({
		{"abcdefg", "cedfgba"},	// true
		{"abcdefg", "adsfasd"},	// false
		{"aabbccc", "aabcbcc"},	// true
		{"aabbccc", "aabaccc"},	// false
		{"aaa", "aaaa"},	// false
	});

	for (const auto &i : inputs)
		cout << i.first << ", " << i.second << ": " <<
			check_permutation(i.first, i.second) << endl;

	return 0;
}
