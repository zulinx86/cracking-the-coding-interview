/*
 * Compare each character with characters in the subsequent part of the given
 * string.
 *
 * N: the length of the given string
 * Time complexity: O(N^2)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_unique(const string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
		for (size_t j = i + 1; j < str.length(); ++j)
			if (str[i] == str[j])
				return false;

	return true;
}

int main(void)
{
	string s;
	cin >> s;

	cout << is_unique(s) << endl;
	return 0;
}
