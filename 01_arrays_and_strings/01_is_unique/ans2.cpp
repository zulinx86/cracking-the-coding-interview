/*
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isUnique(const string &str) {
	if (str.length() > 256) return false;

	bool flags[256] = { false };
	for (int i = 0; i < str.length(); ++i) {
		if (flags[str[i]]) return false;
		flags[str[i]] = true;
	}

	return true;
}

int main(void) {
	vector<string> inputs({"hello", "world"});

	for (int i = 0; i < inputs.size(); ++i)
		cout << inputs[i] << ": " << isUnique(inputs[i]) << endl;

	return 0;
}
