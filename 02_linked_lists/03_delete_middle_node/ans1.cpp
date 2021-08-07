/*
 * Space complexity: O(1)
 * Time complexity: O(1)
 */

#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void deleteMiddleNode(struct Node *n) {
	struct Node *next = n->next;
	n->data = next->data;
	n->next = next->next;
	delete next;
}

void showList(struct Node *n) {
	cout << "[ ";
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << "]" << endl;
}

int main(void)
{
	struct Node *head = NULL, *tail = NULL;
	for (int i = 0; i < 10; ++i) {
		struct Node *n = new struct Node;
		n->data = i;
		n->next = NULL;

		if (head == NULL)
			head = n;
		else
			tail->next = n;

		tail = n;
	}

	cout << "input:" << endl;
	showList(head);

	deleteMiddleNode(head->next->next);

	cout << "output:" << endl;
	showList(head);

	return 0;
}
