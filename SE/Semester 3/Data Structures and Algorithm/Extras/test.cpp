#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


class StrComb
{
	char set[6][30];
	char scomb[6][30];
	public:	int c,a,n,l,i;
	StrComb()
	{
		c = 0;
		for(i=0; i<6; i++)
		{
			cin>>set[i];
		}
	}  
 
	void DisplayComb(int a)
	{
		n = 6;
		l = 3;	
		
		//print string when length is equal to a
		if(a==l)               
		{
			for(int x=0;x<n;x++)
			cout<<scomb[x];
			c++;
     		}
    		else
    		{
        		int j;
        		for(i=0;i<n;i++)
			{
        			cout<<endl;
				if(scomb[a]!=set[i])
				strcpy(scomb[a],set[i]);
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


	
