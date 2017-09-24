/*

Practical 1
Group A-2

Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value

*/

#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
	public:	
	int data;
	node *left;
	node *right;
	int path[25];
	int ac;
		
	void create(node *root)
	{
		ac = 0;
		node *nw, *temp;
		char ans;
		do
		{
			nw = new node;
			cout<<"\nEnter data for new node - ";
			cin>>nw->data;
			nw->left=NULL;
			nw->right = NULL;
		
			temp = root;
			
			while(1)
			{
				if(temp->data > nw->data)
				{
					if(temp->left==NULL)
					{
						cout<<"New node "<<nw->data<<" has been inserted at the left of "<<temp->data<<endl;
						temp->left = nw;
						break;
					}
					else
					temp = temp->left;
				}

				else if(temp->data < nw->data)
				{
					if(temp->right==NULL)
					{
						cout<<"New node "<<nw->data<<" has been inserted at the right of "<<temp->data<<endl;
						temp->right = nw;
						break;
					}
					else
					temp = temp->right;
				}
			
				else if(temp->data == nw->data)
				{
					cout<<"\nTwo values can't be equal...";
					break;
				}
					
			}

			cout<<"\nDo you wanna enter another node (y/n) - ";
			cin>>ans;
		}while(ans=='y' || ans=='Y');

	}

	void insert(node *root, int n)
	{
		node *nw, *temp;
		nw = new node;
		nw->data = n;
		nw->left=NULL;
		nw->right = NULL;
		
		temp = root;
			
			while(1)
			{
				if(temp->data > nw->data)
				{
					if(temp->left==NULL)
					{
						cout<<"New node "<<nw->data<<" has been inserted at the left of "<<temp->data<<endl;
						temp->left = nw;
						break;
					}
					else
					temp = temp->left;
				}

				else if(temp->data < nw->data)
				{
					if(temp->right==NULL)
					{
						cout<<"New node "<<nw->data<<" has been inserted at the right of "<<temp->data<<endl;
						temp->right = nw;
						break;
					}
					else
					temp = temp->right;
				}
			
				else if(temp->data == nw->data)
				{
					cout<<"\nTwo values can't be equal...";
					break;
				}
					
			}
	}
	

	void preOrder(node *root)
	{
		if(root != NULL)
		{
			cout<<"\t"<<root->data;
			preOrder(root->left);
			preOrder(root->right);
			
		}
	}

	void inOrder(node *root)
	{
		if(root != NULL)
		{
			inOrder(root->left);
			cout<<"\t"<<root->data;
			inOrder(root->right);
			
		}
	}

	void postOrder(node *root)
	{
		if(root != NULL)
		{
			postOrder(root->left);
			postOrder(root->right);
			cout<<"\t"<<root->data;
			
		}
	}

	void search(node *root, int n)
	{
		if(root != NULL)
		{
			if(root->data == n)			
			{
				cout<<"\nValue found in the binary tree..."<<root->data;
				
			}
			//else
			//cout<<"\nValue not found in the binary tree...";

			search(root->left, n);
			search(root->right, n);
			
		}
	}

	int longpath(node *root)
	{
		int hl, hr;
		if(root == NULL)
		return 0;

		if(root->left == NULL && root->right == NULL)
		return 0;
		
		hl = longpath(root->left);
		hr = longpath(root->right);

		if(hr>hl)
			return(hr+1);
		else
			return(hl+1);
	}


	node* mirror(node *root)
	{
		node *mirt;
		if(root == NULL)
			return NULL;
		mirt = new node;
		mirt->left = mirror(root->right);
		mirt->right = mirror(root->left);
		mirt->data = root->data;
		
		return mirt;
	}

	int minimum(node *root)
	{
		while(root->left != NULL)		
		root = root->left;
		
		return root->data;
			
	}

	void BFS(node *);
		
		
};

class queue
{
	public:
	int left, right;
	node* que[50];
	int max;
	int size;
	public:
	queue()
	{
		size = 0; max = 50;
		left = right = -1;
	}

	int empty()
	{
		if(left==right)
		return 1;
		else
		return 0;
	}
	
	int full()
	{
		if(right==max-1)
		return 1;	
		else
		return 0;
	}

	void add(node*);
	
	node* Delete()
	{
		if(!empty())
		{
			size--;
			return(que[++right]);
		}
	}
	
	node* getRight()
	{
		if(!empty())
		return(que[right+1]);
	}

};

void queue::add(node* ele)
	{
		if(!full())
		que[++left] = ele;
		size++;
	}


void node::BFS(node* root)
{	
		queue q;
		node * temp, *t;
		temp = new node;
		temp->data = 999;
		temp->left = temp->right = NULL;
		q.add(root);
		q.add(temp);
		cout<<endl;
		int i;
		i = longpath(root);
		for(int j = 0; j<i; j++)
			{cout<<"\t\t";}
		i--;
		
		while(q.left != q.right)
		{
			t = q.Delete();
			if(t==temp)
			{
				if(q.left==q.right)
				break;

				else
				q.add(temp);
				cout<<endl;
				for(int j = 0; j<i; j++)
				{cout<<"\t";}
			}

			else
			{
				
				cout<<t->data<<"\t";
				
				if(t->left!=NULL)
					q.add(t->left);
				if(t->right!=NULL)
					q.add(t->right);
			}
		}
}






int main()
{
	node *root, *TreeMirror, on;
	queue q;
	
	

	int ch;
	
	
	while(1)
	{
		cout<<"\n\nBinary tree Operations -\n0. Construct Binary Tree\n1. Insert new node\n2. Find number of nodes in longest path\n3. Minimum data value found in the tree\n4. Change a tree so that the roles of the left and right pointers are swapped at every node\n5. Search a value\n6. Show Binary Tree Level wise\n7. Show Preorder of BST\n8. Show inorder of BST\n9. Show postorder of BST\n10. Exit\nOption - ";
		cin>>ch;
	
		switch(ch)
		{
			case 0:
			{
				root = new node;
				cout<<"\nEnter data for root node - ";
				cin>>root->data;
				root->left = NULL;
				root->right = NULL;
				on.create(root);
			}break;

			case 1:
			{
				int v;
				cout<<"\nInsert a Value - ";
				cin>>v;
				on.insert(root, v);
			}break;

			case 2:
			{
				cout<<"\nNumber of nodes in Long path - "<<on.longpath(root);
			}break;

			case 3:
			{
				cout<<"\nMinimum value in the binary - "<<on.minimum(root);
			}break;			

			case 4:
			{
				TreeMirror = new node;
				TreeMirror = on.mirror(root);
				cout<<"\nBinary Tree mirrored...\nOrder of Mirrored tree - ";
				cout<<"\nPreOrder - ";
				on.preOrder(TreeMirror);
				cout<<"\ninOrder - ";
				on.inOrder(TreeMirror);
				cout<<"\nPostOrder - ";
				on.postOrder(TreeMirror);
			}break;

			case 5:
			{
				int s;
				cout<<"\nEnter the value to be searched - ";
				cin>>s;
				on.search(root, s);
			}

			case 6:
			{
				cout<<"\nBinary Search tree Level Wise - "<<endl;
				on.BFS(root);
			}break;

			case 7:
				cout<<"\nPreOrder - ";
				on.preOrder(root); 
				break;
				
			case 8:
				cout<<"\ninOrder - ";
				on.inOrder(root);
				break;
				
			case 9:
				cout<<"\nPostOrder - ";
				on.postOrder(root);
				break;
				
			case 10:
				cout<<"\n\n\nProgram Terminated...!!!\n\n\n";
				exit(0);
			

			default: cout<<"\n\nInvalid option...\nPlease try again...!!!\n\n";
		}
	}
				 

	
	return 0;
}
  

/*Output - 
[shivasaran@localhost ~]$ g++ BSTq.cpp
[shivasaran@localhost ~]$ ./a.out


Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 0

Enter data for root node - 30

Enter data for new node - 25
New node 25 has been inserted at the left of 30

Do you wanna enter another node (y/n) - y

Enter data for new node - 21
New node 21 has been inserted at the left of 25

Do you wanna enter another node (y/n) - y

Enter data for new node - 10
New node 10 has been inserted at the left of 21

Do you wanna enter another node (y/n) - y

Enter data for new node - 25

Two values can't be equal...
Do you wanna enter another node (y/n) - y

Enter data for new node - 28
New node 28 has been inserted at the right of 25

Do you wanna enter another node (y/n) - y

Enter data for new node - 27
New node 27 has been inserted at the left of 28

Do you wanna enter another node (y/n) - y

Enter data for new node - 2
New node 2 has been inserted at the left of 10

Do you wanna enter another node (y/n) - y

Enter data for new node - 40
New node 40 has been inserted at the right of 30

Do you wanna enter another node (y/n) - y

Enter data for new node - 35
New node 35 has been inserted at the left of 40

Do you wanna enter another node (y/n) - y

Enter data for new node - 50
New node 50 has been inserted at the right of 40

Do you wanna enter another node (y/n) - y

Enter data for new node - 32
New node 32 has been inserted at the left of 35

Do you wanna enter another node (y/n) - n


Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 6

Binary Search tree Level Wise - 

								30	
			25	40	
			21	28	35	50	
			10	27	32	
			2	

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 7

PreOrder - 	30	25	21	10	2	28	27	40	35	32	50

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 8

inOrder - 	2	10	21	25	27	28	30	32	35	40	50

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 9

PostOrder - 	2	10	21	27	28	25	32	35	50	40	30

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 1

Insert a Value - 60
New node 60 has been inserted at the right of 50


Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 3

Minimum value in the binary - 2

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 2

Number of nodes in Long path - 4

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 4

Binary Tree mirrored...
Order of Mirrored tree - 
PreOrder - 	30	40	50	60	35	32	25	28	27	21	10	2
inOrder - 	60	50	40	35	32	30	28	27	25	21	10	2
PostOrder - 	60	50	32	35	40	27	28	2	10	21	25	30

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 5

Enter the value to be searched - 32

Value found in the binary tree...32
Binary Search tree Level Wise - 

								30	
			25	40	
			21	28	35	50	
			10	27	32	60	
			2	

Binary tree Operations -
0. Construct Binary Tree
1. Insert new node
2. Find number of nodes in longest path
3. Minimum data value found in the tree
4. Change a tree so that the roles of the left and right pointers are swapped at every node
5. Search a value
6. Show Binary Tree Level wise
7. Show Preorder of BST
8. Show inorder of BST
9. Show postorder of BST
10. Exit
Option - 10



Program Terminated...!!!


[shivasaran@localhost ~]$ 

*/
	

		

