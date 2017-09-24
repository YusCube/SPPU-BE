/* 

Group C- Assignment No.-24
Problem Statement- In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.

By Shiva Saran
SE-A A-03

*/


#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int top=-1;

char stack[50];

void push(char x)
{
	top=top+1;
	stack[top]=x;

}
void pop(char t)
{
	if(t=='}')
	{

		if(stack[top]=='{')
			top=top-1;
	}
	else if(t==')')
	{
		if(stack[top]=='(')
			top=top-1;

	}
	else if(t==']')
	{
		if(stack[top]=='[')
			top=top-1;
	}
}
void display()
{
	if(top==-1)
	cout<<"\nStack is Empty\nGiven expression is well parenthesized....\n";
	else{
		cout<<"\nStack is Not Empty\nGiven expression is not well parenthesized....\n";
		
	    }
}
int main()
{
	char exp[50];
	int len,i;
	cout<<"\nEnter Your expression= ";
	cin>>exp;
	cout<<"\nYour expression is= "<<exp;
	
	len=strlen(exp);
	
	for(i=0;i<len;i++)
	{
		if((exp[i]=='{')||(exp[i]=='(')||(exp[i]=='['))
		{
			
			push(exp[i]);

           	}
           	else if((exp[i]=='}')||(exp[i]==')')||(exp[i]==']'))
           	{

          		pop(exp[i]);
    		}

	}
	display();
return 0;
}

/*
Enter Your expression= ((a+b)*{c-d*e})

Your expression is= ((a+b)*{c-d*e})
Stack is Empty
Given expression is well parenthesized....
*/
