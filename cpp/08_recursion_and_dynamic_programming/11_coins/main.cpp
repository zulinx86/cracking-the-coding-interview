#include <iostream>
#include <vector>

using namespace std;

void show(const vector<vector<int>> &dp) {
	for (int i = 0; i < dp.size(); ++i) {
		for (int j = 0; j < dp[i].size(); ++i) {
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}
}

int main(void)
{
	int n;
	cin >> n;

	vector<int> coins = {1, 5, 10, 25};
	vector<int> dp(n + 1);
	dp[0] = 1;

	for (int i = 0; i < coins.size(); ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j + coins[i] > n) continue;
			dp[j + coins[i]] += dp[j];
		}
	}

	cout << dp[n] << endl;
	return 0;
}
