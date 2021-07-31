/*
 * N: the length of the longer string in the given strings
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool oneAway(const string &s1, const string &s2)
{
	const string *t1, *t2;
	if (s1.length() > s2.length())
		t1 = &s1, t2 = &s2;
	else
		t1 = &s2, t2 = &s1;

	if (t1->length() - t2->length() > 1)
		return false;

	if (t1->length() == t2->length()) {
		int cnt = 0;
		for (int i = 0; i < t1->length(); ++i) {
			if ((*t1)[i] != (*t2)[i]) {
				++cnt;
				if (cnt > 1)
					return false;
			}
		}
		return true;
	}

	bool hasDiff = false;
	for (int i = 0; i < t2->length(); ++i) {
		if (hasDiff && (*t1)[i+1] != (*t2)[i])
				return false;
		else if ((*t1)[i] != (*t2)[i])
				hasDiff = true;
	}

	return true;
}


int main(void)
{
	vector<pair<string, string>> inputs({
		{"pale", "ple"},
		{"pales", "pale"},
		{"pale", "bale"},
		{"pale", "bake"}
	});

	for (auto i : inputs)
		cout << i.first << ", " << i.second << ": " <<
			oneAway(i.first, i.second) << endl;

	return 0;
}
