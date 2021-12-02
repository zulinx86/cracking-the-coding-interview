/*
 * Use a bit array whose each bit means whether the character existed.
 *
 * Note:
 * The number of character types is limited to the size of the bit array.
 * In this implementation, `int` is used as the bit array, which means that 
 * the number of character types is limited to 32. So strings consisting of 
 * only 'a' - 'z' are acceptible.
 *
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool is_unique(const string &str)
{
	int checker = 0;
	for (const auto c : str) {
		if (checker & (1 << (c - 'a')))
			return false;

		checker |= (1 << (c - 'a'));
	}

	return true;
}

int main(void)
{
	vector<string> inputs({"hello", "world"});

	for (const auto &i : inputs)
		cout << i << ": " << is_unique(i) << endl;

	return 0;
}
