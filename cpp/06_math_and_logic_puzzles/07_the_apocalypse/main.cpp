#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> apocalypse_each(void) {
	vector<int> child(2, 0); // 0: boy, 1: girl

	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rand(0, 1);
	for (;;) {
		int i = rand(mt);
		if (i == 0) {
			child[0]++;
		} else if (i == 1) {
			child[1]++;
			break;
		}
	}

	return child;
}

double apocalypse(int n) {
	vector<int> child(2, 0); // 0: boy, 1: girl

	for (int i = 0; i < n; ++i) {
		vector<int> c = apocalypse_each();
		child[0] += c[0];
		child[1] += c[1];
	}

	return (double)(child[1]) / (double)(child[0] + child[1]);
}

int main(void)
{
	int n;
	cin >> n;
	cout << apocalypse(n) << endl;
	return 0;
}
