/*
Group A
Assignment 5

Write a C++ program create a calculator (Using Operator Overloading) for an arithmetic operator (+, -, *, /). The
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

class Calculator //Using Operator Overloading
{
    double n;

    public:        
        void getdata()
        {           
            cin >>n;
        }

        void showdata()
        {
            cout <<n;
        }

        Calculator operator + (Calculator p)
	{
		Calculator q;
    		q.n = n + p.n;
    		return q;
	}

        Calculator operator - (Calculator p)
	{
		Calculator q;
    		q.n = n - p.n;
    		return q;
	}

        Calculator operator * (Calculator p)
	{
		Calculator q;
    		q.n = n * p.n;
    		return q;
	}
	
        Calculator operator / (Calculator p)
	{
		Calculator q;
    		q.n = n / p.n;
    		return q;
	}
};


int main()
{
	char op;
	int ch;
	
	do
	{	
	Calculator a, b, c;
	cout<<"\nEnter First number, operator, second number - \nInput - ";
	a.getdata();
    	cin>>op;
	b.getdata();
	cout << endl;

	switch (op)
	{	
        	case '+': c= a + b; break;
	        case '-': c= a - b; break;
		case '*': c= a * b; break;
		case '/': c= a / b; break;
		default: cout<<"\nIncorrect operator...!!!\nPlease Try again...\n\n";
    	}

	if(op=='+' ||	op=='-' ||	op=='*' ||	op=='/' )
	{	
	cout<<"\nResult of ";
	a.showdata();
	cout<<op;
	b.showdata();
	cout<<" = ";
	c.showdata();
	cout<<endl;
	}
	
	cout<<"\nDo you wanna continue...?\n1.Yes\n2.No\nChoice - ";
	cin>>ch;
	}while(ch!=2);
	cout<<"\n\n\nProgram terminated...!!!\n\n";
	return 0;
}

