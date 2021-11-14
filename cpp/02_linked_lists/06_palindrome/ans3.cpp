/*
 * Support that the type is singly linked list
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

bool palindromeSub(
	forward_list<int>::const_iterator &forward,
	forward_list<int>::const_iterator backward)
{
	if (backward._M_node == 0)
		return true;

	forward_list<int>::const_iterator tmp = backward;
	bool ret = palindromeSub(forward, ++tmp);

	if (!ret)
		return false;

	if (*forward != *backward)
		return false;

	++forward;

	return true;
}

bool palindrome(const forward_list<int> &l)
{
	forward_list<int>::const_iterator head = l.cbegin();

	bool ret = palindromeSub(head, head);

	return ret;
}

void showList(const forward_list<int> &l)
{
	for (auto i : l)
		cout << i;
	return;
}

int main(void)
{
	vector<forward_list<int>> inputs({
		{1, 2, 3, 2, 1},
		{1, 2, 3, 3, 1},
		{1, 2, 3, 3, 2, 1},
		{1, 2, 3, 4, 2, 1}
	});

	for (auto i : inputs) {
		showList(i);
		cout << ": " << palindrome(i) << endl;
	}
	
	return 0;
}
