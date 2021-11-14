/*
 * N: the number of digits for the larger value
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> sumLists(const list<int> &l1, const list<int> &l2)
{
	list<int> ans;
	int carry = 0;
	auto i1 = l1.cbegin(), i2 = l2.cbegin();

	while (i1 != l1.cend() || i2 != l2.cend()) {
		int buf = carry;

		if (i1 != l1.cend()) {
			buf += *i1;
			++i1;
		}

		if (i2 != l2.cend()) {
			buf += *i2;
			++i2;
		}

		carry = buf / 10;
		ans.push_back(buf % 10);
	}

	if (carry != 0)
		ans.push_back(carry);

	return ans;
}

void showList(const list<int> &l)
{
	auto itr = l.cend();
	do {
		--itr;
		cout << *itr;
	} while (itr != l.begin());
}

int main(void)
{
	vector<pair<list<int>, list<int>>> inputs({
		{
			{7, 1, 6},
			{5, 9, 2},
		},
		{
			{7, 1, 6},
			{7, 1, 4}
		},
		{
			{0, 2, 3},
			{6, 2, 2, 1}
		}
	});

	for (auto i : inputs) {
		showList(i.first);
		cout << " + ";
		showList(i.second);
		cout << " = ";
		showList(sumLists(i.first, i.second));
		cout << endl;
	}

	return 0;
}
