#include<iostream>
using namespace std;
int main()
{
	int an = 0;	
	for(int i = 1; i<=5000; i++)
	{

	int a = i;
	int temp, q, r, amst = 0;
	temp = a;
	do
	{
		q = temp/10;
		r = temp%10;
		temp = q;
		amst = amst+(r*r*r);
	}while(q!=0);
	if(a==amst)
	{an++;
	}
	cout<<"\n Number of Armstrong Numbers betweem 1 - 5000 are "<<an;
	return(1);
}

