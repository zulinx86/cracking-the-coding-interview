/*
 * Use a flag array to check if the character appeared previously.
 *
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool is_unique(const string &str)
{
	if (str.length() > 128)
		return false;

	bool flags[128] = { false };
	for (const char c : str) {
		if (flags[c])
			return false;

		flags[c] = true;
	}

	return true;
}

int main(void)
{
	string s;
	cin >> s;

	cout << in_unique(s) << endl;
	return 0;
}
