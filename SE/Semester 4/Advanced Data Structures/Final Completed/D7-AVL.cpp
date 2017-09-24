/* 
Group D
Assignment No. 19

A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data sorted
in ascending/ Descending order. Also find how many maximum comparisons may require for
finding any keyword. Use Height balance tree and find the complexity for finding a keyword

*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

class node
{
	public:
	string word;
	string meaning;
	int hei;
	node *left,*right;
};

class avl
{
public:
	node *insert(node *root,string ,string);
	int bf(node *);
	void preorder(node *root);
	void postorder(node *root);
	void inorder(node *root);
	node *dele(node *root,string);
	node *search(node* root,string);
	int height(node *root);
	node *rotateleft(node *);
	node *rotateright(node *);
	node *LL(node *);
	node *LR(node *);
	node *RR(node *);
	node *RL(node *);
};

void avl::preorder(node *root)
{
	if(root!=NULL)
   	{
		cout<<" "<<root->word<<"->"<<root->meaning;
		preorder(root->left);
		preorder(root->right);
   }
}

void avl::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<" "<<root->word<<"->"<<root->meaning;
		inorder(root->right);
	}
}

void avl::postorder(node *root)
{
	if(root!=NULL)
	{
   		postorder(root->left);
		postorder(root->right);
		cout<<" "<<root->word<<"->"<<root->meaning;
  	}
}

node *avl::RR(node *root)
{
	root=rotateleft(root);
	return(root);
}

node *avl::RL(node *root)
{
	root->right=rotateright(root->right);
  	root=rotateleft(root);
  	return(root);
}

node *avl::LL(node *root)
{
	root=rotateright(root);
	return(root);
}

node *avl::LR(node *root)
{
	root->left=rotateleft(root->left);
	root=rotateright(root);
  	return(root);
}

node *avl::rotateright(node *temp)
 {
  node *t1;
  t1=temp->left;
  temp->left=t1->right;
  t1->right=temp;
  temp->hei=height(temp);
  t1->hei=height(t1);
  return(t1);
 }

node *avl::rotateleft(node *temp)
 {
  node *t1;
  t1=temp->right;
  temp->right=t1->left;
  t1->left=temp;
  temp->hei=height(temp);
  t1->hei=height(t1);
  return(t1);
 }

int avl::height(node *root)
{
	int lh,rh;
	if(root==NULL)
  		return(0);
  	
  	if(root->left==NULL)
  		lh=0;
  	else
  		lh=1+root->left->hei;

  	if(root->right==NULL)
   		rh=0;
   	else
   		rh=1+root->right->hei;

  	if(lh>rh) return(lh);
   	else return(rh);
}

int avl::bf(node *root)
{
	int lh,rh;
	if(root==NULL)
  		return(0);
  
  	if(root->left==NULL)
  		lh=0;
  	else
  		lh=1+root->left->hei;

  	if(root->right==NULL)
   		rh=0;
   	else
   		rh=1+root->right->hei;

   	return(lh-rh);
}

node *avl::insert(node *root,string nword,string nmeaning)
{
	if(root==NULL)
    	{
     	root=new node;
     	root->word = nword;
     	root->meaning = nmeaning;
     	root->left=NULL;
     	root->right=NULL;
    	}
   
   	else if(nword > root->word)
    	{
    		root->right=insert(root->right,nword,nmeaning);
    		if(bf(root)==-2)
     	{
      		if(nword > root->right->word)
       			root=RR(root);
       		else
       			root=RL(root);
     	}
  	}

   	else if(nword < root->word)
    	{
    		root->left=insert(root->left,nword,nmeaning);
    		if(bf(root)==2)
     	{
      		if(nword < root->left->word)
       			root=LL(root);
       		else
       			root=LR(root);
     	}
  	}
  	root->hei=height(root);
  	return(root);
}

node *avl::dele(node *root,string word)
{
  	node *temp;
  	if(root==NULL)
    		return(NULL);
  	else if(word > root->word)
    	{
     	root->right=dele(root->right,word);
     	if(bf(root)==-2)
      	{
       		if(bf(root->left)>=0)
	 			root=LL(root);
       		else
				root=LR(root);
      	}
   	}

  	else if(word < root->word)
    	{
     	root->left=dele(root->left,word);
     	if(bf(root)==2)
      	{
       		if(bf(root->right)<=0)
	 			root=RR(root);
      		else
				root=RL(root);
      	}
   	}
 	
 	else
   	{
    		if(root->right!=NULL)
     	{
      		temp=root->right;
      		while(temp->left!=NULL)
				temp=temp->left;
			root->word = temp->word;
      		root->right=dele(root->right,temp->word);
      		if(bf(root)==2)
       		{
				if(bf(root->left)>=0)
	 				root=LL(root);
	 			else
	 				root=LR(root);
       		}
     	}
    		else
    			return(root->left);
  	}
 	root->hei=height(root);
 	return(root);
}

node *avl::search(node* root,string item)
{
	if (root==NULL)
		return root;
	if(root->word == item)
		return root;
	if (root->word < item)
		return search(root->right, item);

	return search(root->left, item);
}

int main()
 {
  int ch,h,ch1;
  node *root,*t1;
  string x, y;
  avl a;
  root=NULL;
  cout<<"\n    ****MENU****";
while(1)
{
  cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Height of tree\n6.Exit";
  cout<<"\nEnter your choice:";
  cin>>ch;
  switch(ch)
   {
    case 1:
	   cout<<"\nEnter the word and its meaning to insert: ";
	   cin>>x>>y;
           
	   root=a.insert(root,x,y);
           cout<<"\n\nPreorder:\n";
           a.preorder(root);
           cout<<"\n\nInorder:\n";
	   a.inorder(root);
           cout<<"\n\nPostorder:\n";
           a.postorder(root);
    break;
    case 2:
	   cout<<"\nEnter the word to delete:";
	   cin>>x;
	   root=a.dele(root,x);

    break;
    case 3:
	   
	   cout<<"\n\n1.Preorder:";
	   a.preorder(root);
	  
	   cout<<"\n\n2.Inorder:";
	   a.inorder(root);
	  
	   cout<<"\n\n3.Postorder:";
	   a.postorder(root);
	  
    break;
    

    case 4:
	   cout<<"\nEnter the word to Search= ";
	   cin>>x;
	   t1=a.search(root,x);
	   if(t1==NULL)
		cout<<"\n Given Word is Not Present in Dictionary. ";
	     else
		cout<<"\n Given Word is Present in Dictionary. ";
    break;
    case 5:
	    h=a.height(root);
	    cout<<"\nHeight of tree is=="<<h;
     break;
     case 6:
	    exit(0);
  }
 }
 return(0);
}

/* ******************************** OUTPUT ********************************
[shivasaran@sss-ragemachine ~]$  g++ Assign_D_19.cpp
[shivasaran@sss-ragemachine ~]$  ./a.out

    ****MENU****
1.Insert
2.Delete
3.Display
4.Search
5.Height of tree
6.Exit
Enter your choice:1

Enter the word and its meaning to insert: bat animal


Preorder:
 bat->animal

Inorder:
 bat->animal

Postorder:
 bat->animal
1.Insert
2.Delete
3.Display
4.Search
5.Height of tree
6.Exit
Enter your choice:1

Enter the word and its meaning to insert: signal order


Preorder:
 bat->animal signal->order

Inorder:
 bat->animal signal->order

Postorder:
 signal->order bat->animal
1.Insert
2.Delete
3.Display
4.Search
5.Height of tree
6.Exit
Enter your choice:1       

Enter the word and its meaning to insert: light lamp


Preorder:
 light->lamp bat->animal signal->order

Inorder:
 bat->animal light->lamp signal->order

Postorder:
 bat->animal signal->order light->lamp
1.Insert
2.Delete
3.Display
4.Search
5.Height of tree
6.Exit
Enter your choice:4

Enter the word to Search= signal

 Given Word is Present in Dictionary. 
1.Insert
2.Delete
3.Display
4.Search
5.Height of tree
6.Exit
Enter your choice:5

Height of tree is==1
1.Insert
2.Delete
3.Display
4.Search
5.Height of tree
6.Exit
Enter your choice:6
[shivasaran@sss-ragemachine ~]$  


*/
