/*
 * N: the length of the longer string in the given strings
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkPermutation(const string &s1, const string &s2)
{
	int count[256] = {0};

	if (s1.length() != s2.length())
		return false;

	for (auto s : s1)
		++count[s];
	for (auto s : s2)
		--count[s];

	for (int i = 0; i < 256; ++i) {
		if (count[i] != 0)
			return false;
	}

	return true;
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

	for (auto i : inputs)
		cout << i.first << ", " << i.second << ": " <<
			checkPermutation(i.first, i.second) << endl;

	return 0;
}
