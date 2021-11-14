/*
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool palindromePermutation(string str)
{
	unsigned int bitVec = 0;

	for (int i = 0; i < str.length(); ++i) {
		char c = tolower(str[i]);
		if (c == ' ')
			continue;

		unsigned int mask = 1 << c - 'a';
		if (mask & bitVec)
			bitVec &= ~mask;
		else
			bitVec |= mask;
	}

	return (bitVec & (bitVec - 1)) == 0;
}


int main(void)
{
	vector<string> inputs({"Tact Coa", "Hello World", "aabbcc"});

	for (auto i : inputs)
		cout << i << ": " << palindromePermutation(i) << endl;

	return 0;
}
