/*

Write C++ program for string operations- copy, concatenate, check substring, equal, reverse
and length 


*/




#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

class strops
{
	char str1[100];
	char str2[100];
	
	
	public: 
	void copystr(char str1[100], char str2[100])
	{
		cout<<"\nString Copy -";
		for(int i = 0; str1[i]!='\0';i++)
		{
			str2[i] = str1[i];
		}
		cout<<"\nString 1 - "<<str1;
		cout<<"\nString 2 - "<<str2;
	}

	void concstr(char str1[100], char str2[100])
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

	void strequal(char str1[100], char str2[100])
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
	
	void reversestr(char str1[100])
	{
		char str3[100];
		int l, j;
		cout<<"\n\nReverse of the String is - ";
		for(l=0; str1[l]!='\0'; l++);
		for(j = l-1; j>=0; j--)
		cout<<str1[j];
				
	}
	
	void strlength(char str1[100])
	{
		int l;	
		for(l=0; str1[l]!='\0'; l++);
		cout<<"\nLength of String is "<<l;
	}
	
	void substr(char str1[100])	
	{
		char subs[50], *p;
		int sl, l;
		cout<<"\nEnter the substring to be checked - ";
		gets(subs);
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
	char s1[100], s2[100];	
	
	do
	{
	
	strops so;
	cout<<endl<<"String Functions -"<<endl;
	cout<<"1.String Copy\n2.Concatenate\n3.Check Substring\n4.Equal\n5.Reverse String\n6. Length\nChoice - ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<endl<<"Enter string - ";
			gets(s1);
			so.copystr(s1, s2); break;
		
		case 2: cout<<endl<<"Enter string - ";
			gets(s1);
			cout<<endl<<"Enter second string - ";
			gets(s2);
			so.concstr(s1,s2); break;

		case 3: cout<<endl<<"Enter string - ";
			gets(s1);
			so.substr(s1); break;
			
		case 4: cout<<endl<<"Enter string - ";
			gets(s1);
			cout<<endl<<"Enter second string - ";
			gets(s2);
			so.strequal(s1,s2); break;
		
		case 5: cout<<endl<<"Enter string - ";
			gets(s1);
			so.reversestr(s1); break;
		
		case 6: cout<<endl<<"Enter string - ";
			gets(s1);
			so.strlength(s1); break;
		
		default: cout<<"Invalid Input...\nPlease Try again...\n";
	} 
	
	cout<<"\nDo you wanna continue...?\n1. Yes\n 2. No\nChoice - ";
	cin>>op;

	}while(op!=2);
	
	
	
}
