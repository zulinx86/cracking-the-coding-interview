/*
 * N: the length of the given list
 * Time complexity: O(N^2)
 * Space complexity: O(1)
 */

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void removeDups(list<int> &input)
{
	auto i1 = input.cbegin();
	while (i1 != input.cend()) {
		auto i2 = next(i1);
		if (i2 == input.cend())
			break;

		while (i2 != input.cend()) {
			if (*i1 == *i2)
				input.erase(i2++);
			else
				++i2;
		}

		++i1;
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
