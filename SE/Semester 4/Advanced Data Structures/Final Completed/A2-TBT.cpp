/* Group A-Assignment No.6

Problem Statement-
 Convert given binary tree into threaded binary tree. Analyze time and space complexity of the
algorithm.

*/

#include<iostream>
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

using namespace std;

class TBT
{
	public:
		char data;
		TBT *left, *right;
		int lbit, rbit;
		
		
		
		void create(TBT *head)
		{
			char ch, ch1;
			TBT *root,*nw,*temp;
			root=new TBT;
			cout<<"\nEnter data for new root node= ";
			cin>>root->data;
			
			root->left=head;
			root->right=head;
			root->lbit=1;
			root->rbit=1;
			head->left=root;
			head->lbit=0;
			head->rbit=0;
			do
			{
				nw=new TBT;
				
				cout<<"\nEnter data for new node= ";
				cin>>nw->data;
				
				nw->left=nw->right=NULL;
				nw->lbit=nw->rbit=1;
				temp=root;
				
				while(1)
				{
					cout<<"Press L or R to insert new data "<<nw->data<<" in left or right of root node: "<<temp->data<<"= ";
					__fpurge(stdin);
					 cin>>ch;
				 
					 if(ch=='l' || ch=='L')
					 {
					 	if(temp->lbit==1)
					 	{
					 		nw->left=temp->left;
					 		nw->right=temp;
					 		temp->left=nw;
					 		temp->lbit=0;
					 		
					 		cout<<"\nThe new node "<<nw->data<<" has been inserted in left of "<<temp->data;
					 		break;			 				 	
					 	}
			 			else
			 			temp=temp->left;
					}	
					if(ch=='r' || ch=='R')
			 		{
			 			if(temp->rbit==1)
			 			{
			 				nw->right=temp->right;
			 				nw->left=temp;
			 				temp->right=nw;
			 				temp->rbit=0;
			 				
			 				cout<<"\nThe new node "<<nw->data<<" has been inserted in right of "<<temp->data;
			 				break;			 				 	
			 			}
			 			else
			 			  temp=temp->right;
			 		}		
				
				}		
	  	
				cout<<"\nDo you want to insert new node=(Y/N)?";
				__fpurge(stdin);
				cin>>ch1;
	
				}while(ch1=='Y'|| ch1=='y');
		}
		
		void preorder(TBT *head)
		{
			TBT *temp;
		
			temp=head->left;
		
			while(temp!=head)
			{
				cout<<" "<<temp->data;
				if(temp->lbit==0)
				{
					temp=temp->left;
				}
				else if(temp->rbit==0)
					temp=temp->right;
				else
				{
					while(temp->rbit==1)
					temp=temp->right;
					
					if(temp==head)
						break;
						
					temp=temp->right;
				}
		
			}

		}

		
		void inorder(TBT *head)
		{
			TBT *temp;
			temp=head->left;
			while(temp!=head)
			{
				while(temp->lbit==0)
				{
					temp=temp->left;
				}
				cout<<" "<<temp->data;
				
				while(temp->rbit==1)
				{
					temp=temp->right;
					
					if(temp==head)
					{
						break;
					}
				cout<<" "<<temp->data;
				}
				temp=temp->right;
			}
	
		}

		void postorder(TBT *head);
};


int main()
{
	TBT *head, obj1;
	int ch;
	
	cout<<"\n\n******Threaded Binary Tree******";
	while(1)
	{
		cout<<"\n\n\n1.Create\n2.Inorder traversal\n3.Preorder traversal\n4.Exit";
		cout<<"\nChoice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				head=new TBT;
				head->left=NULL;
				head->right=head;
				head->lbit=head->rbit=1;
				
				obj1.create(head);
				break;
			case 2:
				cout<<"\nInorder traversal= ";
				obj1.inorder(head);
				
			break;
			case 3:
				cout<<"\nPreorder traversal= ";
				obj1.preorder(head);
			break;	
			case 4:
				cout<<"\n\nProgram Terminated...!!!\n\n\n";
				exit(0);
			break;
		}
	}	
}




/*Output -
[shivasaran@localhost ~]$ g++ TBT.cpp
[shivasaran@localhost ~]$ ./a.out


******Threaded Binary Tree******


1.Create
2.Inorder traversal
3.Preorder traversal
4.Exit
Choice:1

Enter data for new root node= I

Enter data for new node= F
Press L or R to insert new data F in left or right of root node: I= l

The new node F has been inserted in left of I
Do you want to insert new node=(Y/N)?y

Enter data for new node= K
Press L or R to insert new data K in left or right of root node: I= r

The new node K has been inserted in right of I
Do you want to insert new node=(Y/N)?y

Enter data for new node= C
Press L or R to insert new data C in left or right of root node: I= l
Press L or R to insert new data C in left or right of root node: F= l

The new node C has been inserted in left of F
Do you want to insert new node=(Y/N)?y

Enter data for new node= D
Press L or R to insert new data D in left or right of root node: I= l
Press L or R to insert new data D in left or right of root node: F= r

The new node D has been inserted in right of F
Do you want to insert new node=(Y/N)?y

Enter data for new node= A
Press L or R to insert new data A in left or right of root node: I= l
Press L or R to insert new data A in left or right of root node: F= l
Press L or R to insert new data A in left or right of root node: C= l

The new node A has been inserted in left of C
Do you want to insert new node=(Y/N)?y

Enter data for new node= O
Press L or R to insert new data O in left or right of root node: I= r
Press L or R to insert new data O in left or right of root node: K= r

The new node O has been inserted in right of K
Do you want to insert new node=(Y/N)?y

Enter data for new node= M
Press L or R to insert new data M in left or right of root node: I= r
Press L or R to insert new data M in left or right of root node: K= l

The new node M has been inserted in left of K
Do you want to insert new node=(Y/N)?n



1.Create
2.Inorder traversal
3.Preorder traversal
4.Exit
Choice:2

Inorder traversal=  A C F D I M K O


1.Create
2.Inorder traversal
3.Preorder traversal
4.Exit
Choice:3

Preorder traversal=  I F C A D K M O


1.Create
2.Inorder traversal
3.Preorder traversal
4.Exit
Choice:4


Program Terminated...!!!


[shivasaran@localhost ~]$

*/
