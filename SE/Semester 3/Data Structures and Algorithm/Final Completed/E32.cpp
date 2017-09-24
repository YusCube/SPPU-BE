/*

Write C++ program to store roll numbers of student in array who attended training
program in random order. Write function for searching whether particular student
attended training program or not using linear search and sentinel search.

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class search
{
	int a[30];
	public:
	int n,target;
	void accept()
	{
		int i;
		cout<<"\nEnter the no of elements of array\n";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cout<<"\nEnter the element\n";
			cin>>a[i];
		}
		cout<<"\nEnter element to be searched\n";
		cin>>target;
	}

	int sentinel()
	{
		int i=0;
		a[n]=target;
		while(a[i]!=target)
			i++;
		if(i!=n)
			return (i+1);
	return -1;
	}

	int linear()
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(target==a[i])
			{
				return(i+1);
			}
		}
		return -1;
	}

	int fibo(int n)
	{
		if(n==0||n==1)
			return 1;
		else
			return(fibo(n-1)+fibo(n-2));
	}


	int fibonacci()
	{
		int f1,f2,t,mid,j,f;
		j=1;
		while(fibo(j)<=n)
		{
			j++;
		}
		f=fibo(j);
		f1=fibo(j-2);
		f2=fibo(j-3);
		mid=n-f1+1;
		while(target!=a[mid])
		{
			if(mid<0||target>a[mid])
			{
				if(f1==1)
					return -1;
				mid=mid+f2;
				f1=f1-f2;
				f2=f2-f1;
			}
			else
			{
				if(f2==0)
					return -1;
				mid=mid-f2;
				t=f1-f2;
				f1=f2;
				f2=t;
			}
		}
		return mid+1;
	}

	int binary()
	{
		int lb=0,ub=n-1,mid=(lb+ub)/2;
		for(mid=(lb+ub)/2;lb<=ub;mid=(lb+ub)/2)
		{
			if(a[mid]==target)
				return(mid+1);
			else if(target<a[mid])
				ub=mid-1;
			else if(target>a[mid])
				lb=mid+1;
		}
		return 0;
	}
};

int main()
{
	search obj;
	int ch,pos;
	while(1)
	{
		cout<<"\n**********PROGRAM MENUS**********\n";
		cout<<"\n1-LINEAR AND SENTINEL SEARCH\n";
		cout<<"\n2-BINARY AND FIBONACCI SEARCH\n";
		cout<<"\n3-EXIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
					obj.accept();
					cout<<"\nUSING LINEAR SEARCH\n";
					pos=obj.linear();
					if(pos==(-1))
					{
						cout<<"\nElement is not present\n";
					}
					else
					{
						cout<<"\nElement found at "<<pos<<" position\n";
					}
					cout<<"\nUSING SENTINEL SEARCH\n";
					pos=obj.sentinel();
					if(pos==(-1))
					{
						cout<<"\nElement is not present\n";
					}
					else
					{
						cout<<"\nElement found at "<<pos<<" position\n";
					}
				break;
			case 2:
					obj.accept();
					cout<<"\nUSING FIBONACCI SEARCH\n";
					pos=obj.fibonacci();
					if(pos==(-1))
					{
						cout<<"\nElement is not present\n";
					}
					else
					{
						cout<<"\nElement found at "<<pos<<" position\n";
					}
					cout<<"\nUSING BINARY SEARCH\n";
					pos=obj.binary();
					if(pos==0)
					{
						cout<<"\nElement is not present\n";
					}
					else
					{
						cout<<"\nElement found at "<<pos<<" position\n";
					}
					
				break;
			case 3:
					exit(0);
		}
	}
return 0;
}

/*
**********PROGRAM MENUS**********

1-LINEAR AND SENTINEL SEARCH

2-BINARY AND FIBONACCI SEARCH

3-EXIT
1

Enter the no of elements of array
5

Enter the element
1

Enter the element
2

Enter the element
3

Enter the element
4

Enter the element
5

Enter element to be searched
4

USING LINEAR SEARCH

Element found at 4 position

USING SENTINEL SEARCH

Element found at 4 position

**********PROGRAM MENUS**********

1-LINEAR AND SENTINEL SEARCH

2-BINARY AND FIBONACCI SEARCH

3-EXIT
2

Enter the no of elements of array
5

Enter the element
3

Enter the element
12

Enter the element
21

Enter the element
27

Enter the element
37

Enter element to be searched
27

USING FIBONACCI SEARCH

Element found at 4 position

USING BINARY SEARCH

Element found at 4 position

**********PROGRAM MENUS**********

1-LINEAR AND SENTINEL SEARCH

2-BINARY AND FIBONACCI SEARCH

3-EXIT
1

Enter the no of elements of array
3

Enter the element
2

Enter the element
5

Enter the element
1

Enter element to be searched
4

USING LINEAR SEARCH

Element is not present

USING SENTINEL SEARCH

Element is not present

**********PROGRAM MENUS**********

1-LINEAR AND SENTINEL SEARCH

2-BINARY AND FIBONACCI SEARCH

3-EXIT
3

*/
					



