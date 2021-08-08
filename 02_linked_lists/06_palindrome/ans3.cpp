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
	_Fwd_list_node_base **forward,
	_Fwd_list_node_base *backward)
{
	if (backward == 0)
		return true;
	
	bool ret = palindromeSub(
		forward,
		backward->_M_next
	);

	if (!ret)
		return false;

	int fval = *(static_cast<_Fwd_list_node<int> *>(*forward)->_M_valptr());
	int bval = *(static_cast<_Fwd_list_node<int> *>(backward)->_M_valptr());

	if (fval != bval)
		return false;
	
	*forward = (*forward)->_M_next;

	return true;
}


bool palindrome(forward_list<int> &l)
{
	bool ret = palindromeSub(
		&(l.begin()._M_node),
		l.begin()._M_node
	);

	return ret;
}

void showList(const _Fwd_list_node<int> *node)
{
	while (node != 0) {
		cout << *(node->_M_valptr());
		node = static_cast<const _Fwd_list_node<int> *>(node->_M_next);
	}
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
		showList(static_cast<const _Fwd_list_node<int> *>(i.cbegin()._M_node));
		cout << ": " << palindrome(i) << endl;
	}
	
	return 0;
}
