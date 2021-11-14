#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool route_between_nodes(vector<vector<int>> &graph, int from, int to)
{
	vector<bool> seen(graph.size(), false);
	queue<int> q;

	seen[from] = true;
	q.push(from);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto next : graph[curr]) {
			if (next == to)
				return true;

			if (seen[next])
				continue;

			seen[next] = true;
			q.push(next);
		}
	}

	return false;
}

int main(void)
{
	int n, m; // n: the number of nodes, m: the number of edges
	cin >> n >> m;

	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b; // a -> b
		cin >> a >> b;
		graph[a].push_back(b);
	}

	int from, to;
	cin >> from >> to;

	cout << route_between_nodes(graph, from, to) << endl;
	return 0;
}
