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
		if (str[i] == ' ') {
			str[p--] = '0';
			str[p--] = '2';
			str[p--] = '%';
		}
		else str[p--] = str[i];
	}
}

int main(void)
{
	string s;
	getline(cin, s);

	urlify(s, s.size());

	cout << s << endl;
	return 0;
}
