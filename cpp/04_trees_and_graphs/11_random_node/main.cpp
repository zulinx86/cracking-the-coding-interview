#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct node {
	int val;
	struct node *parent;
	struct node *left;
	struct node *right;
};

class binary_search_tree {
public:
	binary_search_tree(unsigned int n = 100) {
		_p = 0;
		_root = NULL;
		_v = vector<struct node>(n);

		random_device rnd;
		_mt = mt19937(rnd());
	}

	~binary_search_tree() {}

	void __show(struct node *n) {
		if (!n)
			return;

		__show(n->left);
		cout << n->val << " ";
		__show(n->right);
	}

	void show() {
		__show(_root);
		cout << endl;
	}

	void show_internal() {
		unsigned int i;

		for (i = 0; i < _p; ++i)
			cout << _v[i].val << " ";
		cout << endl;
	}

	void insert(int val) {
		struct node *n, *curr;

		n = init_node(val);

		if (_p == 1) {
			_root = n;
			return;
		}

		// Search a node to be the parent of `n`.
		curr = _root;
		while (curr) {
			if (curr->val == val) {
				_p--;
				return;
			} else if (val < curr->val) {
				if (!curr->left)
					break;

				curr = curr->left;
			} else {
				if (!curr->right)
					break;

				curr = curr->right;
			}
		}

		// Update links of `n` and `curr`.
		n->parent = curr;
		if (val < curr->val)
			curr->left = n;
		else
			curr->right = n;
	}

	void remove(struct node *n) {
		struct node *curr;
		unsigned int p;

		if (!n)
			return;

		p = n - &_v[0];

		if (!n->left && !n->right) {	// 1. No left, no right.
			if (n->parent) {	// 1.1. Parent exists.
				if (n->val < n->parent->val)
					n->parent->left = NULL;
				else
					n->parent->right = NULL;
			} else {		// 1.2. No parent.
				_root = NULL;
			}
		} else if (!n->left) {		// 2. No left, right exists.
			if (n->parent) {	// 2.1. Parent exists.
				if (n->right)
					n->right->parent = n->parent;

				if (n->val < n->parent->val)
					n->parent->left = n->right;
				else
					n->parent->right = n->right;
			} else {		// 2.2. No parent.
				_root = n->right;
			}
		} else {			// 3. Left exists.
			// Get the largest node (`curr`) within the left sub-tree of `n`.
			// To achieve this, go down until `curr` doesn't have the right node.
			curr = n->left;
			while (curr->right)
				curr = curr->right;

			if (n->left == curr) {	// 3.1. No nodes between `n` and `curr`
				n->left = curr->left;
				if (curr->left)
					curr->left->parent = n;
			} else {		// 3.2. Some nodes exist between `n` and `curr`
				curr->parent->right = curr->left;
				if (curr->left)
					curr->left->parent = curr->parent;
			}

			// `curr->val` is copied to `n->val` and `curr` will be deleted.
			n->val = curr->val;
			p = curr - &_v[0];
		}

		// Delete a node `_v[_p]` which is the last element of `_v`.
		_p--;
		_v[p] = _v[_p];

		if (_v[_p].parent) {
			if (_v[_p].val < _v[_p].parent->val)
				_v[_p].parent->left = &_v[p];
			else
				_v[_p].parent->right = &_v[p];
		}

		if (_v[_p].left)
			_v[_p].left->parent = &_v[p];

		if (_v[_p].right)
			_v[_p].right->parent = &_v[p];
	}

	struct node *find(int val) {
		return __find(_root, val);
	}

	struct node *get_random_node() {
		uniform_int_distribution<int> uni_rand(0, _p - 1);
		return &_v[uni_rand(_mt)];
	}

	unsigned int size() {
		return _p;
	}

private:
	struct node *init_node(int val) {
		if (_p == _v.size())
			_v.resize(2 * _v.size());

		_v[_p] = {
			.val = val,
			.parent = NULL,
			.left = NULL,
			.right = NULL
		};
		return &_v[_p++];
	}

	struct node *__find(struct node *n, int val) {
		if (!n)
			return NULL;

		if (n->val == val)
			return n;

		if (val < n->val)
			return __find(n->left, val);
		else
			return __find(n->right, val);
	}

	unsigned int _p;
	vector<struct node> _v;
	struct node *_root;
	mt19937 _mt;
};

int main(void)
{
	unsigned int i, n;
	cin >> n;

	binary_search_tree bst;

	for (i = 0; i < n; ++i) {
		unsigned int act, v, j;

		cin >> act >> v;

		cout << "===============" << endl;
		if (act == 0) { // insert
			cout << "insert  : " << v << endl;
			bst.insert(v);
		} else if (act == 1) { // remove
			cout << "remove  : " << v << endl;
			bst.remove(bst.find(v));
		}

		cout << "internal: ";
		bst.show_internal();

		cout << "traverse: ";
		bst.show();

		cout << "random  : ";
		for (j = 0; j < bst.size(); ++j)
			cout << bst.get_random_node()->val << " ";
		cout << endl;
	}

	return 0;
}
