/* 
Group B
Assignment No. 11

You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.

*/

#include<stdlib.h>
#include<iostream>
using namespace std;

class prims
{
public:
	int cost[10][10],vertex,edge;
	void creategraph();
	void primfun(int);
};


void prims::creategraph()
{
  	int v1,v2,i,j,wt;
   	cout<<"\n\t\t Enter the MAXIMUM no of vertices:::";
   	cin>>vertex;
   	cout<<"\n\t\t Enter the no of edges:::";
   	cin>>edge;
  	for(i=1;i<=vertex;i++)
  		for(j=1;j<=vertex;j++)
     			cost[i][j]=0;

   	for(i=1;i<=edge;i++)
   	{
			cout<<"\n\t\t Enter the edge and its weight(v1,v2,wt)::";
			cin>>v1>>v2>>wt;
			cost[v1][v2]=cost[v2][v1]=wt;
   	}
   	
   	cout<<"\n****** Adajency Matrix ********\n";
   	for(i=1;i<=vertex;i++)
   	{
  			for(j=1;j<=vertex;j++)
  			 {
  			 		cout<<"  "<<cost[i][j];
  			 }
  			 cout<<"\n";
  		}	 		
}

void prims::primfun(int start)
{
  int p,temp,min,visited[10],sum=0,k,m,j,i,n;

  for(i=1;i<=vertex;i++)
  {
   visited[i]=0;
  }

 visited[start]=1;
 
 for(k=1;k<=vertex-1;k++)
 {
     	temp=999;
     for(i=1;i<=vertex;i++)
     {
			if(visited[i]==1)
			{
	  			min=999;
	   		for(j=1;j<=vertex;j++)
	  			{
	    			if(cost[i][j]!=0)
	    			{
	     				if(cost[i][j]< min && visited[j]==0)
	     				{
		  					min=cost[i][j];
		  					p=j;
	     				}
	    			}
	   		}//end of j for loop
	   	if(min<temp)
	   	{
		 		temp=min;
		 		m=i;
		 		n=p;
	    	}
		}//end of if
    }//end of i for loop

      sum=sum+cost[m][n];
      cout<<"\n\t\t Selected Edge of the graph "<<m<<" "<<n<<" Weight "<<cost[m][n];
      visited[m]=1;
      visited[n]=1;

   } //end of k for loop
   cout<<"\n\tCost of minimun spanning tree is::"<<sum;

}

int main()
{
   prims s1;
   
   int ch;
	while(1)
	{

		 cout<<"\n 1.Readgraph and Create Adjency Matrix \n 2.Prims Algorithm \n 3.Exit.\n";
		 cout<<"\n\nEnter Ur Choice= ";
		 cin>>ch;
		 switch(ch)
		 {

		 case 1:
			 s1.creategraph();
				 break;

		 case 2:
			    int start;
			    cout<<"\nEnter Starting Vertex=";
			    cin>>start;
			    s1.primfun(start);
				 break;

		 case 3:exit(0);
		 }
	 }
   return 0;
}


/* **************** OUTPUT ******************************************
[shivasaran@sss-ragemachine ~]$  g++ Assign-11.cpp
[shivasaran@sss-ragemachine ~]$  ./a.out

 1.Readgraph and Create Adjency Matrix 
 2.Prims Algorithm 
 3.Exit.


Enter Ur Choice= 1

		 Enter the MAXIMUM no of vertices:::5

		 Enter the no of edges:::8

		 Enter the edge and its weight(v1,v2,wt)::1 2 10
		 Enter the edge and its weight(v1,v2,wt)::1 3 8
		 Enter the edge and its weight(v1,v2,wt)::1 5 7
		 Enter the edge and its weight(v1,v2,wt)::2 3 8
		 Enter the edge and its weight(v1,v2,wt)::2 4 7
		 Enter the edge and its weight(v1,v2,wt)::2 5 4
		 Enter the edge and its weight(v1,v2,wt)::3 4 6
		 Enter the edge and its weight(v1,v2,wt)::4 5 5

****** Adajency Matrix ********
  0  10  8  0  7
  10  0  8  7  4
  8  8  0  6  0
  0  7  6  0  5
  7  4  0  5  0

 1.Readgraph and Create Adjency Matrix 
 2.Prims Algorithm 
 3.Exit.


Enter Ur Choice= 2

Enter Starting Vertex=5

		 Selected Edge of the graph 5 2 Weight 4
		 Selected Edge of the graph 5 4 Weight 5
		 Selected Edge of the graph 4 3 Weight 6
		 Selected Edge of the graph 5 1 Weight 7
	Cost of minimun spanning tree is::22
 1.Readgraph and Create Adjency Matrix 
 2.Prims Algorithm 
 3.Exit.


Enter Ur Choice= 3
[shivasaran@sss-ragemachine ~]$  
*/
