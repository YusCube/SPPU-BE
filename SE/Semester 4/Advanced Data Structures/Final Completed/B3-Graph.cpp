/* 
Group B
Assignment No. 9

Write a function to get the number of vertices in an undirected graph and its edges. 
You may assume that no edge is input twice.
i. Use adjacency list representation of the graph and find runtime of the function
ii. Use adjacency matrix representation of the graph and find runtime of the function
iii. Perform BFS using queue and DFS (recursive or Non-recursive)

*/

#include<iostream>
#include<stdlib.h>
using namespace std;
  class node
  {
     public:
	int data;
	node *next;
  };

class graph
{
      public:
	int visited[20];
	node *head[20];
	int n;
	bool v[10][10];
	
	public:
	graph()
	{
		n=0;
		for(int a = 0; a<10; a++)
		{
			for(int b = 0; b<10; b++)
			{
				v[a][b] = 0;
			}
		}
	}

	void insertMat(int, int);
	void printMat();
	void insert(int ai,int aj);
	void printList();
	void DFS1(int);
	void readg();
	void BFS(int);
	void DFS(int);
};
class queue
{
  	public:
   	int qsize[40];
  	int rear,front;
  	queue()
  	{
  		rear=-1;
  		front=-1;
  	}

	void inqueue(int temp)
	{
 		rear++;
 		qsize[rear]=temp;
	}

	int dequeue()
	{
  		int temp;
  		temp=qsize[++front];
  		return(temp);
	}
};

void graph::DFS(int start)
  {
	for(int i=1;i<=n;i++)
		visited[i]=0;
	DFS1(start);
  }
void graph::BFS(int v)
{
	int i,w;
	queue s1;
	node *temp;
	for(i=1;i<=n;i++)
		visited[i]=0;
	s1.inqueue(v);
	cout<<"\n Visited Vertex=  "<<v;
	visited[v]=1;
	while(s1.front!=s1.rear)
	   {
		v=s1.dequeue();
		for(temp=head[v];temp!=NULL;temp=temp->next)
		   {
			w=temp->data;
			if(visited[w]==0)
			  {
				s1.inqueue(w);
				visited[w]=1;
				cout<<"\nVisited Vertex=  "<<w;
			  }
		   }
	   }
}

void graph::DFS1(int i)
{
	node *temp;
	cout<<"\t"<<i;
	temp=head[i];
	visited[i]=1;
	while(temp!=NULL)
	{
		i=temp->data;
		if(visited[i]!=1)
			DFS1(i);
		temp=temp->next;
	}
}


void graph::readg()
{
	int i,ai,aj,edge;
	cout<<"\n\nEnter no. of vertices :";
	cin>>n;
	for(i=1;i<=n;i++)
		head[i]=NULL;
	cout<<"\n\nEnter no of edges :";
	cin>>edge;
	for(i=1;i<=edge;i++)
	{
		cout<<"\nEnter an edge (Vi to Vj)= ";
		cin>>ai>>aj;
		insertMat(ai,aj);
		insertMat(aj,ai);
		insert(ai,aj);
		insert(aj,ai);
	}
}

void graph::printList()
{
	node *temp;
  cout<<"\n **************** Adjacency list ****************";
  for(int i=1;i<=n;i++)
  {
	cout<<"\nHead ["<<i<<"]= ";
	for(temp=head[i]->next;temp!=NULL;temp=temp->next)
	{
		cout<<"->"<<temp->data;
        }
	cout<<"-END.";
  }
}

void graph::printMat()
{
		cout<<"\n\n********************Adjacency Matrix********************\n\n";
		for(int a = 1; a<=n; a++)
		{	
			for(int b = 1; b<=n; b++)
				cout<<v[a][b]<<"\t";
			cout<<"\n";
		}
}

void graph::insert(int ai,int aj)
{
	node *temp,*nnew,*t1;
	int i;

	nnew=new node ;
	nnew->data=aj;
	nnew->next=NULL;

	if(head[ai]==NULL)
	{
	  t1=new node ;
	  t1->data=ai;
	  t1->next=NULL;
	  head[ai]=t1;
	}
	if(head[ai]!=NULL)
	{
		temp=head[ai];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nnew;
	}
 
}

void graph::insertMat(int i, int j)
{
		v[i][j] = 1;
		v[j][i] = 1;
}



int main()
{
         int ch,start;
     
	graph s1;
	while(1)
	{
		cout<<"\n**************** Program Menus ****************\n1)Create Graph\n2)Display Adjacency Matrix\n3)Dispaly Adjacency List\n4)DFS\n5)BFS\n6)Exit";
		cout<<"\n\nEnter Your Choice : ";
		cin >>ch ;
		switch(ch)
		   {
			case 1:	s1.readg();
				break;
			case 2: s1.printMat();
				break;
			case 3: s1.printList();
				break;
			case 4: cout<<"\nEnter starting node : ";
				cin>>start;
				cout<<"\nDFS Sequence=\n";
				s1.DFS(start);
				break;
			case 5: cout<<"\nEnter starting node : ";
				cin>>start;
				s1.BFS(start);
				break;
			case 6:exit(0);
		    }

	}
return 0;
}

/********************** OUTPUT*********************
[shivasaran@sss-ragemachine C++]$ g++ Assign-09.cpp
[shivasaran@sss-ragemachine C++]$ ./a.out

**************** Program Menus ****************
1)Create Graph
2)Display Adjacency Matrix
3)Dispaly Adjacency List
4)DFS
5)BFS
6)Exit

Enter Your Choice : 1


Enter no. of vertices :5


Enter no of edges :6

Enter an edge (Vi to Vj)= 1 2
Enter an edge (Vi to Vj)= 1 3
Enter an edge (Vi to Vj)= 2 4
Enter an edge (Vi to Vj)= 2 5
Enter an edge (Vi to Vj)= 3 4
Enter an edge (Vi to Vj)= 4 5

**************** Program Menus ****************
1)Create Graph
2)Display Adjacency Matrix
3)Dispaly Adjacency List
4)DFS
5)BFS
6)Exit

Enter Your Choice : 2


********************Adjacency Matrix********************

0	1	1	0	0	
1	0	0	1	1	
1	0	0	1	0	
0	1	1	0	1	
0	1	0	1	0	

**************** Program Menus ****************
1)Create Graph
2)Display Adjacency Matrix
3)Dispaly Adjacency List
4)DFS
5)BFS
6)Exit

Enter Your Choice : 3

 **************** Adjacency list ****************
Head [1]= ->2->3-END.
Head [2]= ->1->4->5-END.
Head [3]= ->1->4-END.
Head [4]= ->2->3->5-END.
Head [5]= ->2->4-END.

**************** Program Menus ****************
1)Create Graph
2)Display Adjacency Matrix
3)Dispaly Adjacency List
4)DFS
5)BFS
6)Exit

Enter Your Choice : 4

Enter starting node : 5

DFS Sequence=
	5	2	1	3	4

**************** Program Menus ****************
1)Create Graph
2)Display Adjacency Matrix
3)Dispaly Adjacency List
4)DFS
5)BFS
6)Exit

Enter Your Choice : 5

Enter starting node : 3

 Visited Vertex=  3
Visited Vertex=  1
Visited Vertex=  4
Visited Vertex=  2
Visited Vertex=  5

**************** Program Menus ****************
1)Create Graph
2)Display Adjacency Matrix
3)Dispaly Adjacency List
4)DFS
5)BFS
6)Exit

Enter Your Choice : 6

[shivasaran@sss-ragemachine C++]$ 

*/

