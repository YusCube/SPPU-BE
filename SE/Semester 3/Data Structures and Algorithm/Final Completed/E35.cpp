/* 


Group E- Assignment No- 35
Problem Statement--
Write C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.

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
 	void selection();
	void bubble();
};
void Marksheet:: getdata()
{ 
	cout<<"\n Enter how many students are there?:= ";
  	cin>>size;
  	cout<<"\n Enter the first year percentage of "<<size<<" students= \n";
   	for(int i=0;i<size;i++)
    		cin>>array[i];
}

void Marksheet::selection()
{

	int i,j,min,k,m;
	float temp;
  	
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]<array[min])
			{
				min=j;
			}	
		}	
			temp=array[i];
			array[i]= array[min];
			array[min]=temp;
		
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
void Marksheet::bubble()
{

	int i,j,k,m;
	float temp;
  	
	for(i=0;i<size-1;i++)
	{
		
		for(j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]= array[j+1];
				array[j+1]=temp;
			}
			
		}
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

int main()
{ 
  	Marksheet s1;
  	int ch;
  	
  
	while(1) 
	{  
		cout<<"\n ****************** Sorting Techniques Main Menu ********************";
		cout<<"\n 1. Selection Sort\n 2. Bubble Sort \n 3. Exit";
   		cout<<"\n Enter your choice:=";
   		cin>>ch;
    		switch(ch)
    		{ 
			case 1:
				s1.getdata();
				s1.selection();
   			break;           
  			case 2:
				s1.getdata();
				s1.bubble();
   			break;
  	  		case 3:
    				exit(0);
    		}
	}
return 0;
}

/*

 ****************** Sorting Techniques Main Menu ********************
 1. Selection Sort
 2. Bubble Sort 
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

Iteration No= 1--> 10.54 77.82 11.45 66.25 99.14 88.12 77.45 52 32.45 42.32
Iteration No= 2--> 10.54 11.45 77.82 66.25 99.14 88.12 77.45 52 32.45 42.32
Iteration No= 3--> 10.54 11.45 32.45 66.25 99.14 88.12 77.45 52 77.82 42.32
Iteration No= 4--> 10.54 11.45 32.45 42.32 99.14 88.12 77.45 52 77.82 66.25
Iteration No= 5--> 10.54 11.45 32.45 42.32 52 88.12 77.45 99.14 77.82 66.25
Iteration No= 6--> 10.54 11.45 32.45 42.32 52 66.25 77.45 99.14 77.82 88.12
Iteration No= 7--> 10.54 11.45 32.45 42.32 52 66.25 77.45 99.14 77.82 88.12
Iteration No= 8--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 99.14 88.12
Iteration No= 9--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Top Five Scores are= 
 99.14 88.12 77.82 77.45 66.25
 ****************** Sorting Techniques Main Menu ********************
 1. Selection Sort
 2. Bubble Sort 
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

Iteration No= 1--> 77.82 11.45 66.25 10.54 88.12 77.45 52 32.45 42.32 99.14
Iteration No= 2--> 11.45 66.25 10.54 77.82 77.45 52 32.45 42.32 88.12 99.14
Iteration No= 3--> 11.45 10.54 66.25 77.45 52 32.45 42.32 77.82 88.12 99.14
Iteration No= 4--> 10.54 11.45 66.25 52 32.45 42.32 77.45 77.82 88.12 99.14
Iteration No= 5--> 10.54 11.45 52 32.45 42.32 66.25 77.45 77.82 88.12 99.14
Iteration No= 6--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Iteration No= 7--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Iteration No= 8--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Iteration No= 9--> 10.54 11.45 32.45 42.32 52 66.25 77.45 77.82 88.12 99.14
Top Five Scores are= 
 99.14 88.12 77.82 77.45 66.25
 ****************** Sorting Techniques Main Menu ********************
 1. Selection Sort
 2. Bubble Sort 
 3. Exit
 Enter your choice:=3

*/













