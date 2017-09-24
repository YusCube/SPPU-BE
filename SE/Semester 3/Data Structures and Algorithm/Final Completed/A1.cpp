/*
In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and display-

1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only cricket
4. Set of students who play only badminton
5. Number of students who play neither cricket nor badminton
   (Note- While realizing the set duplicate entries are to avoided)


By Shiva Saran
SE-A A-03
*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class sett
{
	int a[30],b[30],c[60];
	public:
	int s1,s2,m;
 	void accept()
	{
		int i;
		cout<<"\nEnter no of students in Second Year Computer Engineering:= ";
		cin>>m;

		cout<<"\nEnter size of set A students (Play Cricket):= ";
		cin>>s1;
		cout<<"\nEnter roll numbers of set A students (Play Cricket):= ";
		for(i=0;i<s1;i++)
			cin>>a[i];

		cout<<"\nEnter size of set B students (Play Badminton):= ";
		cin>>s2;
		cout<<"\nEnter roll numbers of set B students (Play Badminton):= ";
		for(i=0;i<s2;i++)
			cin>>b[i];
	}
	int compare(int t1,int c[],int k)
	{
		int i;
		for(i=0;i<k;i++)
		{
			if(t1==c[i])
			return 1;
		}
	return 0;
	}

	void Union()
	{
		int i,j,k;
		for(i=0,k=0;i<s1;i++,k++)
			c[k]=a[i];
		for(j=0;j<s2;j++)
		{
			if((compare(b[j],c,k))==0)
			{
				c[k]=b[j];
				k++;
			}
		}
		cout<<"\nSet of students who play either Cricket or Badminton or both (Union)=\n";
		for(i=0;i<k;i++)
			cout<<"\t"<<c[i];
	}

	int Intersection()
	{
		int i,j,k=0;
		for(i=0;i<s1;i++)
		{
			for(j=0;j<s2;j++)
			{
				if(a[i]==b[j])
				{
					c[k]=a[i];
					k++;
				}
			}
		}
		cout<<"\nSet of students who play both Cricket and Badminton (Intersection)=\n";
			for(i=0;i<k;i++)
				cout<<"\t"<<c[i];
  	return(k);
	}

	void onlycricket()
	{
		int i,k=0;
		for(i=0;i<s1;i++)
		{
			if((compare(a[i],b,s2))==0)
			{
				c[k]=a[i];
				k++;
			}
		}
		cout<<"\nSet of students who play only Cricket=\n";
		for(i=0;i<k;i++)
			cout<<"\t"<<c[i];
	}

	void onlybadminton()
	{
		int i,k=0;
		for(i=0;i<s2;i++)
		{
			if((compare(b[i],a,s1))==0)
			{
				c[k]=b[i];
				k++;	
			}
		}
		cout<<"\nSet of students who play only Badminton=\n";
		for(i=0;i<k;i++)
			cout<<"\t"<<c[i];
	}
	
};

	
int main()
{
	sett obj;
        int i,ch,inter;
	
	
	obj.accept();
	while(1)
	{
		cout<<"\n\n*******Program Menu*******\n";
		cout<<"\n1. Set of students who play either Cricket or Badminton or both (Union)\n";
		cout<<"\n2. Set of students who play both Cricket and Badminton (Intersection)\n";
		cout<<"\n3. Set of students who play only Cricket\n";
		cout<<"\n4. Set of students who play only Badminton\n";
		cout<<"\n5. Number of students who play neither Cricket nor Badminton\n";
		cout<<"\n6. Exit\n";
		cout<<"\nEnter ur choice:= ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				obj.Union();
				break;

			case 2:
				inter=obj.Intersection();
				break;

			case 3:
				obj.onlycricket();
				break;
			case 4:
				obj.onlybadminton();
				break;

			case 5:
                             	cout<<"\nNumber of students who play neither Cricket nor Badminton= "<<(obj.m-(obj.s1+obj.s2-inter));
			     	break;

			case 6:	
				exit(0);
		}
	}
	return 0;
}

/* 
Enter no of students in Second Year Computer Engineering:= 50

Enter size of set A students (Play Cricket):= 4

Enter roll numbers of set A students (Play Cricket):= 1 2 3 4 

Enter size of set B students (Play Badminton):= 4

Enter roll numbers of set B students (Play Badminton):= 3 4 5 6


*******Program Menu*******

1. Set of students who play either Cricket or Badminton or both (Union)

2. Set of students who play both Cricket and Badminton (Intersection)

3. Set of students who play only Cricket

4. Set of students who play only Badminton

5. Number of students who play neither Cricket nor Badminton

6. Exit

Enter ur choice:= 1

Set of students who play either Cricket or Badminton or both (Union)=
	1	2	3	4	5	6

*******Program Menu*******

1. Set of students who play either Cricket or Badminton or both (Union)

2. Set of students who play both Cricket and Badminton (Intersection)

3. Set of students who play only Cricket

4. Set of students who play only Badminton

5. Number of students who play neither Cricket nor Badminton

6. Exit

Enter ur choice:= 2

Set of students who play both Cricket and Badminton (Intersection)=
	3	4

*******Program Menu*******

1. Set of students who play either Cricket or Badminton or both (Union)

2. Set of students who play both Cricket and Badminton (Intersection)

3. Set of students who play only Cricket

4. Set of students who play only Badminton

5. Number of students who play neither Cricket nor Badminton

6. Exit

Enter ur choice:= 3

Set of students who play only Cricket=
	1	2

*******Program Menu*******

1. Set of students who play either Cricket or Badminton or both (Union)

2. Set of students who play both Cricket and Badminton (Intersection)

3. Set of students who play only Cricket

4. Set of students who play only Badminton

5. Number of students who play neither Cricket nor Badminton

6. Exit

Enter ur choice:= 4

Set of students who play only Badminton=
	5	6

*******Program Menu*******

1. Set of students who play either Cricket or Badminton or both (Union)

2. Set of students who play both Cricket and Badminton (Intersection)

3. Set of students who play only Cricket

4. Set of students who play only Badminton

5. Number of students who play neither Cricket nor Badminton

6. Exit

Enter ur choice:= 5

Number of students who play neither Cricket nor Badminton= 44

*******Program Menu*******

1. Set of students who play either Cricket or Badminton or both (Union)

2. Set of students who play both Cricket and Badminton (Intersection)

3. Set of students who play only Cricket

4. Set of students who play only Badminton

5. Number of students who play neither Cricket nor Badminton

6. Exit

Enter ur choice:= 6


*/

