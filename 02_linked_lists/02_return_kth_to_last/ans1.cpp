/*
 * Support that you know the length of the given list
 *
 * N: the length of the given list
 * Time complexity: O(N - k)
 * Space complexity: O(1)
 */

#include <cstdlib>
#include <iostream>
#include <list> 
#include <vector>

using namespace std;

int returnKthToLast(const list<int> &l, unsigned int k)
{
	if (k >= l.size()) {
		cerr << endl << "invalid k value: " << k << endl;
		exit(1);
	}

	unsigned int last_k = l.size() - k - 1;
	auto itr = l.cbegin();

	for (unsigned int i = 0; i < last_k; ++i, ++itr) {}

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
