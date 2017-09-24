/*

Write C++ program for string operations- copy, concatenate, check substring, equal, reverse
and length 


*/




#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>
using namespace std;

class strops
{
	char str1[100];
	char str2[100];
	
	
	public: void input()
	{
		cout<<endl<<"Enter first string - ";
		gets(str1);
		cout<<endl<<"Enter second string - ";
		gets(str2);
	
	}
	
	void copystr()
	{
		cout<<"\nString Copy - \n";
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
		//cout<<endl<<i<<endl;

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
		int ch;	
		cout<<"\n\nEnter the string that you want in reverse form - \n1.String 1\n2.String 2\nChoice - ";
		cin>>ch;
		int l, i, j;
		switch(ch)
		{		
		case 1:
		{
			cout<<"\n\nReverse of the String 1 is - ";
			for(l=0; str1[l]!='\0'; l++);
			for(j = l-1; j>=0; j--)
			cout<<str1[j];
		}break;
		case 2:
		{
			
			cout<<"\n\nReverse of the String 2 is - ";
			for(l=0; str2[l]!='\0'; l++);
			for(j = l-1; j>=0; j--)
			cout<<str2[j];
		}break;
		default:
		{
			cout<<"Wrong Choice...!!!\nPlease try again...!!!\n";
			reversestr();
		}
		}
	
		
	}
	
	void strlength()
	{
		int ch, l;	
		cout<<"\n\nEnter the string that you want to find length of - \n1.String 1\n2.String 2\nChoice - ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				for(l=0; str1[l]!='\0'; l++);
				cout<<"\nLength of String 1 is "<<l;
			}break;
			case 2:
			{
				for(l=0; str2[l]!='\0'; l++);
				cout<<"\nLength of String 2 is "<<l;
			}break;
			default:
			{	
				cout<<"Wrong Choice...!!!\nPlease try again...!!!\n";
				strlength();
			}
		}		
	}
	
	void substr()	
	{
		char subs[50];
		int sl, l;
		cout<<"\nEnter the substring to be checked - ";
		gets(subs);
		
		for(sl = 0; subs[sl]!='\0'; sl++);
		for(l=0; str1[l]!='\0'; l++);
		int c = 0;
		
		for(int i = 0; i<=l-sl+1; i++)
		{
			if(str1[i]==subs[0])
			{
				int m;
				for(m = 1; m<sl; m++)
				if(str1[i+m] != subs[m])
				c++;
			}
		}
		if(c==0)
		cout<<"\nEntered string is a substring of string 1";
		else
		cout<<"\nEntered string is not a substring of string 1";
	}		
};

int main()
{
	strops so;
	so.input();
	so.substr();
	so.reversestr();
	so.strequal();
	so.strlength();
	so.substr();
	so.concstr();
	so.copystr();
	
	
	
}
