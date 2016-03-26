/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node *construct(int data,struct node *start)
{
	struct node *ptr, *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->num = data;
	if (start == NULL)
	{
		newnode->next = NULL;
		start = newnode;
	}
	else
	{
		ptr = start;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->next = NULL;
		newnode = start;
	}
	return start;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	int val;
	struct node *start = NULL, *ptr1, *ptr2, *preptr;
	ptr1 = head1;
	ptr2 = head2;
	while (ptr1 != NULL && ptr2 != NULL)
	{
		if (ptr1->num < ptr2->num)
		{
			start = construct(ptr1->num, start);
			ptr1 = ptr1->next;
		}
		else
		{
			start = construct(ptr2->num, start);
			ptr2 = ptr2->next;
		}
	}
	while (ptr1 != NULL)
	{
		start = construct(ptr1->num, start);
		ptr1 = ptr1->next;
	}
	while (ptr2 != NULL)
	{
		start = construct(ptr2->num, start);
		ptr2 = ptr2->next;
	}
	return start;





	return NULL;
}
