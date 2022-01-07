#include <iostream>
#include <bitset>

using namespace std;

int conversion(int x, int y) {
	int cnt = 0;

	for (int z = x ^ y; z > 0; z &= z - 1)
		++cnt;

	return cnt;
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
