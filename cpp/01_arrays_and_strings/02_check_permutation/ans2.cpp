/*
 * Count up how many times each character appears and then compare.
 *
 * N: the length of the longer string in the given strings
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check_permutation(const string &s1, const string &s2)
{
	if (s1.length() != s2.length())
		return false;

	int count[128] = {0};

	for (auto c : s1)
		++count[c];

	for (auto c : s2)
		--count[c];

	for (size_t i = 0; i < 128; ++i) {
		if (count[i] != 0)
			return false;
	}

	return true;
}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;

	cout << check_permutation(s1, s2) << endl;
	return 0;
}
