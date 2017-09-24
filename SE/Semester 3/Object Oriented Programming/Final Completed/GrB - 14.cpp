/*Group B, Assignment 14
Create a user defined exception to check the following conditions and throw the exception if the
criteria doesn't meet.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned
above. If any of the condition not met then throw the exception.

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class exceptions
{
	
	int age, income;
	char city[15], vehicle[10];
	public:
	void accept()
	{
		cout<<"\nEnter your age:\n";
		cin>>age;
		cout<<"\nEnter your income:\n";
		cin>>income;
		cout<<"\nEnter your city:\n";
		cin>>city;
		cout<<"I/P: "<<city;
		cout<<"\nDo you have a vehicle?\nIf yes, how many wheels does it have?\n";
		cin>>vehicle;
		cout<<"I/P: "<<vehicle;
	}
	void check()
	{
		int count=0;
		try{
			if(age>=18 && age<=55)
			{
				count++;
			}
			else 
			throw 1;
		}
		catch(int a)
		{
			cout<<"\nAge is NOT between 18 and 55\n";
			
		}
		try{
			if((income>=50000 && income<=100000))
			{
				count++;
			}
			else
			throw 'a';
		}
		catch(char a)
		{
			cout<<"\nIncome is NOT between 50,000 and 1,00,000\n";
			
		}
		try{
			if((strcmp(city, "pune")==0)||(strcmp(city, "mumbai")==0)||(strcmp(city, "bangalore")==0)||(strcmp(city, "chennai")==0))
			{
				count++;
			}
			else
			throw 1.0;
		}
		catch(double a)
		{
			cout<<"\nYou don't live in Pune, Mumbai, Bangalore or Chennai\n";
			
			
		}
		try{
			if(strcmp(vehicle, "no")!=0)
			{
				if(strcmp(vehicle, "4")==0)
				{
					count++;
				}
			else 
			throw 1;
			}
		}
		catch(int a)
		{
			cout<<"\nYou don't have a four wheeler\n";
			
		}
		if(count==4)
			cout<<"\nYou are perfectly fine!\n";
	}
};
int main()
{
	exceptions e;
	e.accept();
	e.check();
	return 0;
}
