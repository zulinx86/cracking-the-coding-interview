#include <iostream>

using namespace std;

template <typename T>
class stack {
public:
	stack(int n) : _n(n)
	{
		_arr = new T[_n];
		for (int i = 0; i < _n; ++i)
			_arr[i] = -1;
	}

	~stack()
	{
		delete _arr;
	}

	void push(T val)
	{
		if (_i != _n)
			_arr[_i++] = val;
	}

	void pop()
	{
		if (_i != 0)
			_arr[--_i] = -1;
	}

	T top()
	{
		return _arr[_i - 1];
	}

	bool is_full()
	{
		return _i == _n;
	}

	bool is_empty()
	{
		return _i == 0;
	}

	void show()
	{
		for (int i = _n - 1; i >= 0; --i)
			cout << _arr[i] << " ";
		cout << endl;
	}

private:
	int _n;
	T *_arr;
	int _i = 0;
};

template <typename T>
class linked_stack {
public:
	linked_stack(int n, linked_stack<T> *prev): _n(n), _prev(prev)
	{
		_s = new stack<T>(_n);
	}

	~linked_stack()
	{
		delete _s;
	}

	linked_stack<T> *get_prev()
	{
		return _prev;
	}

	void push(T val)
	{
		_s->push(val);
	}

	void pop()
	{
		_s->pop();
	}

	T top()
	{
		return _s->top();
	}

	bool is_full()
	{
		return _s->is_full();
	}

	bool is_empty()
	{
		return _s->is_empty();
	}

	void show()
	{
		_s->show();
	}

private:
	int _n;
	linked_stack<T> *_prev;
	stack<T> *_s;
};

template <typename T>
class set_of_stacks {
public:
	set_of_stacks(int n) : _n(n)
	{
		_ls = new linked_stack<T>(_n, NULL);
	}

	~set_of_stacks()
	{
		while (_ls) {
			linked_stack<T> *tmp = _ls;
			_ls = _ls->get_prev();
			delete tmp;
		}
	}

	void push(T val)
	{
		if (_ls->is_full()) {
			_ls = new linked_stack<T>(_n, _ls);
		}

		_ls->push(val);
	}

	void pop(void)
	{
		_ls->pop();
		if (_ls->is_empty()) {
			if (_ls->get_prev() != NULL) {
				linked_stack<T> *tmp = _ls;
				_ls = _ls->get_prev();
				delete tmp;
			}
		}
	}

	T top(void)
	{
		return _ls->top();
	}

	void show(void)
	{
		linked_stack<T> *tmp = _ls;
		while (tmp) {
			tmp->show();
			tmp = tmp->get_prev();
		}
	}

private:
	int _n;
	linked_stack<T> *_ls;
};


int main(void)
{
	set_of_stacks<int> test(4);

	int op;
	int val;
	while (1) {
		cout << "push(0)? pop(1)? > ";
		cin >> op;

		if (op == 0) {
			cout << "val? > ";
			cin >> val;
			test.push(val);
		} else {
			test.pop();
		}

		test.show();
	}
		

	return 0;
}
