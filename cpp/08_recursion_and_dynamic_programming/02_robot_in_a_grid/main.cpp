#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main(void)
{
	int r, c;
	cin >> r >> c;

	vector<vector<ll>> mat(r + 1, vector<ll>(c + 1, 0));
	mat[0][0] = 1;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = -INF;
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mat[i][j] > 0) {
				mat[i + 1][j] += mat[i][j];
				mat[i][j + 1] += mat[i][j];
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mat[i][j] < 0) cout << "na, ";
			else cout << mat[i][j] << ", ";
		}
		cout << endl;
	}

	cout << mat[r - 1][c - 1] << endl;
	return 0;
}
