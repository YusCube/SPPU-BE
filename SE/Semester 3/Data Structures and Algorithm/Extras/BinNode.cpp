/* 
Group B- Assignment No. 19

Write C++ program for storing binary number using doubly linked lists. Write functions
a) to compute 1‘s and 2‘s complement
b) add two binary numbers



		void display(node *head);
		void insert_at_begin(node *head,int x);
		void insert_at_end(node *head,int x);
		node* ones_complement(node *head);
		void twos_complement(node *head);
		void add(node *head,node *head1);

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class BinaryNode
{
	int b;
	BinaryNode *next;
	BinaryNode *back;

	public:
	
	BinaryNode *create(BinaryNode *head)
	{
		head = new BinaryNode;
		head->next = NULL:
		head->back = NULL;
		head->b = 0;
		return head;
	}

	
	void BeginInsert(BinaryNode *head; int n)
	{
		BinaryNode *nw;
		BinaryNode = new nw;
