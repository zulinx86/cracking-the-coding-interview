#include <iostream>
#include <stack>
#include <random>

using namespace std;

template <class T>
class StackWithMin {
public:
	StackWithMin() {}
	~StackWithMin() {}
	
	void push(T val) {
		if (_s.size() == 0) {
			_s.push(make_pair(val, val));
		} else {
			T minval = std::min(_s.top().second, val);
			_s.push(make_pair(val, minval));
		}
	}

	T pop(void) {
		T val = _s.top().first;
		_s.pop();
		return val;
	}

	T min(void) {
		return _s.top().second;
	}

private:
	stack<pair<T, T>> _s;
};

int main(void)
{
	random_device seed_gen;
	default_random_engine engine(seed_gen());

	uniform_int_distribution<> dist(0, 9);

	StackWithMin<int> s;
	cout << "input" << endl;
	for (int i = 0; i < 10; ++i) {
		int v = dist(engine);
		s.push(v);
		cout << v << " " << s.min() << endl;
	}

	cout << "output" << endl;
	for (int i = 0; i < 9; ++i) {
		cout << s.pop() << " " << s.min() << endl;
	}
	cout << s.pop() << endl;

	return 0;
}
