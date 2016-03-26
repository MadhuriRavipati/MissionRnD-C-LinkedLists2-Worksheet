/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int n, c = 0, x, p=0, a;
	struct node *ptr, *preptr, *p1;
	ptr = head;
	preptr = head;
	p1 = head;
	while (ptr != NULL){
		c++;
		ptr = ptr->next;
	}
	a = (c / 2);
	if (c % 2 != 0)
	{
		while (preptr != NULL)
		{
			if (p == a){
				x = preptr->num;
				break;
			}
			p++;
			preptr = preptr->next;
		}
		return x;
	}
	else if(c % 2 == 0)
	{
		while (p1 != NULL)
		{
			if (p == a){
				p1 = preptr->next;
				x = ((preptr->num) + (p1->num))/2;
				break;
			}
			p++;
			preptr = p1;
			p1 = p1->next;
		}
		return x;
	}
	

}
