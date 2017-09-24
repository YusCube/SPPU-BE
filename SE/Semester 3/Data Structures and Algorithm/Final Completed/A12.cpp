/* 

WRITE A C++ PROGRAM FOR STRING OPERATIONS.
	1- COPY
	2- LENGTH
	3- REVERSE
	4- CONCATENATE
	5- COMPARE
	6- SUBSTRING

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class stringoperations
{
	char str1[30], str2[30],str3[60];
	int i,j,k,l1,l2;
public:
	void getdata();
	void getdat();
	void len();
	void copy();
	void reverse();
	void compare();
	void concat();
	void substring();
	
	
};
void stringoperations::getdata()
{
	cout<<"\nEnter string \n";
	cin>>str1;
}
void stringoperations::getdat()
{
	cout<<"\nEnter first string \n";
	cin.ignore();
	gets(str1);
	cout<<"\nEnter second string \n";
	gets(str2);
}
void stringoperations::len()
{
	int c=0;
	for(i=0;str1[i]!='\0';i++)
	{
		c++;
	}
	cout<<"\nLength of string="<<c<<"\n";
}
void stringoperations::copy()
{
	
	for(i=0;str1[i]!='\0';i++)
	{
		str2[i]=str1[i];
	}
	str2[i]='\0';
	cout<<"\nCopied String="<<str2<<"\n";
}
void stringoperations::reverse()
{
	for(j=i-1,k=0;j>=0;j--,k++)
	{
		str3[k]=str1[j];
	}
	str3[k]='\0';
	cout<<"\nReverse of String="<<str3<<"\n";
}
void stringoperations::compare()
{
	int flag=0;
	for(i=0;str1[i]!='\0';i++);
	l1=i;
	for(i=0;str2[i]!='\0';i++);
	l2=i;
	if(l1==l2)
	{
		for(i=0;i<l1;i++)
		{
			if(str1[i]==str2[i])
			{
				flag=1;
				continue;
			}
			else if(str1[i]>str2[i])
			{
				flag=0;
				cout<<"\nString 1 is greater than String 2 \n";
				break;
			}
			else
			{
				flag=0;
				cout<<"\nString 1 is lesser than String 2 \n";
				break;
			}
		}
		
	}
	else
	{
		cout<<"\nString 1 is not equal String 2 \n";
	}
}
void stringoperations::concat()
{
	for(i=0;str1[i]!='\0';i++)
	{
		str3[i]=str1[i];
	}
	for(j=0;str2[j]!='\0';j++)
	{
		str3[i++]=str2[j];
	}
	str3[i]='\0';
	cout<<"\nConcatenated String is="<<str3<<" \n";
}
void stringoperations::substring()
{
	char *p;
	p=strstr(str1,str2);
	if(p==NULL)
		cout<<"\nString 2 is not substring of String 1 \n";
	else
		cout<<"\nString 2 is substring of String 1 \n";
}
int main()
{
	int ch;
	stringoperations obj;
	while(1)
	{

		cout<<" \n ************ Program Menus ********** \n";
		cout<<" \n1. Length  \n";
		cout<<" \n2. Reverse \n";
		cout<<" \n3. Copy \n";
		cout<<" \n4. Compare \n";
		cout<<" \n5. Concat \n";
		cout<<" \n6. Substring \n";
		cout<<" \n7. Exit \n";
		cin>>ch;
	

	switch(ch)
	{
		case 1:
			
			obj.getdata();
			obj.len();
			break;
			
		case 2: 
			
			obj.getdata();
			obj.reverse();
			break;
			
		case 3: 
			
			obj.getdata();
			obj.copy();
			break;
				
		case 4: 
			
			obj.getdat();
			obj.compare();
			break;
				
		case 5:
			
			obj.getdat();
			obj.concat();
			break;
			
		case 6:
			
			obj.getdat();
			obj.substring();
			break;
				
		case 7:
			
			exit(0);
			break;
					
		default:
			
			cout<<"\n Wrong Choice... Enter correct choice.";
			break;
			
	}
	}
return 0;
}

/*
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
1

Enter string 
Aniket

Length of string=6
 
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
2

Enter string 
ANIKET

Reverse of String=TEKINA
 
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
3

Enter string 
Pandey

Copied String=Pandey
 
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
4

Enter first string 
Aniket

Enter second string 
Pandey

String 1 is lesser than String 2 
 
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
5

Enter first string 
Comp

Enter second string 
uter

Concatenated String is=Computer 
 
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
6

Enter first string 
Aniket is SE student

Enter second string 
SE

String 2 is substring of String 1 
 
 ************ Program Menus ********** 
 
1. Length  
 
2. Reverse 
 
3. Copy 
 
4. Compare 
 
5. Concat 
 
6. Substring 
 
7. Exit 
7
*/

















	

