/*

Group C
Assignment 21

Write C++ program using STL for implementation of stack & queue using SLL

By Shiva Saran
SE-A A-03


*/

#include<iostream>
#include<list>
#include<string>
using namespace std;

class Stack
{
	public:
	list <string> s;
	void push()
	{
		string name;
		cout<<"Enter random name - ";
		getline(cin, name);
		s.push_back(name);
		cout<<"\nStack Size - "<<s.size();
	}

	void pop()
	{
		cout<<"\nPopping from stack...";
		s.pop_back();
		cout<<"\nStack Size - "<<s.size();
	}

	void top()
	{
		cout<<"\nTop element - "<<s.back()<<endl;
	}
};


int main()
{
	Stack os;
	int ch=3;
	while(ch!=0)
	{
		cout<<"\nSTL Menu\n1. Push Element\n2. Pop Element\n3. See Top element\nChoice - ";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1: os.push(); break;
			case 2: os.pop(); break;
			case 3: os.top(); break;
			default: cout<<"\nInvalid option....";
		}
	}
	return 0;
}
