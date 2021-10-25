#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> build_order(const vector<vector<int>> &edges)
{
	vector<int> order, num_edges;
	queue<int> q;
	int i, n;
	bool flag;

	n = edges.size();
	num_edges.resize(n);

	for (i = 0; i < n; ++i) {
		for (auto to : edges[i])
			++num_edges[to];
	}

	for (i = 0; i < n; ++i) {
		if (!num_edges[i])
			q.push(i);
	}

	while (!q.empty()) {
		int curr;

		curr = q.front();
		q.pop();
		order.push_back(curr);

		for (auto next : edges[curr]) {
			--num_edges[next];
			if (!num_edges[next])
				q.push(next);
		}
	}

	flag = true;
	for (i = 0; i < n; ++i) {
		if (num_edges[i])
			flag = false;
	}

	return flag ? order : vector<int>(1, {-1});
}

int main(void)
{
	vector<vector<int>> edges;
	vector<int> ans;
	int i, n, m;

	cin >> n >> m;

	edges.resize(n);
	for (i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
	}

	ans = build_order(edges);

	for (auto num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}
