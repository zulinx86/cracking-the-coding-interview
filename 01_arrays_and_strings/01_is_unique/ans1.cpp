/*
 * N: the length of the given string
 * Time complexity: O(N^2)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(const string &str)
{
	int i, j;

	for (i = 0; i < str.length(); ++i) {
		for (j = i + 1; j < str.length(); ++j) {
			if (str[i] == str[j])
				return false;
		}
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
