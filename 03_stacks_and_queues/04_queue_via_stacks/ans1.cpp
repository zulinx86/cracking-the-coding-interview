#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class queue_via_stacks {
public:
	queue_via_stacks() {}
	~queue_via_stacks() {}

	void push(T val) {
		s_new.push(val);
	}

	void pop() {
		if (s_old.empty())
			shift();
		
		if (s_old.empty())
			return;

		s_old.pop();
	}

	T top() {
		if (s_old.empty())
			shift();

		if (s_old.empty())
			return -1;

		return s_old.top();
	}

private:
	void shift() {
		while(!s_new.empty()) {
			s_old.push(s_new.top());
			s_new.pop();
		}
	}

	stack<T> s_new, s_old;
};

int main(void)
{
	queue_via_stacks<int> qvs;

	while (1) {
		int op, val;

		cout << "push(0)? pop(1)? > ";
		cin >> op;

		if (op == 0) {
			cout << "value? > ";
			cin >> val;
			qvs.push(val);
		} else if (op == 1) {
			cout << "popped value : " << qvs.top() << endl;
			qvs.pop();
		}
	}

	return 0;
}
