/*
 * Process from back to front.
 *
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
	int p = str.length() - 1;

	for (int i = length - 1; i >= 0; --i) {
		if (str[(size_t)i] == ' ') {
			str[(size_t)p--] = '0';
			str[(size_t)p--] = '2';
			str[(size_t)p--] = '%';
		}
		else str[(size_t)p--] = str[(size_t)i];
	}
}


int main(void) {
	vector<pair<string, int>> inputs ({
		{"My John Smith    ", 13},
		{"Hello world  ", 11}
	});

	for (auto i : inputs) {
		cout << "\"" << i.first << "\" -> \"";
		urlify(i.first, i.second);
		cout << i.first << "\"" << endl;
	}

	return 0;
}
