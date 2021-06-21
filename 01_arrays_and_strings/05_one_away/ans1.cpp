/*
 * Check separately
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool oneAway(const string &s1, const string& s2) {
		const string *t1, *t2;
		if (s1.length() > s2.length()) t1 = &s1, t2 = &s2;
		else t1 = &s2, t2 = &s1;

		if (t1->length() - t2->length() > 1) return false;

		if (t1->length() == t2->length()) {
			int cnt = 0;
			for (int i = 0; i < t1->length(); ++i) {
				if ((*t1)[i] != (*t2)[i]) ++cnt;
				if (cnt > 1) return false;
			}
			return true;
		}

		bool hasDiff = false;
		for (int i = 0; i < t2->length(); ++i) {
			if (hasDiff) {
				if ((*t1)[i+1] != (*t2)[i]) return false;
			}
			else {
				if ((*t1)[i] != (*t2)[i]) hasDiff = true;
			}
		}

		return true;
	}
};

int main(void) {
	Solution solution;
	vector<pair<string, string>> inputs({
		{"pale", "ple"},
		{"pales", "pale"},
		{"pale", "bale"},
		{"pale", "bake"}
	});

	for (int i = 0; i < inputs.size(); ++i) {
		cout << inputs[i].first << ", " << inputs[i].second << ": " << solution.oneAway(inputs[i].first, inputs[i].second) << endl;
	}

	return 0;
}
