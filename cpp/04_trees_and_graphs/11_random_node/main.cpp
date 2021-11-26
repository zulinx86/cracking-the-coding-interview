#include <iostream>
#include <vector>
#include <random>
#include <map>

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

		for (i = 0; i < _v.size(); ++i)
			cout << _v[i]->val << " ";
		cout << endl;
	}

	void insert(int val) {
		struct node *n, *curr;

		if (_v.size() == 0) {
			n = init_node(val);
			_root = n;
			return;
		}

		// Search a node to be the parent of `n`.
		curr = _root;
		while (curr) {
			if (curr->val == val) {
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

		// insert a new node as a child of `curr`.
		insert_node(curr, init_node(val));
	}

	void remove(struct node *n) {
		if (!n)
			return;

		// Update links.
		if (!n->left) {			// 1. No left.
			if (n->parent) {	// 1.1. Parent exists.
				if (n->val < n->parent->val)
					n->parent->left = n->right;
				else
					n->parent->right = n->right;
			} else {		// 1.2. No parent.
				_root = n->right;
			}
		} else {			// 2. Left exists.
			// Get the largest node (`curr`) within the left sub-tree of `n`.
			// To achieve this, go down until `curr` doesn't have the right node.
			struct node *curr = n->left;
			while (curr->right)
				curr = curr->right;

			if (n->left != curr) { // 2.1. Some nodes exist between `n` and `curr`.
				curr->parent->right = curr->left;
				if (curr->left)
					curr->left->parent = curr->parent;
			} else {		// 2.2. `n` and `curr` are connected directly.
				n->left = curr->left;
				if (curr->left)
					curr->left->parent = n;
			}

			// `curr->val` is copied to `n->val` and `curr` will be deleted.
			n->val = curr->val;
			n = curr;
		}

		// Remove `n` from `_v`.
		if (n != _v.back()) {
			int pos = _mp[n];
			_v[pos] = _v.back();
			_mp[_v[pos]] = pos;
		}
		_mp.erase(n);
		delete n;
		_v.pop_back();
	}

	struct node *find(int val) {
		return __find(_root, val);
	}

	struct node *get_random_node() {
		uniform_int_distribution<int> uni_rand(0, _v.size() - 1);
		return _v[uni_rand(_mt)];
	}

private:
	struct node *init_node(int val) {
		struct node *n = new struct node;
		n->val = val;
		n->parent = NULL;
		n->left = NULL;
		n->right = NULL;

		_mp[n] = _v.size();
		_v.push_back(n);
		return n;
	}

	void insert_node(struct node *parent, struct node *n) {
		n->parent = parent;
		if (n->val < parent->val)
			parent->left = n;
		else
			parent->right = n;
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

	vector<struct node *> _v;
	map<struct node *, unsigned int> _mp;
	struct node *_root = NULL;
	mt19937 _mt;
};

int main(void)
{
	unsigned int i, n;
	cin >> n;

	binary_search_tree bst;

	for (i = 0; i < n; ++i) {
		unsigned int act, v;

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

		cout << "random  : " << bst.get_random_node()->val << endl;
	}

	return 0;
}
