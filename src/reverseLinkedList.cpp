/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *temp1 = head;
	struct node *temp2 = NULL;
	struct node *temp3 = NULL;
	if (head == NULL)
		return NULL;
	while (temp1 != NULL)
	{
		head = temp1;
		temp2 = temp1->next;
		temp1->next = temp3;
		temp3 = temp1;
		temp1 = temp2;
	}
	head= temp3;
	return head;

}
