#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class CircularArray;

template <typename T>
class CircularArrayIterator {
public:
	CircularArrayIterator(CircularArray<T> *arr, int i) : _arr(arr), _i(i) {}

	CircularArrayIterator &operator++() {
		++_i;
		return *this;
	}

	T &operator*() {
		return _arr->get(_i);
	}

	bool operator!=(const CircularArrayIterator &rhs) {
		return _i != rhs._i;
	}

private:
	CircularArray<T> *_arr;
	int _i;
};

template <typename T>
class CircularArray {
public:
	CircularArray(unsigned int n) : _v(vector<T>(n)), _n(n), _i(0) {}

	void rotate(int m = 1) {
		_i = (((_i + m) % _n) + _n) % _n;
	}

	T &get(unsigned int idx) {
		return _v[(_i + idx) % _n];
	}

	void set(unsigned int idx, T val) {
		_v[(_i + idx) % _n] = val;
	}

	unsigned int size(void) const {
		return _n;
	}

	CircularArrayIterator<T> begin() {
		return CircularArrayIterator<T>(this, 0);
	}

	CircularArrayIterator<T> end() {
		return CircularArrayIterator<T>(this, _n);
	}

private:
	vector<T> _v;
	int _n;
	int _i;
};

int main(void)
{
	int n = 10;
	CircularArray<int> ca(n);

	for (int i = 0; i < n; ++i)
		ca.set(i, i);

	ca.rotate(-2);

	cout << "=== use iterator ===" << endl;
	for (CircularArrayIterator<int> it = ca.begin(); it != ca.end(); ++it) {
		cout << *it << endl;
	}

	cout << "=== range-based for ===" << endl;
	for (int i : ca) {
		cout << i << endl;
	}

	return 0;
}
