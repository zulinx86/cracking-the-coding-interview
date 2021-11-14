/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool palindrome(const list<int> &l)
{
	auto front = l.cbegin(), back = --l.cend();

	while (front != back) {
		if (*front != *back)
			return false;

		++front;
		if (front == back)
			break;
		--back;
	}

	return true;
}

void showList(const list<int> &l)
{
	for (int i : l)
		cout << i;
}

int main(void)
{
	vector<list<int>> inputs({
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
