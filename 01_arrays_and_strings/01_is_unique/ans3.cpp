/*
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isUnique(const string &str)
{
	int i, checker = 0;
	for (i = 0; i < str.length(); ++i) {
		if (checker & (1 << str[i]))
			return false;

		checker |= (1 << str[i]);
	}

	return true;
}

int main(void)
{
	int i;
	vector<string> inputs({"hello", "world"});

	for (i = 0; i < inputs.size(); ++i)
		cout << inputs[i] << ": " << isUnique(inputs[i]) << endl;

	return 0;
}
