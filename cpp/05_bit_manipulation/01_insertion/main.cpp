/*
 * Create a bit mask from i to j
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

#include <iostream>
#include <bitset>

using namespace std;

unsigned int insertion(unsigned int n, unsigned int m, unsigned int i, unsigned int j)
{
	int mask = (~0 << (1 + j)) | ((1 << i) - 1);
	return (n & mask) | (m << i);
}

int main(void)
{
	unsigned int n, m, i, j;
	cin >> n >> m >> i >> j;
	cout << "n: " << bitset<32>(n) << endl;
	cout << "m: " << bitset<32>(m) << endl;
	cout << "=  " << bitset<32>(insertion(n, m, i, j)) << endl;
	return 0;
}
