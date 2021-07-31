/*
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void urlify(string &str, int length)
{
	int i, p = str.length() - 1;

	for (i = length - 1; i >= 0; --i) {
		if (str[i] == ' ') {
			str[p--] = '0';
			str[p--] = '2';
			str[p--] = '%';
		}
		else str[p--] = str[i];
	}
}


int main(void) {
	vector<pair<string, int>> inputs ({
		{"My John Smith    ", 13},
		{"Hello world  ", 11}
	});

	for (auto i : inputs) {
		cout << i.first << ": ";
		urlify(i.first, i.second);
		cout << i.first << endl;
	}

	return 0;
}
