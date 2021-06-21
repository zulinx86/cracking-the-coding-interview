/*
 * Go Backwards
 * Time complexity: O(n)
 * Space complexity: No extra space
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	void urlify(string &str, int length) {
		int p = str.length() - 1;
		for (int i = length - 1; i >= 0; --i) {
			if (str[i] == ' ') {
				str[p--] = '0';
				str[p--] = '2';
				str[p--] = '%';
			}
			else str[p--] = str[i];
		}
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, int>> inputs ({
		{"My John Smith    ", 13},
		{"Hello world  ", 11}
	});

	for (int i = 0; i < inputs.size(); ++i) {
		cout << inputs[i].first << ": ";
		solution.urlify(inputs[i].first, inputs[i].second);
		cout << inputs[i].first << endl;
	}

	return 0;
}
