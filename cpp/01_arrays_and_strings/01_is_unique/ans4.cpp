/*
 * Sort the given string and then compare neighboring characters.
 *
 * N: the length of the given string.
 * Time complexity: O(N log N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

bool is_unique(string s) {
	sort(s.begin(), s.end());

	for (int i = 0; i < s.size() - 1; ++i)
		if (s[i] == s[i + 1])
			return false;

	return true;
}

int main() {
	string s;
	cin >> s;

	cout << is_unique(s) << endl;
	return 0;
}
