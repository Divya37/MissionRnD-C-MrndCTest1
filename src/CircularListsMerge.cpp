/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node * sortLinkedList(struct node *head)
{

	int i = 0, *arr, j = 0, size = 0, swap_temp = 0;
	arr = (int *)malloc(sizeof(int) * 20);
	struct node *temp = head;

	if (head == NULL)
		return NULL;

	while (temp != NULL)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	size = i;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				swap_temp = arr[i];
				arr[i] = arr[j];
				arr[j] = swap_temp;
			}
		}
	}
	temp = head;
	for (i = 0; i < size; i++)
	{
		temp->data = arr[i];
		temp = temp->next;

	}
	return head;
}
struct node * merge(struct node *head1, struct node *head2)
{
	struct node *temp, *head;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		head = head2;
	else if (head2 == NULL)
		head = head1;
	else
	{
		if (head1->data <= head2->data)
		{
			head = head1;
			head1 = head1->next;
			temp = head;
		}
		else
		{
			head = head2;
			head2 = head2->next;
			temp = head;
		}
		while (head1 != NULL && head2 != NULL)
		{
			if (head1->data < head2->data)
			{
				temp->next = head1;
				head1 = head1->next;
				temp = temp->next;
			}
			else
			{
				temp->next = head2;
				head2 = head2->next;
				temp = temp->next;
			}
			if (head1->data == head2->data)
			{
				temp->next = head1;
				head1 = head1->next;
				temp = temp->next;
				temp->next = head2;
				head2 = head2->next;
				temp = temp->next;
			}
		}
		while (head1 != NULL)
		{
			temp->next = head1;
			head1 = head1->next;
			temp = temp->next;
		}
		while (head2 != NULL)
		{
			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;
		}
	}
	return head;
}

int merge_circularlists(struct node **head1, struct node **head2){
	if (*head1 == NULL || *head2 == NULL)
		return -1;

	struct node *temp_head;
	int count1 = 0, count2 = 0;
	temp_head = *head1;
	while (temp_head->next!=*head1)
	{ 
		temp_head = temp_head->next;
		count1++;
	}
	temp_head->next = NULL;

	temp_head = *head2;
	while (temp_head->next != *head2)
	{
		temp_head = temp_head->next;
		count2++;
	}
	temp_head->next = NULL;
	*head1=merge(*head1, *head2);
	temp_head = *head1;
	while (temp_head->next != NULL)
	{
		temp_head = temp_head->next;
	}
	temp_head->next = *head1;
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	return count1+count2;
}