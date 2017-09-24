/* 

Group E- Assignment No- 36

Problem Statement--
Write C++ program to store second year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores.

By Shiva Saran
SE-A A-03

*/


#include<iostream>
#include<stdlib.h>
using namespace std;
#define M 60
class Marksheet
{
	float array[M];
	int size;
public:
	void getdata();
 	void insertion();
	void shell();
};
void Marksheet:: getdata()
{ 
	cout<<"\n Enter how many students are there?:= ";
  	cin>>size;
  	cout<<"\n Enter the first year percentage of "<<size<<" students= \n";
   	for(int i=0;i<size;i++)
    		cin>>array[i];
}

void Marksheet::insertion()
{

	int i,j,min,k,m;
	float temp;
  	
	for(i=1;i<size;i++)
	{
	      temp=array[i];
	      j=i-1;
	      while((temp<array[j])&&(j>=0))
	      {
	      		array[j+1]=array[j];
	      		j=j-1;
      	      }
  	      array[j+1]=temp;
  	
		cout<<"\nIteration No= "<<i+1<<"-->";
		for(k=0;k<size;k++)
			cout<<" "<<array[k];
	}
	cout<<"\nTop Five Scores are= \n";
	for(k=size-1,m=1;k>=0;k--,m++)
	{
		if(m<=5)
		{
			cout<<" "<<array[k];
		}
	}
}
void Marksheet::shell()
{

	int i,j,k,m,d;
	float temp;
  	d=(size+1)/2;
  	for(i=d;i>=1;i=i/2)
  	{ 
		for(j=i;j<=size-1;j++)
		{  
			temp=array[j];
			k=j-i;
     			while(k>=0 && temp < array[k])
     			{ 
				array[k+i]=array[k];
				k=k-i;
      			}
   		array[k+i]=temp;
   		} 
  		cout<<"\nIteration No= "<<i<<"-->";
		for(k=0;k<size;k++)
			cout<<" "<<array[k];
	}
	cout<<"\nTop Five Scores are= \n";
	for(k=size-1,m=1;k>=0;k--,m++)
	{
		if(m<=5)
		{
			cout<<" "<<array[k];
		}
	}
}

int main()
{ 
  	Marksheet s1;
  	int ch;
  	  
	while(1) 
	{  
		cout<<"\n ****************** Sorting Techniques Main Menu ********************";
		cout<<"\n 1. Insertion sort\n 2. Shell Sort \n 3. Exit";
   		cout<<"\n Enter your choice:=";
   		cin>>ch;
    		switch(ch)
    		{ 
			case 1:
				s1.getdata();
				s1.insertion();
   			break;           
  			case 2:
				s1.getdata();
				s1.shell();
   			break;
  	  		case 3:
    				exit(0);
    		}
	}
return 0;
}

/*

 ****************** Sorting Techniques Main Menu ********************
 1. Insertion sort
 2. Shell Sort 
 3. Exit
 Enter your choice:=1

 Enter how many students are there?:= 10

 Enter the first year percentage of 10 students= 
99.14        
77.82
11.45
66.25
10.54
88.12
77.45
52
32.45
42.32

Iteration No= 2--> 77.82 99.14 11.45 66.25 10.54 88.12 77.45 52 32.45 42.32
Iteration No= 3--> 11.45 77.82 99.14 66.25 10.54 88.12 77.45 52 32.45 42.32
Iteration No= 4--> 11.45 66.25 77.82 99.14 10.54 88.12 77.45 52 32.45 42.32
Iteration No= 5--> 10.54 11.45 66.25 77.82 99.14 88.12 77.45 52 32.45 42.32
Iteration No= 6--> 10.54 11.45 66.25 77.82 88.12 99.14 77.45 52 32.45 42.32
Iteration No= 7--> 10.54 11.45 66.25 77.45 77.82 88.12 99.14 52 32.45 42.32
Iteration No= 8--> 10.54 11.45 52 66.25 77.45 77.82 88.12 99.14 32.45 42.32
Iteration No= 9--> 10.54 11.45 32.45 52 66.25 77.45 77.82 88.12 99.14 42.32
Iteration No= 10--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Top Five Scores are= 
 99.14 88.12 77.82 77.45 66.25
 ****************** Sorting Techniques Main Menu ********************
 1. Insertion sort
 2. Shell Sort 
 3. Exit
 Enter your choice:=2

 Enter how many students are there?:= 10

 Enter the first year percentage of 10 students= 
99.14
77.82
11.45
66.25
10.54
88.12
77.45
52
32.45
42.32

Iteration No= 5--> 88.12 77.45 11.45 32.45 10.54 99.14 77.82 52 66.25 42.32
Iteration No= 2--> 10.54 32.45 11.45 42.32 66.25 52 77.82 77.45 88.12 99.14
Iteration No= 1--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Top Five Scores are= 
 99.14 88.12 77.82 77.45 66.25
 ****************** Sorting Techniques Main Menu ********************
 1. Insertion sort
 2. Shell Sort 
 3. Exit
 Enter your choice:=3
*/













