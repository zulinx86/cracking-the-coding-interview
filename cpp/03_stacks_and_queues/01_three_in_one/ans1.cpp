
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

		for (int i = 0; i < 3; ++i)
			_p[i] = i * n;
	}

	~ThreeStacksInSingleArray() {
		delete[] _arr;
	}

	void push(unsigned int i, T val)
	{
		if (i >= 3) {
			print_err_msg("invalid index", __func__);
			return;
		}

		if (_p[i] == (i + 1) * _n) {
			print_err_msg("stack overflow", __func__);
			return;
		}

		_arr[_p[i]] = val;
		_p[i]++;
	}

	T pop(unsigned int i)
	{
		if (i >= 3) {
			print_err_msg("invalid index", __func__);
			return T();
		}

		if (_p[i] == i * _n) {
			print_err_msg("stack underflow", __func__);
			return T();
		}
		
		_p[i]--;
		
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
	void print_err_msg(string msg, string func)
	{
		cerr << msg << " in ThreeStacksInSingleArray." << func << "()" << endl;
	}

	unsigned int _n;
	T *_arr;
	unsigned int _p[3];
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
