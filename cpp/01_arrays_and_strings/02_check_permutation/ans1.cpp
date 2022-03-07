/*
 * Sort the two strings and then compare them in order from front.
 *
 * N: the length of the given string
 * Time complexity: O(N log N) (O(1) if the lengths are different)
 * Space complexity: O(1) (note that sorting may take additional space inside)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_permutation(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return s1 == s2;
}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;

	cout << check_permutation(s1, s2) << endl;
	return 0;
}
