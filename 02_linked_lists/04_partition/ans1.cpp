/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void partition(list<int> &l, int part)
{
	auto front = l.begin(), back = --l.end();
	while (front != back) {
		while (*front < part && front != back)
			++front;

		while (*back >= part && back != front)
			--back;

		int buf = *front;
		*front = *back;
		*back = buf;
	}
}

void showList(const list<int> &l)
{
	for (auto i : l)
		cout << i << " ";
	cout << endl;
}

int main(void)
{
	vector<pair<list<int>, int>> inputs({
		{{3, 5, 8, 5, 10, 2, 1}, 5},
		{{3, 5, 8, 5, 10, 2, 1}, 3}
	});

	for (auto i : inputs) {
		showList(i.first);
		partition(i.first, i.second);
		showList(i.first);
	}

	return 0;
}
