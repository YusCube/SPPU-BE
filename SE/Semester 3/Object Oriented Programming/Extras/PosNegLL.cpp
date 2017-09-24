/*

Write C++ program to store set of negative and positive numbers using linked list. Write
functions
1. Insert numbers.
2. Delete nodes with negative numbers.
3. To create two more linked lists using this list, one containing all positive numbers and other containing negative numbers.
4. For two lists that are sorted; Merge these two lists into third resultant list that is sorted.

*/

#include<iostream>
#include<stdlib.h>


class node
{
	node *head, *poshead, *neghead;
	int data;
	
	public:
	node * headini(node *head)
	{
		head=new node;
		head->next=NULL;
		head->data=0;
		return head; 
	}



	void insertnum(node *head, int info)
	{
		node *nw, *temp;
		nw=new node;
	
		nw->data = info;
		nw->next=NULL;

		temp=head;
	
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nw;
		head->data++;
	}

}

int main()
{
	int n, data;
	node objn;
	node *head, *poshead, *neghead;
	head = objn.headini(head);
	
	cout<<"\nHow many positive or negative you wanna enter - ";
	cin>>n;
	
	//case1: 
	for(int i = 0; i<n; i++)
	{
		cout<<"Data "<<i+1<<" - ";
		cin>>data;
		objn.insertnum(head, data);
	}

	//case 3:
	poshead = objn.headini(poshead);
	neghead = objn.headini(neghead);
	
