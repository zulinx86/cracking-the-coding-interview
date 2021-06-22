/*
 * Concat
 * Time complexity: O(1) but isSubstring() runs in O(n)
 * Space Complexity: O(n)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool stringRotation(const string &s1, const string &s2) {
		if (s1.length() != s2.length()) return false;

		const string s1s1 = s1 + s1;
		return isSubstring(s2, s1s1);
	}

private:
	bool isSubstring(const string &substr, const string &mainstr) {
		if (mainstr.find(substr) == string::npos) return false;
		else return true;
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, string>> inputs({
		{"waterbottle", "erbottlewat"},
		{"waterbottle", "erbbottlewat"},
		{"waterbottle", "erbattlewat"}
	});

	for (const auto &input : inputs) {
		cout << input.first << ", " << input.second << ": " << solution.stringRotation(input.first, input.second) << endl;
	}
	return 0;
}
