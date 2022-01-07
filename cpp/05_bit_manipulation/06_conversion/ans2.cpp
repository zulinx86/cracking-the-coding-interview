#include <iostream>
#include <bitset>

using namespace std;

int conversion(int x, int y) {
	unsigned int mask[5] = {
		0xaaaaaaaa,
		0xcccccccc,
		0xf0f0f0f0,
		0xff00ff00,
		0xffff0000,
	};

	x = x ^ y;
	for (int i = 0; i < 5; ++i)
		x = ((x & mask[i]) >> (1 << i)) + (x & (mask[i] >> (1 << i)));

	return x;
}

int main(void)
{
	int x, y;
	cin >> x >> y;

	cout << "x: " << bitset<32>(x) << endl;
	cout << "y: " << bitset<32>(y) << endl;
	cout << "ans: " << conversion(x, y) << endl;
	return 0;
}
