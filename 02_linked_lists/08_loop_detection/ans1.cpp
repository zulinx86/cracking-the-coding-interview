/*
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct node {
	struct node *next;
	int val;
};

struct node *loopDetection(struct node *head) {
	unordered_map<struct node *, bool> ht;
	while (head) {
		if (ht.find(head) != ht.end())
			break;
		ht[head] = true;
		head = head->next;
	}
	return head;
}

int main(void)
{
	struct node nodes[10];
	for (int i = 0; i < 10; ++i) {
		nodes[i].val = i;
		if (i != 9)
			nodes[i].next = &nodes[i + 1];
	}
	
	nodes[9].next = &nodes[3];
	cout << "0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9\n"
	     << "               ^                             |\n"
	     << "               +-----------------------------+\n"
	     << "answer: " << loopDetection(&nodes[0])->val << endl << endl;
	

	nodes[9].next = &nodes[4];
	cout << "0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9\n"
	     << "                    ^                        |\n"
	     << "                    +------------------------+\n"
	     << "answer: " << loopDetection(&nodes[0])->val << endl << endl;

	return 0;
}
