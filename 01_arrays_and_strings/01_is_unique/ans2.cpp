/*
 * N: length of a given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isUnique(const string& str) {
	bool check[256] = { false };

	for (int i = 0; i < str.length(); ++i) {
		if (check[str[i]]) return false;
		check[str[i]] = true;
	}

	return true;
}

int main(void) {
	vector<string> inputs({"hello", "world"});

	for (int i = 0; i < inputs.size(); ++i)
		cout << inputs[i] << ": " << isUnique(inputs[i]) << endl;

	return 0;
}
