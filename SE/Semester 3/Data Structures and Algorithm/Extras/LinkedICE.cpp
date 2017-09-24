/*

Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B
of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked
list. compute and display-
1. Set of students who like either vanilla or butterscotch or both
2. Set of students who like both vanilla and butterscotch
3. Set of students who like only vanilla not butterscotch
4. Set of students who like only butterscotch not vanilla
5. Number of students who like neither vanilla nor butterscotch

*/

#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

class node
{
	int data;
	node *next;

	public:
	node *createlist(node *)
	{
		node *head;
		head = new node;

		head->next = NULL;
		head->data = 0;
	}
	
	
	
