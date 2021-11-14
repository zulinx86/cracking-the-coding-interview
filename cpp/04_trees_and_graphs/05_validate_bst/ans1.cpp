#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int val;
	struct node *left;
	struct node *right;
};

pair<int, int> __check_bst(struct node *n, bool &ans)
{
	pair<int, int> left_minmax, right_minmax, ret_minmax;

	// left
	if (n->left)
		left_minmax = __check_bst(n->left, ans);
	else
		left_minmax = make_pair(n->val, n->val);

	// right
	if (n->right)
		right_minmax = __check_bst(n->right, ans);
	else
		right_minmax = make_pair(n->val, n->val);

	// check
	if (n->val < left_minmax.second || right_minmax.first < n->val) 
		ans = false;

	cout << n->val << ": "
		<< "left (" << left_minmax.first << ", " << left_minmax.second << "), "
		<< "right (" << right_minmax.first << ", " << right_minmax.second << ")" << endl;

	ret_minmax.first = min(n->val, min(left_minmax.first, right_minmax.first));
	ret_minmax.second = max(n->val, max(left_minmax.second, right_minmax.second));

	return ret_minmax;
}

bool check_bst(struct node *n) {
	bool ans = true;
	__check_bst(n, ans);
	return ans;
}

int main(void)
{
	int n, i;

	cin >> n;

	vector<struct node> nodes(n);
	for (i = 0; i < n; ++i) {
		int v;
		cin >> v;

		if (v == -1) {
			int par = (i - 1) / 2;

			if (2 * par + 1 == i) {
				nodes[par].left = NULL;
			} else if (2 * par + 2 == i) {
				nodes[par].right = NULL;
			}
		} else {
			nodes[i].val = v;
			if (i < n / 2) {
				nodes[i].left = &nodes[2 * i + 1];
				nodes[i].right = &nodes[2 * i + 2];
			} else {
				nodes[i].left = NULL;
				nodes[i].right = NULL;
			}
		}
	}

	check_bst(&nodes[0], ans);

	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
