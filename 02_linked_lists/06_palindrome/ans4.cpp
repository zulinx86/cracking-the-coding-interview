/*
 * Support that the type is singly linked list
 * N: the length of the given list
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <stdio.h>

#define SIZE 11

struct node {
	struct node *next;
	int val;
};

int palindrome(struct node **forward, struct node *backward)
{
	int ret;

	if (backward == NULL)
		return -1;

	ret = palindrome(forward, backward->next);
	if (ret != -1)
		return ret;

	if (*forward == backward || (*forward)->next == backward)
		return 1;

	if ((*forward)->val != backward->val)
		return 0;

	*forward = (*forward)->next;

	return -1;
}

int main(void)
{
	struct node nodes[SIZE];
	struct node *np;
	int i;

	for (i = 1; i < SIZE; i++)
		nodes[i - 1].next = &nodes[i];
	nodes[SIZE - 1].next = NULL;

	for (i = 0; i < (SIZE + 1) / 2; i++) {
		nodes[i].val = i;
		nodes[SIZE - 1 - i].val = i;
	}

	np = &nodes[0];
	while (np) {
		printf("%d ", np->val);
		np = np->next;
	}

	printf("\n");

	np = &nodes[0];
	printf("%d\n", palindrome(&np, np));

	return 0;
}
