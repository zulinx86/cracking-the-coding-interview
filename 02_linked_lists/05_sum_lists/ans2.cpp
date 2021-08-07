/*
 * Support that the digits are stored in forward order and they are singly linked lists
 * N: the number of digits for the larger value
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

int subSumLists(
	forward_list<int>::const_iterator long_itr,
	forward_list<int>::const_iterator short_itr,
	int long_size,
	int short_size,
	forward_list<int> &ans)
{
	if (long_size == 0)
		return 0;

	int buf = *long_itr;
	if (long_size > short_size) {
		buf += subSumLists(++long_itr, short_itr, long_size - 1, short_size, ans);
	} else { /* long_size == short_size */
		buf += *short_itr;
		buf += subSumLists(++long_itr, ++short_itr, long_size - 1, short_size - 1, ans);
	}
	ans.push_front(buf % 10);
	return buf / 10;
}

forward_list<int> sumLists(const forward_list<int> &l1, const forward_list<int> &l2)
{
	forward_list<int> ans;
	int s1 = distance(l1.begin(), l1.end());
	int s2 = distance(l2.begin(), l2.end());

	int carry;
	if (s1 > s2)
		carry = subSumLists(l1.cbegin(), l2.cbegin(), s1, s2, ans);
	else
		carry = subSumLists(l2.cbegin(), l1.cbegin(), s2, s1, ans);

	if (carry)
		ans.push_front(carry);

	return ans;
}

void showList(const forward_list<int> &l)
{
	for (int i : l)
		cout << i;
}

int main(void)
{
	vector<pair<forward_list<int>, forward_list<int>>> inputs({
		{
			{6, 1, 7},
			{2, 9, 5},
		},
		{
			{6, 1, 7},
			{4, 1, 7}
		},
		{
			{3, 2, 0},
			{1, 2, 2, 6}
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
