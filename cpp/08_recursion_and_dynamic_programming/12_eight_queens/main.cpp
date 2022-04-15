#include <iostream>
#include <vector>

using namespace std;

void f(int depth, const int n,
       vector<vector<bool>> &queens,
       vector<vector<bool>> avail)
{
	if (depth == n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (queens[i][j]) cout << "q ";
				else cout << ". ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (avail[depth][i]) {
			queens[depth][i] = true;
			vector<vector<bool>> new_avail(avail);

			for (int j = depth + 1; j < n; ++j)
				new_avail[j][i] = false;

			// left
			for (int j = 1; i - j >= 0 && depth + j < n; ++j)
				new_avail[depth + j][i - j] = false;

			// right
			for (int j = 1; i + j < n && depth + j < n; ++j)
				new_avail[depth + j][i + j] = false;

			f(depth + 1, n, queens, new_avail);

			queens[depth][i] = false;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;

	vector<vector<bool>> queens(n, vector<bool>(n, false));
	vector<vector<bool>> avail(n, vector<bool>(n, true));

	f(0, n, queens, avail);

	return 0;
}
