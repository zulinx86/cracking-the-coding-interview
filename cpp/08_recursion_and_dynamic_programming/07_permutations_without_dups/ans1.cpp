#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

void permutation(const string &s, vector<bool> &used, string curr) {
	if (curr.size() == s.size()) {
		cout << curr << endl;
		return;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (used[i]) continue;
		used[i] = true;
		permutation(s, used, curr + s[i]);
		used[i] = false;
	}
}

int main(void)
{
	string s;
	cin >> s;

	chrono::system_clock::time_point start, end;
	start = chrono::system_clock::now();

	vector<bool> used(s.size(), false);
	permutation(s, used, "");

	end = chrono::system_clock::now();
	cout << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

	return 0;
}
