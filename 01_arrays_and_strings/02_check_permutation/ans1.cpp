#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool checkPermutation(string& s1, string& s2) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;
	}
};

int main(void) {
	Solution solution;

	vector<pair<string, string>> inputs({
		{"abcdefg", "cedfgba"},	// true
		{"abcdefg", "adsfasd"},	// false
		{"aabbccc", "aabcbcc"},	// true
		{"aabbccc", "aabaccc"},	// false
		{"aaa", "aaaa"},		// false
		{"アイウエオ", "エイウオア"},
	});

	for (auto i : inputs) {
		cout << i.first << ", " << i.second << ": " << solution.checkPermutation(i.first, i.second) << endl;
	}

	return 0;
}
