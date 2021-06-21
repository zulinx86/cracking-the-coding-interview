/*
 * Brute Force
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool isUnique(const string& str) {
		for (int i = 0; i < str.length(); ++i) {
			for (int j = i + 1; j < str.length(); ++j) {
				if (str[i] == str[j]) return false;
			}
		}

		return true;
	}
};

int main(void) {
	Solution solution;
	vector<string> inputs({"hello", "world"});

	for (int i = 0; i < inputs.size(); ++i) {
		cout << inputs[i] << ": " << solution.isUnique(inputs[i]) << endl;
	}

	return 0;
}
