/*
 * Subtract 2^(-n) from the given value repeatedly where n = [0, 32).
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

void binary_to_string(double v)
{
	string ans;
	double x = 1.0;
	for (int i = 0; i < 32; ++i) {
		if (v >= x) {
			ans += '1';
			v -= x;
		} else {
			ans += '0';
		}
		x /= 2.0;
	}

	if (v > 0.0) cout << "ERROR" << endl;
	else cout << ans << endl;
}

int main(void)
{
	double d;
	cin >> d;
	binary_to_string(d);
	return 0;
}
