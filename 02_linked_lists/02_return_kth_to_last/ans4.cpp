/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <cstdlib>
#include <iostream>
#include <list> 
#include <vector>

using namespace std;

int returnKthToLast(const list<int> &l, unsigned int k)
{
	auto itr = l.cbegin(), k_itr = l.cbegin();

	for (unsigned int i = 0; i < k + 1; ++i, ++k_itr) {
		if (k_itr == l.cend()) {
			cerr << endl << "invalid k value: " << k << endl; 
			exit(1);
		}
	}

	for (; k_itr != l.cend(); ++k_itr, ++itr) {}

	return *itr;
}

void showList(const list<int> &l)
{
	cout << "[ ";
	for (auto i : l)
		cout << i << " ";
	cout << "]" << endl;
}

int main(void)
{
	list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<unsigned int> inputs({3, 0, 9, 10});

	showList(l);
	for (auto i : inputs)
		cout << i << "-th: " << returnKthToLast(l, i) << endl;

	return 0;
}
