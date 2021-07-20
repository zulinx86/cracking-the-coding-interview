/*
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool palindromePermutation(string str) {
	unordered_map<char, int> mp;
	int cnt = 0;

	for (int i = 0; i < str.length(); ++i) {
		char c = tolower(str[i]);
		if (c == ' ')
			continue;

		mp[c]++;
		
		if (mp[c] % 2 == 1)
			++cnt;
		else
			--cnt;
	}

	return cnt <= 1;
}

int main(void) {
	vector<string> inputs({"Tact Coa", "Hello World", "aabbcc"});

	for (auto i : inputs)
		cout << i << ": " << palindromePermutation(i) << endl;

	return 0;
}
