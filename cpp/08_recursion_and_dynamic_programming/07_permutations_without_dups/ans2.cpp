#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

void permutation(string &s, int depth) {
	if (depth == s.size()) {
		cout << s << endl;
		return;
	}

	for (int i = depth; i < s.size(); ++i) {
		swap(s[depth], s[i]);
		permutation(s, depth + 1);
		swap(s[depth], s[i]);
	}
}

int main(void)
{
	string s;
	cin >> s;

	chrono::system_clock::time_point start, end;
	start = chrono::system_clock::now();

	permutation(s, 0);

	end = chrono::system_clock::now();
	cout << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

	return 0;
}
