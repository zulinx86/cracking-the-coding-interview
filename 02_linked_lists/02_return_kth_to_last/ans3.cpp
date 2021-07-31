/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <cstdlib>
#include <iostream>
#include <list> 
#include <vector>

using namespace std;

list<int>::const_iterator subReturnKthToLast(list<int>::const_iterator itr,
	const list<int>::const_iterator end, unsigned int k, int &cnt)
{
	if (itr == end)
		return end;

	auto i = subReturnKthToLast(++itr, end, k, cnt);
	--itr;

	++cnt;
	if (cnt == k)
		return itr;
	
	return i;
}

int returnKthToLast(const list<int> &l, unsigned int k)
{
	int cnt = -1;
	auto itr = subReturnKthToLast(l.cbegin(), l.cend(), k, cnt);
	if (itr == l.cend()) {
		cout << endl << "invalid k value: " << k << endl;
		exit(1);
	}
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
