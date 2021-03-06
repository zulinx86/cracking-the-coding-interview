
#include <iostream>
#include <string>

using namespace std;

template <class T>
class ThreeStacksInSingleArray
{
public:
	ThreeStacksInSingleArray()
	{
		ThreeStacksInSingleArray(100);
	}

	ThreeStacksInSingleArray(unsigned int n)
	{
		_n = n;
		_arr = new T[3 * n];

		for (int i = 0; i < 3; ++i) {
			_p[i] = i * n;
			_s[i] = i * n;
		}
	}

	~ThreeStacksInSingleArray() {
		delete[] _arr;
	}

	void push(unsigned int i, T val)
	{
		unsigned int next = (i + 1) % 3;

		if (i >= 3) {
			print_err_msg("invalid index", __func__);
			return;
		}

		if (_p[i] == _s[next]) {
			if (!move(next, next)) {
				print_err_msg("stack overflow", __func__);
				return;
			}
		}

		_arr[_p[i]] = val;
		_p[i] = inc(_p[i]);
	}

	T pop(unsigned int i)
	{
		if (i >= 3) {
			print_err_msg("invalid index", __func__);
			return T();
		}

		if (_p[i] == _s[i]) {
			print_err_msg("stack underflow", __func__);
			return T();
		}

		_p[i] = dec(_p[i]);

		T ans = _arr[_p[i]];
		_arr[_p[i]] = T();
		return ans;
	}

	void debug(void)
	{
		for (unsigned int i = 0; i < 3 * _n; ++i)
			cout << _arr[i] << " ";
		cout << endl;
	}

private:
	inline unsigned int inc(unsigned int p)
	{
		return (p + 1) % (3 * _n);
	}

	inline unsigned int dec(unsigned int p)
	{
		if (p == 0)
			return 3 * _n - 1;
		else
			return p - 1;
	}

	inline unsigned int add(unsigned int p1, unsigned int p2)
	{
		unsigned int ans = p1 + p2;
		if (ans >= 3 * _n)
			return ans % (3 * _n);
		else
			return ans;
	}

	inline unsigned int sub(unsigned int p1, unsigned int p2)
	{
		if (p1 >= p2)
			return p1 - p2;
		else
			return (p1 + 3 * _n) - p2;
	}

	bool move(unsigned int i, unsigned int start)
	{
		unsigned int next = (i + 1) % 3;

		if (_p[i] == _s[next]) {
			if ((next + 1) % 3 == start)
				return false;

			if (!move(next, start))
				return false;
		}

		unsigned int d = (sub(_s[next], dec(_p[i])) + 1) / 2;

		for (unsigned int p = dec(_p[i]); p != dec(_s[i]); p = dec(p)) {
			_arr[add(p, d)] = _arr[p];
			_arr[p] = 0;
		}

		_s[i] = add(_s[i], d);
		_p[i] = add(_p[i], d);
		return true;
	}

	void print_err_msg(string msg, string func)
	{
		cerr << msg << " in ThreeStacksInSingleArray." << func << "()" << endl;
	}

	unsigned int _n;
	T *_arr;
	unsigned int _p[3];
	unsigned int _s[3];
};

int main(void)
{
	int size;
	cout << "input the size of stacks: ";
	cin >> size;

	ThreeStacksInSingleArray<int> stacks(size);

	int a, i;
	while (1) {
		cout << endl << "select action (0 => push, 1 => pop): ";
		cin >> a;

		cout << "select stack: ";
		cin >> i;

		if (a == 0) { // push
			stacks.push(i, i + 1);
		} else if (a == 1) { // pop
			cout << "poped value is " << stacks.pop(i) << endl;
		} else {
			cout << "invalid action" << endl;
		}

		cout << "debug: ";
		stacks.debug();
	}
}
