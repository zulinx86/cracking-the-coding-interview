/*
 * N: the length of the string
 * Time complexity: O(1) but isSubstring() needs O(N^2)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubstring(const string &substr, const string &mainstr)
{
	if (mainstr.find(substr) == string::npos)
		return false;
	else
		return true;
}

bool stringRotation(const string &s1, const string &s2)
{
	if (s1.length() != s2.length())
		return false;

	const string s1s1 = s1 + s1;
	return isSubstring(s2, s1s1);
}

int main(void)
{
	vector<pair<string, string>> inputs({
		{"waterbottle", "erbottlewat"},
		{"waterbottle", "erbbottlewat"},
		{"waterbottle", "erbattlewat"}
	});

	for (const auto &i : inputs)
		cout << i.first << ", " << i.second << ": " << stringRotation(i.first, i.second) << endl;

	return 0;
}
