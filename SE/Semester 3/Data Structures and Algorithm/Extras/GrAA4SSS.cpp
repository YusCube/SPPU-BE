/*
Group A
Assignment 4

Set A=(1,3, a, s, t, i} represent alphanumeric characters permitted to set the password of
length 4. Write C/C++ program to generate all possible passwords.


By Shiva Saran, SE-A, A-03
*/


#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class StrComb
{
	char set[6]= {'1','3','a', 's', 't', 'i'};
	char scomb[10];
	public:	int c = 0,a,n,l;
	public: void DisplayComb(int a)
	{
		n = 6;
		l = 4;	
		
		//print string when length is equal to a
		if(a==l)               
		{
			cout<<scomb;
			c++;
     		}
    		else
    		{
        		int i;
        		for(i=0;i<n;i++)
        		{
        			cout<<endl;
				scomb[a]=set[i];
				DisplayComb(a+1);
				
				
	  		}
    		}
	}
};	
	
int main()
{
	StrComb osc;
    	osc.DisplayComb(0);
	cout<<"\n\nNumber of Combinations = "<<osc.c<<"\n\n\n";
	return 0;
}




/*
	
	Variables Description ->
	
	set[] - Stores the character data 
	scomb[] - Stores the character combinations 
	a - index position of scomb[] i.e. for storing swapped each letter from the set[]
	n - Size of set[]
	l - length of the string combination to be found
	c - Counts the number of combinations done

*/

