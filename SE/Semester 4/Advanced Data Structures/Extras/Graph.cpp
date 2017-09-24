/*

Group A
Assignment 9

Write a function to get the number of vertices in an undirected graph and its edges. You may
assume that no edge is input twice.
1. Use adjacency list representation of the graph and find runtime of the function
2. Use adjacency matrix representation of the graph and find runtime of the function
3. Perform BFS using queue and DFS (recursive or Non-recursive)

*/


#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;
};

class graph
{
	bool v[10][10];
	int i, j, ver, edge;

	public:
	graph()
	{
		for(int a = 0; a<10; a++)
		{
			for(int b = 0; b<10; b++)
			{
				v[a][b] = 0;
			}
		}
	}
	
	
	void insert()
	{
		cout<<"\nEnter the number of vertices - ";
		cin>>ver;
		cout<<"\nEnter the number of edges - ";
		cin>>edge;

		for(int x=1;x<=edge;x++)
		{
			//cout<<edge<<endl<<i<<endl;
			cout<<"\nEnter an edge (Vi to Vj)= ";
			cin>>i>>j;
				
			v[i][j] = 1;
			v[j][i] = 1;
		}
	}

	void print()
	{
		cout<<"\n\n********************Adjacency Matrix********************\n\n";
		for(int a = 1; a<=ver; a++)
		{	
			for(int b = 1; b<=ver; b++)
				cout<<v[a][b]<<"\t";
			cout<<"\n";
		}
	}
};
		
		
int main()
{
	graph og;
	og.insert();
	og.print();
	return 0;
}	

