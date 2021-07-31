/*
 * N: the length of the given string
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string stringCompression(const string &str)
{
	int len = 0;

	for (int i = 0; i < str.length(); ++i) {
		char c = str[i];
		int cnt = 1;

		while (i + 1 != str.length() && str[i + 1] == c) {
			++cnt;
			++i;
		}

		int len_cnt = 1;
		while (cnt /= 10)
			++len_cnt;

		len += len_cnt + 1;
	}

	if (len < str.length()) {
		string result;
		result.reserve(len);

		for (int i = 0; i < str.length(); ++i) {
			char c = str[i];
			int cnt = 1;

			while (i + 1 != str.length() && str[i + 1] == c) {
				++cnt;
				++i;
			}

			result += c + to_string(cnt);
		}
		return result;
	}

	return str;
}


int main(void)
{
	vector<string> inputs({
		"aabcccccaaa", /* a2b1c5a3 */
		"aaaa", /* a4 */
		"abcd", /* abcd (a1b1c1d1) */
		"aaaaaaaaaaabbbbbbbbbbbbbb" /* a11b14 */
	});

	for (auto i : inputs)
		cout << i << ": " << stringCompression(i) << endl;

	return 0;
}
