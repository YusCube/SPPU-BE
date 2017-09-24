/*

Write C++ program using STL for Dqueue (Double ended queue)

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<string.h>
#include<deque>
using namespace std;

class Dequeue
{
	public :
		int a;
		deque <int> s;
		deque <int> :: iterator itr;


		void push_front()
		{
			cout<<"\n Enter a number : ";
				cin>>a;
				s.push_front(a);
		}

		void push_back()
		{
			 cout<<"\n Enter a number : ";
			 cin>>a;
			 s.push_back(a);
	    }

		void pop_back()
		{
			itr=s.end();
			itr--;
			s.pop_back();
			cout<<"\n The element popped out of the queue is "<<*itr;
		}

		void pop_front()
		{
			itr=s.begin();
			s.pop_front();
			cout<<"\n The element popped out of the queue is "<<*itr;
		}

		void displayqueue()
		{
				cout<<"\n The elements in the queue are : "<<"\n";
				for(itr=s.begin() ; itr!=s.end() ; itr++)
			{
				cout<<*itr<<"\t";
			}
		}

};

int main()
{
	Dequeue p;
	int choice;
	char ans;
	do
	{
		cout<<"\n 1. Add element from front \n 2. Add element from behind \n 3. Delete element front front \n 4. Delete element from behind \n 5. Display queue elements";
		cout<<"\n Enter the operation you want to perform : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : p.push_front();
			break;
			case 2 : p.push_back();
			break;
			case 3 : p.pop_front();
			break;
			case 4 : p.pop_back();
			break;
			case 5 : p.displayqueue();
			break;
		}
		cout<<"\n Do you want to perform any other operation ?";
		cin>>ans;
	}while(ans=='Y' || ans=='y');
}

/**********************************************Output*****************************************************


bash-4.2$ g++ GrC - 23.cpp
bash-4.2$ ./a.out

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 1

 Enter a number : 67

 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 1

 Enter a number : 98

 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 1

 Enter a number : 56

 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 5

 The elements in the queue are : 
56	98	67	
 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 3

 The element popped out of the queue is 56
 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 2

 Enter a number : 10

 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 5

 The elements in the queue are : 
98	67	10	
 Do you want to perform any other operation ?y

 1. Add element from front 
 2. Add element from behind 
 3. Delete element front front 
 4. Delete element from behind 
 5. Display queue elements
 Enter the operation you want to perform : 4

 The element popped out of the queue is 10
 Do you want to perform any other operation ?n
*/
