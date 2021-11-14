#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum animal_type {
	dog,
	cat,
};

class animal_shelter {
public:
	animal_shelter() {}
	~animal_shelter() {}

	void enqueue(enum animal_type type)
	{
		switch (type) {
		case dog:
			cout << "dog(" << _id << ")" << endl;
			q_dog.push(_id++);
			break;
		case cat:
			cout << "cat(" << _id << ")" << endl;
			q_cat.push(_id++);
			break;
		default:
			break;
		}
	}

	int dequeueAny()
	{
		cout << "dequeueAny(): ";
		int ret;

		if (q_dog.empty() && q_cat.empty()) {
			cout << "empty" << endl;
			return -1;
		} else if (q_dog.empty()) {
			cout << "cat";
			ret = q_cat.front();
			q_cat.pop();
		} else if (q_cat.empty()) {
			cout << "dog";
			ret = q_dog.front();
			q_dog.pop();
		} else if (q_dog.front() < q_cat.front()) {
			cout << "dog";
			ret = q_dog.front();
			q_dog.pop();
		} else {
			cout << "cat";
			ret = q_cat.front();
			q_cat.pop();
		}
		cout << "(" << ret << ")" << endl;
		return ret;
	}

	int dequeueDog()
	{
		cout << "dequeueDog(): ";
		if (q_dog.empty()) {
			cout << "empty" << endl;
			return -1;
		}
		int ret = q_dog.front();
		q_dog.pop();
		cout << "dog(" << ret << ")" << endl;
		return ret;
	}

	int dequeueCat()
	{
		cout << "dequeueCat(): ";
		if (q_cat.empty()) {
			cout << "empty" << endl;
			return -1;
		}
		int ret = q_cat.front();
		q_cat.pop();
		cout << "cat(" << ret << ")" << endl;
		return ret;
	}

private:
	int _id = 0;
	queue<int> q_dog, q_cat;
};

int main(void)
{
	animal_shelter as;
	vector<enum animal_type> input({dog, cat, dog, dog, cat});

	for (enum animal_type i : input) {
		as.enqueue(i);
	}

	as.dequeueAny();
	as.dequeueAny();
	as.dequeueCat();
	as.dequeueCat();
	as.dequeueDog();
	as.dequeueAny();
	as.dequeueAny();

	return 0;
}
