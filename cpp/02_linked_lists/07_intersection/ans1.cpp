/*
 * M, N: the length of the given two lists
 * Time complexity: O(M + N)
 * Space complexity: O(1)
 */

#include <iostream>

using namespace std;

struct node {
	struct node *next;
	int val;
};

struct node *intersection(struct node *h1, struct node *h2)
{
	struct node *n1 = h1, *n2 = h2;
	int l1 = 0, l2 = 0, diff;

	while (n1->next != NULL) {
		++l1;
		n1 = n1->next;
	}
	
	while (n2->next != NULL) {
		++l2;
		n2 = n2->next;
	}

	if (n1 != n2)
		return NULL;

	if (l1 >= l2) {
		diff = l1 - l2;
		n1 = h1;
		n2 = h2;
	} else {
		diff = l2 - l1;
		n1 = h2;
		n2 = h1;
	}

	while (diff--)
		n1 = n1->next;

	while (n1 != n2) {
		n1 = n1->next;
		n2 = n2->next;
	}

	return n1;
}

void showList(struct node *n)
{
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

int main(void)
{
	struct node nodes[10];
	struct node *ans;
	
	/*
	 * 0 -> 1 -> 2 -> 3 \
	 *                   -> 7 -> 8 -> 9
	 *      4 -> 5 -> 6 /
	 */
	for (int i = 0; i < 10; ++i) {
		nodes[i].val = i;
		if (i == 9)
			nodes[i].next = NULL;
		else
			nodes[i].next = &nodes[i + 1];
	}
	nodes[3].next = &nodes[7];

	cout << "list #1: ";
	showList(&nodes[0]);

	cout << "list #2: ";
	showList(&nodes[4]);

	ans = intersection(&nodes[0], &nodes[4]);
	cout << "answer: ";
	if (ans != NULL)
		cout << ans->val << endl;
	else
		cout << "none" << endl;

	/*
	 * 0 -> 1 -> 2 -> 3 -> 4
	 * 5 -> 6 -> 7 -> 8 -> 9
	 */
	for (int i = 0; i < 10; ++i) {
		if (i == 9)
			nodes[i].next = NULL;
		else
			nodes[i].next = &nodes[i + 1];
	}
	nodes[4].next = NULL;

	cout << "list #1: ";
	showList(&nodes[0]);

	cout << "list #2: ";
	showList(&nodes[5]);

	ans = intersection(&nodes[0], &nodes[5]);
	cout << "answer: ";
	if (ans != NULL)
		cout << ans->val << endl;
	else
		cout << "none" << endl;


	return 0;
}
