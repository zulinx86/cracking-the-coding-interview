#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void sort_stack(stack<int> &s) {
	stack<int> tmp;

	while (!s.empty()) {
		int a = s.top();
		s.pop();

		while (!tmp.empty() && tmp.top() > a) {
			int b = tmp.top();
			tmp.pop();
			s.push(b);
		}

		tmp.push(a);
		while (!s.empty() && tmp.top() < s.top()) {
			tmp.push(s.top());
			s.pop();
		}
	}

	while (!tmp.empty()) {
		s.push(tmp.top());
		tmp.pop();
	}
}

int main(void)
{
	stack<int> s;

	vector<int> v({3, 6, 12, 3, 5, 7, 4, 1});
	for (int a : v) {
		cout << a << " ";
		s.push(a);
	}
	cout << endl;

	sort_stack(s);

	while (s.size()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	return 0;
}
