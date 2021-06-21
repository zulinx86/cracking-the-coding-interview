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
		unordered_map<char, int> mp;

		for (int i = 0; i < str.length(); ++i) {
			char c = tolower(str[i]);
			if (c == ' ') continue;
			mp[c]++;
		}

		bool hasOdd = false;
		for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
			if (itr->second % 2 == 1) {
				if (hasOdd) return false;
				else hasOdd = true;
			}
		}

		return true;
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
