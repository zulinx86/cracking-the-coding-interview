/*
 * Use a flag which checks whether the character appeared previously.
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
	for (const auto c : str) {
		if (flags[(size_t)c])
			return false;

		flags[(size_t)c] = true;
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
