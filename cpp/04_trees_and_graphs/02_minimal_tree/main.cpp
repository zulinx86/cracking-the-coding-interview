#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

struct node *__minimal_tree(struct node *np, int left, int right)
{
	cout << left << ", " << right << endl;

	if (left == right)
		return NULL;
	else if (left + 1 == right)
		return &np[left];

	int mid = (left + right) / 2;
	np[mid].left = __minimal_tree(np, left, mid);
	np[mid].right = __minimal_tree(np, mid + 1, right);
	return &np[mid];
}

struct node *minimal_tree(vector<int> &arr)
{
	int size = arr.size();

	struct node *np = new struct node[size];
	for (int i = 0; i < size; ++i) {
		np[i].value = arr[i];
		np[i].left = NULL;
		np[i].right = NULL;
	}

	return __minimal_tree(np, 0, size);
}

void display_bst(struct node *n)
{
	queue<struct node *> q;
	q.push(n);

	int cnt = 0, newline = 2;
	while (!q.empty()) {
		n = q.front();
		q.pop();

		if (!n)
			continue;

		++cnt;
		cout << n->value;
		if (cnt == newline - 1) {
			cout << endl;
			newline *= 2;
		} else {
			cout << " ";
		}

		q.push(n->left);
		q.push(n->right);
	}
}

void free_bst(struct node *n)
{
	if (!n)
		return;

	free_bst(n->left);
	free_bst(n->right);

	delete n;
}

int main(void)
{
	int n; // the number of items
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		arr[i] = i;

	struct node *head = minimal_tree(arr);

	display_bst(head);

	free_bst(head);
	return 0;
}
