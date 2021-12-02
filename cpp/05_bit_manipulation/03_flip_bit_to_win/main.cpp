#include <iostream>
#include <bitset>

using namespace std;

int get_next_zero_pos(int i, int x) {
	while (x >> i) {
		if (!((x >> i) & 1)) {
			return i;
		}
		++i;
	}

	return i;
}

int flip_bit_to_win(int x) {
	int fast = 0, slow = -1, ans = 0;

	fast = get_next_zero_pos(fast, x);

	ans = fast;
	while ((1 << fast) <= x) {
		fast = get_next_zero_pos(fast + 1, x);

		if (fast - slow - 1 > ans)
			ans = fast - slow - 1;

		slow = get_next_zero_pos(slow + 1, x);
	}

	return ans;
}

int main(void)
{
	int x;
	cin >> x;

	cout << bitset<32>(x) << endl;
	cout << flip_bit_to_win(x) << endl;
	return 0;
}
