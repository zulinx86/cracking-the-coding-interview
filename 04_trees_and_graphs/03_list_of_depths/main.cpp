#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct node {
	struct node *left;
	struct node *right;
	int val;
};

void list_of_depths(struct node *n, int level,
		    vector<list<struct node *>> &ans)
{
	if (n == NULL)
		return;

	if (ans.size() == level)
		ans.push_back(list<struct node *>());
	
	ans[level].push_back(n);
	list_of_depths(n->left, level + 1, ans);
	list_of_depths(n->right, level + 1, ans);
}

void print_list_of_depths(vector<list<struct node *>> &ans)
{
	int i;
	struct node *n;

	for (i = 0; i < ans.size(); ++i) {
		for (n : ans[i]) {
			cout << n->val << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	int n, i;
	vector<struct node> a;
	vector<list<struct node *>> ans;

	cin >> n;

	a.resize(n);
	for (i = 0; i < n; ++i) {
		int val;
		cin >> val;

		if (val == -1) {
			int p = (i - 1) / 2;
			if (2 * p + 1 == i)
				a[p].left = NULL;
			else
				a[p].right = NULL;
			continue;
		}

		a[i].val = val;
		if (2 * i + 2 < n) {
			a[i].left = &a[2 * i + 1];
			a[i].right = &a[2 * i + 2];
		} else {
			a[i].left = NULL;
			a[i].right = NULL;
		}
	}
	
	list_of_depths(&a[0], 0, ans);

	print_list_of_depths(ans);
	return 0;
}
