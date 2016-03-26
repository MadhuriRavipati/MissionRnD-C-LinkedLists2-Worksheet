/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	int j = 1;
	if (head == NULL)
		return NULL;
	if (K == 0)
		return head;
	struct node *ptr, *preptr, *x;
	ptr = head->next;
	preptr = head;
	while (ptr != NULL){
		if (j % K == 0)
		{
			x = (struct node *)malloc(sizeof(struct node));
			x->num = K;
			preptr->next = x;
			x->next = ptr;
			j = 0;
		}

		j++;
		preptr = ptr;
		ptr = ptr->next;

	}
	if (K == 1)
	{
		x = (struct node *)malloc(sizeof(struct node));
		x->num = K;
		preptr->next = x;
		x->next = NULL;
	}

	return head;


	//return NULL;
}
