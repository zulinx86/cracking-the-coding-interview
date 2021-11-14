/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void partition(list<int> &l, int pivot)
{
	for (auto itr = l.begin(); itr != l.cend();) {
		if (*itr < pivot) {
			l.push_front(*itr);
			itr = l.erase(itr);
		} else {
			++itr;
		}
	}
}

void showList(const list<int> &l)
{
	for (int i : l)
		cout << i << " ";
	cout << endl;
}

int main(void)
{
	vector<pair<list<int>, int>> inputs({
		{{3, 5, 8, 5, 10, 2, 1}, 5},
		{{3, 5, 8, 5, 10, 2, 1}, 8}
	});

	for (auto i : inputs) {
		cout << "input: ";
		showList(i.first);
		cout << "pivot: " << i.second << endl;

		partition(i.first, i.second);

		cout << "output: ";
		showList(i.first);
	}

	return 0;
}
