/*
 * Process from front to back
 *
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <string>

using namespace std;

void urlify(string &str, int length)
{
	string result(length, ' ');

	int last = 0;
	for (int i = 0; i < length; ++i)
		if (str[i] != ' ')
			last = i;

	for (int i = 0, p = 0; i <= last; ++i, ++p) {
		if (str[i] == ' ') {
			result[p] = '%';
			result[p + 1] = '2';
			result[p + 2] = '0';
			p += 2;
		} else {
			result[p] = str[i];
		}
	}

	swap(str, result);
}

int main()
{
	string s;
	getline(cin, s);

	urlify(s, s.size());

	cout << s << endl;
	return 0;
}
