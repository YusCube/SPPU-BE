/*

Write C++ program for string operations- copy, concatenate, check substring, equal, reverse
and length 


*/




#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
using namespace std;

class strops
{
	char str1[100];
	char str2[100];
	
	
	public: void input1()
	{
		cout<<endl<<"Enter string - ";
		cin>>str1;
			
	}
	
	void input2()
	{
		cout<<endl<<"Enter second string - ";
		cin>>str2;
	
	}
	
	void copystr()
	{
		cout<<"\nString Copy -";
		for(int i = 0; str1[i]!='\0';i++)
		{
			str2[i] = str1[i];
		}
		cout<<"\nString 1 - "<<str1;
		cout<<"\nString 2 - "<<str2;
	}

	void concstr()
	{
		int i, j;
		
		for(i=0; str1[i]!='\0'; i++); //finds length of the String 
		for(j=0; str2[j]!='\0'; j++, i++)
    		{
        		str1[i]=str2[j];
    		}
    		str1[i]='\0';
    		cout << "\n\nAfter concatenation: " << str1<<endl<<endl;
    		
	}

	void strequal()
	{
		int flag = 0,i ;
		for(i=0; str1[i]!='\0'; i++)
		{
			if(str1[i] != str2[i])
			{
				cout<<"\nStrings 1 and 2 are not equal...!!!";
				flag = 1;
				break;
			}
		}
		if(flag==0)
		cout<<"\nStrings 1 and 2 are equal...!!!";
	}
	
	void reversestr()
	{
		char str3[100];
		int l, j;
		cout<<"\n\nReverse of the String is - ";
		for(l=0; str1[l]!='\0'; l++);
		for(j = l-1; j>=0; j--)
		cout<<str1[j];
				
	}
	
	void strlength()
	{
		int l;	
		for(l=0; str1[l]!='\0'; l++);
		cout<<"\nLength of String is "<<l;
	}
	
	void substr()	
	{
		char subs[50], *p;
		int sl, l;
		cout<<"\nEnter the substring to be checked - ";
		cin>>subs;
		p = strstr(str1, subs);
				
		if(p=='\0')
		cout<<"\nEntered string is not a substring of string 1";
		else
		cout<<"\nEntered string is a substring of string 1";
	}		
};

int main()
{
	int ch, op;	
	
	do
	{
	
	strops so;
	cout<<endl<<"String Functions -"<<endl;
	cout<<"1.String Copy\n2.Concatenate\n3.Check Substring\n4.Equal\n5.Reverse String\n6. Length\nChoice - ";
	cin>>ch;
	switch(ch)
	{
		case 1: so.input1(); 
			so.copystr(); break;
		
		case 2: so.input1();
			so.input2();
			so.concstr(); break;

		case 3: so.input1();
			so.substr(); break;
			
		case 4: so.input1();
			so.input2();
			so.strequal(); break;
		
		case 5: so.input1();
			so.reversestr(); break;
		
		case 6: so.input1();
			so.strlength(); break;
		
		default: cout<<"Invalid Input...\nPlease Try again...\n";
	} 
	
	cout<<"\n\nDo you wanna continue...?\n1. Yes\n2. No\nChoice - ";
	cin>>op;

	}while(op!=2);
	
	
	
}
