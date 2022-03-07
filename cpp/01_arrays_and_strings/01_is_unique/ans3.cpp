/*
 * Use a bit array where each bit means if the character appeared previously.
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
	unsigned int flag = 0;
	for (const char c : str) {
		if (c < 'a' || 'z' < c) {
			cerr << "Error: invalid input" << endl;
			return false;
		}

		if (flag & (1 << (c - 'a')))
			return false;

		flag |= (1 << (c - 'a'));
	}

	return true;
}

int main(void)
{
	string s;
	cin >> s;

	cout << is_unique(s) << endl;
	return 0;
}
