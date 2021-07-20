/*
 * N: the length of the longer string in the given strings
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool oneAway(const string &s1, const string& s2) {
	const string *t1, *t2;
	if (s1.length() > s2.length())
		t1 = &s1, t2 = &s2;
	else
		t1 = &s2, t2 = &s1;

	if (t1->length() - t2->length() > 1) return false;

	int i1 = 0, i2 = 0;
	bool hasDiff = false;
	
	while (i1 < t1->length() && i2 < t2->length()) {
		if ((*t1)[i1] != (*t2)[i2]) {
			if (hasDiff)
				return false;
			
			hasDiff = true;
			if (t1->length() == t2->length())
				++i2;
		} else {
			++i2;
		}
		++i1;
	}

	return true;
}


int main(void) {
	vector<pair<string, string>> inputs({
		{"pale", "ple"},
		{"pales", "pale"},
		{"pale", "bale"},
		{"pale", "bake"}
	});

	for (auto i : inputs)
		cout << i.first << ", " << i.second << ": " << oneAway(i.first, i.second) << endl;

	return 0;
}
