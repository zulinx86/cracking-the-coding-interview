/*
 * Support that the type is singly linked list
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <forward_list>
#include <stack>

using namespace std;

bool palindrome(const forward_list<int> &l)
{
	auto fast = l.cbegin(), slow = l.cbegin();
	stack<int> s;

	do {
		if (++fast == l.cend()) {
			++slow;
			break;
		}

		s.push(*slow);
		++slow;
		++fast;
	} while (fast != l.cend());

	while (!s.empty()) {
		if (s.top() != *slow)
			return false;

		s.pop();
		++slow;
	}

	return true;
}

void showList(const forward_list<int> &l)
{
	for (int i : l)
		cout << i;
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
}
