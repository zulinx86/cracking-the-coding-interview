#include <iostream>
#include <bitset>

using namespace std;

unsigned int pairwise_swap(unsigned int x)
{
	unsigned int mask1 = 0xaaaaaaaa;
	unsigned int mask2 = 0x55555555;
	return ((x & mask2) << 1) | ((x & mask1) >> 1);
}

int main(void)
{
	unsigned int x;
	cin >> x;

	cout << "input:  " << bitset<32>(x) << endl;
	cout << "output: " << bitset<32>(pairwise_swap(x)) << endl;
	return 0;
}
