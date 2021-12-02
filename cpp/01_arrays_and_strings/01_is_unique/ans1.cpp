/*
 * Compare each character with characters in the rest part of the string.
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
	for (size_t i = 0; i < str.length(); ++i) {
		for (size_t j = i + 1; j < str.length(); ++j) {
			if (str[i] == str[j])
				return false;
		}
	}

	return true;
}

int main(void)
{
	vector<string> inputs({"hello", "world"});

	for (const auto &i : inputs)
		cout << i << ": " << is_unique(i) << endl;

	return 0;
}
