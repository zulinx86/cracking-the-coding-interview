/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

void removeDups(list<int> &input)
{
	unordered_map<int, bool> htable;

	for (auto itr = input.begin(); itr != input.cend();) {
		if (htable.find(*itr) != htable.cend()) {
			itr = input.erase(itr);
		} else {
			htable[*itr] = true;
			++itr;
		}
	}
}

void showList(const list<int> &input)
{
	for (auto i : input)
		cout << i << " ";
	cout << endl;
}

int main(void)
{
	list<int> input{1, 2, 3, 2, 4, 5, 6, 2, 5, 6, 7};

	cout << "input : ";
	showList(input);
	
	removeDups(input);

	cout << "output: ";
	showList(input);

	return 0;
}
