/*
Group A
Assignment 5

Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The
program should take two operands from user and performs the operation on those two
operands depending upon the operator entered by user. Use a switch statement to select the
operation. Finally, display the result.

Some sample interaction with the program might look like this:
Enter first number, operator, second number: 10 / 3
Answer = 3.333333
Do another (y/n)? y
Enter first number, operator, second number: 12 + 100
Answer = 112
Do another (y/n)? n


By Shiva Saran, SE-A, A-03
*/


#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

class calculator
{
	double a, b;
	double long result;
	char op;
	public:
	void getdata()
	{
		cout<<"\nEnter First number, operator, second number - \nInput - ";
		cin>>a>>op>>b;
	}
	void compute()
	{
		switch(op)
		{
			case '-' : result = a-b;print();break;
			case '+' : result = a+b;print();break;
			case '*' : result = a*b;print();break;
			case '/' : result = a/b;print();break;
			default: cout<<"\nIncorrect operator...!!!\nPlease Try again...\n\n";
		}
	}
	void print()
	{
		cout<<"\nResult of "<<a<<op<<b<<" = "<<result<<endl;
	}
};

int main()
{
	int ch;
	do
	{
	
		calculator calo;
		calo.getdata();
		calo.compute();
		
		cout<<"\nDo you wanna continue...?\n1.Yes\n2.No\nChoice - ";
		cin>>ch;
	}while(ch!=2);
	cout<<"\n\n\nProgram terminated...!!!\n\n";
		return 0;
}
