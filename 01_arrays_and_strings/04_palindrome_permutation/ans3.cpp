/*
 * Hash Table
 * Time complexity: O(n)
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	bool palindromePermutation(string str) {
		int bitVec = 0;

		for (int i = 0; i < str.length(); ++i) {
			char c = tolower(str[i]);
			if (c == ' ') continue;
			int mask = 1 << c - 'a';
			if (mask & bitVec) bitVec &= ~mask;
			else bitVec |= mask;
		}

		return (bitVec & (bitVec - 1)) == 0;
	}
};

int main(void) {
	Solution solution;
	vector<string> inputs({"Tact Coa", "Hello World", "aabbcc"});

	for (int i = 0; i < inputs.size(); ++i) {
		cout << inputs[i] << ": " << solution.palindromePermutation(inputs[i]) << endl;
	}

	return 0;
}
