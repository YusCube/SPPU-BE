/*Write a C/C++ program to store marks scored for first test of subject, data structure and algorithm for N students.
   Compute 
	1- Average score of class
	2- Highest score and lowest score of class
	3- Marks scored by most of the students
	4- List of students who were absent for the test 

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class DSATest
{
	public:
	int roll;
	int marks;
	char status;
DSATest()
{
	static int c;
	c++;
	roll=c;
	marks=0;
	status='A';
}
void accept(int);
void display();
};
void DSATest::accept(int troll)
{
	roll=troll;
	cout<<"\nEnter the marks\n";
	cin>>marks;
	status='P';
}
void DSATest::display()
{
	cout<<"\t"<<roll<<"\t"<<marks<<"\t"<<status<<"\n";
}

int main()
{
	DSATest obj[60];
	int i, ch, n, count=0, troll, max=-1, min=100, sum=0;
	while(1)
	{
	cout<<"\nProgram Menus";
	cout<<"\n1- Accept and Display Data";
	cout<<"\n2- Average score of class";
	cout<<"\n3- Highest score and lowest score of class";
	cout<<"\n4- Marks scored by most of the students";
	cout<<"\n5- List of students absent for the test";
	cout<<"\n6- Exit\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter the no of students \n";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"\nEnter the roll no: \n";
				cin>>troll;
				obj[troll-1].accept(troll);
			}
			cout<<"\tRoll No\tMarks\tStatus\n";
			for(i=0;i<60;i++)
			obj[i].display();
			break;
		case 2:
			cout<<"\nAverage Score of class :\n"; 
			for(i=0;i<60;i++)
			{
				if(obj[i].status=='P')
				{
				count++;
				sum=sum+obj[i].marks;
				}
			}
			cout<<(sum/count);
			break;
		case 3:
			for(i=0;i<60;i++)
			{
				if(obj[i].marks>max)
				max=obj[i].marks;
				if(obj[i].marks<min)
				min=obj[i].marks;
			}
			cout<<"\nHighest Score="<<max<<"\n";
			cout<<"\nLowest Score="<<min<<"\n";
			break;
		case 4:
			cout<<"\tRoll No\tMarks\tStatus\n";
			for(i=0;i<60;i++)
			{
				if(obj[i].marks>=40)
				obj[i].display();
			}
			break;
		case 5:
			cout<<"\tRoll No\tMarks\tStatus\n";
			for(i=0;i<60;i++)
			{
				if(obj[i].status=='A')
				obj[i].display();
			}
			break;
		case 6:
			exit(0);
			break;
	}
	}
	return 0;
}
			
/*
Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
5
	Roll No	Marks	Status
	1	0	A
	2	0	A
	3	0	A
	4	0	A
	5	0	A
	6	0	A
	7	0	A
	8	0	A
	9	0	A
	10	0	A
	11	0	A
	12	0	A
	13	0	A
	14	0	A
	15	0	A
	16	0	A
	17	0	A
	18	0	A
	19	0	A
	20	0	A
	21	0	A
	22	0	A
	23	0	A
	24	0	A
	25	0	A
	26	0	A
	27	0	A
	28	0	A
	29	0	A
	30	0	A
	31	0	A
	32	0	A
	33	0	A
	34	0	A
	35	0	A
	36	0	A
	37	0	A
	38	0	A
	39	0	A
	40	0	A
	41	0	A
	42	0	A
	43	0	A
	44	0	A
	45	0	A
	46	0	A
	47	0	A
	48	0	A
	49	0	A
	50	0	A
	51	0	A
	52	0	A
	53	0	A
	54	0	A
	55	0	A
	56	0	A
	57	0	A
	58	0	A
	59	0	A
	60	0	A

Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
1

Enter the no of students 
10

Enter the roll no: 
3

Enter the marks
86

Enter the roll no: 
12

Enter the marks
76

Enter the roll no: 
21

Enter the marks
96

Enter the roll no: 
26

Enter the marks
38

Enter the roll no: 
27

Enter the marks
88

Enter the roll no: 
35

Enter the marks
31

Enter the roll no: 
40

Enter the marks
51

Enter the roll no: 
59

Enter the marks
80

Enter the roll no: 
48

Enter the marks
21

Enter the roll no: 
14

Enter the marks
90
	Roll No	Marks	Status
	1	0	A
	2	0	A
	3	86	P
	4	0	A
	5	0	A
	6	0	A
	7	0	A
	8	0	A
	9	0	A
	10	0	A
	11	0	A
	12	76	P
	13	0	A
	14	90	P
	15	0	A
	16	0	A
	17	0	A
	18	0	A
	19	0	A
	20	0	A
	21	96	P
	22	0	A
	23	0	A
	24	0	A
	25	0	A
	26	38	P
	27	88	P
	28	0	A
	29	0	A
	30	0	A
	31	0	A
	32	0	A
	33	0	A
	34	0	A
	35	31	P
	36	0	A
	37	0	A
	38	0	A
	39	0	A
	40	51	P
	41	0	A
	42	0	A
	43	0	A
	44	0	A
	45	0	A
	46	0	A
	47	0	A
	48	21	P
	49	0	A
	50	0	A
	51	0	A
	52	0	A
	53	0	A
	54	0	A
	55	0	A
	56	0	A
	57	0	A
	58	0	A
	59	80	P
	60	0	A

Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
2

Average Score of class :
65
Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
3

Highest Score=96

Lowest Score=0

Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
4
	Roll No	Marks	Status
	3	86	P
	12	76	P
	14	90	P
	21	96	P
	27	88	P
	40	51	P
	59	80	P

Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
5
	Roll No	Marks	Status
	1	0	A
	2	0	A
	4	0	A
	5	0	A
	6	0	A
	7	0	A
	8	0	A
	9	0	A
	10	0	A
	11	0	A
	13	0	A
	15	0	A
	16	0	A
	17	0	A
	18	0	A
	19	0	A
	20	0	A
	22	0	A
	23	0	A
	24	0	A
	25	0	A
	28	0	A
	29	0	A
	30	0	A
	31	0	A
	32	0	A
	33	0	A
	34	0	A
	36	0	A
	37	0	A
	38	0	A
	39	0	A
	41	0	A
	42	0	A
	43	0	A
	44	0	A
	45	0	A
	46	0	A
	47	0	A
	49	0	A
	50	0	A
	51	0	A
	52	0	A
	53	0	A
	54	0	A
	55	0	A
	56	0	A
	57	0	A
	58	0	A
	60	0	A

Program Menus
1- Accept and Display Data
2- Average score of class
3- Highest score and lowest score of class
4- Marks scored by most of the students
5- List of students absent for the test
6- Exit
6
*/























