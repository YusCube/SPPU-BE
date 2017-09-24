/*
Group A
Assignment 2

Write C/C++ program to store marks scored for first test of subject 'Data Structures and
Algorithms' for N students. Compute
1. The average score of class
2. Highest score and lowest score of class
3. Marks scored by most of the students
4. list of students who were absent for the test

*/


#include<iostream>
#include<cstdlib>
using namespace std;

class DSMarks
{
	public:	
	int roll, marks;
	char status;
	
	public:
	DSMarks()
	{
		static int c;
		c++;
		roll = c;
		status = 'A';
		marks = 0;	
	}

	void accept()
	{
		cout<<"Enter marks - ";
		cin>>marks;
		status = 'P';
	}
		
	void display()
	{
		cout<<"\t\t"<<roll<<"\t\t"<<marks<<"\t\t"<<status<<endl;		
	}
};

int main()
{
	int ch, total, rl, max = -1, min = 100, pass = 60, c = 0;
	long sum = 0;
	
	DSMarks ds[60];
	
	cout<<"Enter the number of students present for the test - ";
	cin>>total;
	cout<<"\nEnter the database - ";

	for(int i = 0; i<total; i++)
	{
		cout<<"\nRoll Number - ";
		cin>>rl;
		ds[rl-1].accept();
	}

	cout<<"\n\nData Structures Class Marksheet\n\n";	
	cout<<"\tRoll No.\t\tMarks\t\tStatus\n";
	for(int i = 0; i<60; i++)
	ds[i].display();
	
	while(ch!=5)
	{
	
	cout<<"\n\n--------------Data Structures Database---------------";
	cout<<endl<<"1. Average of the class\n2. Highest score and lowest score of class\n3. Marks scored by most of the students\n4. list of students who were absent for the test\n5. Exit\n\nChoice - ";
	cin>>ch;

	switch(ch)
	{
		case 1:
			for(int i = 0; i<60; i++)
			{
				if(ds[i].status=='P')
				sum+=ds[i].marks;
			}
			
			cout<<"\nAverage of the class is "<<sum/total;
			break;

		case 2:
			for(int i = 0; i<60; i++)
			{
				if(ds[i].status=='P')
				{
					if(ds[i].marks>max)
					max = ds[i].marks;
					else if(ds[i].marks<min)
					min = ds[i].marks;
				}
					
			}
			cout<<"\nHighest Score of the class = "<<max;
			cout<<"\nLowest Score of the class = "<<min;
			break;

		case 3:
			cout<<"\nMarks scored by most of the students are - \n";
			cout<<"\tRoll No.\t\tMarks\t\tStatus\n";
			for(int i = 0; i<60; i++)
			{
				if(ds[i].status=='P' && ds[i].marks>=pass)
				ds[i].display();
			}
			break;
	
		case 4:
			cout<<"\nList of students who were absent - \n";
			cout<<"\tRoll No.\t\tMarks\t\tStatus\n";
			for(int i = 0; i<60; i++)
			{
				if(ds[i].status=='A')
				{
					ds[i].display(); c++;
				}
			}
			cout<<"\n\nNUmber of students absent - "<<c;
			break;
		
		case 5: cout<<"\n\nProgram Terminated....\n\n"; exit(0);
			
		default: cout<<"\n\nWrong option...\nPlease Try again...\n";
	}
	}

				
	return 0;
}
