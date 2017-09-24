#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
class Student
{
	char name[50];
	int rollno;
	public: void getdata()
	{
		cout<<"Hello student...\nPlease enter your details - \nName - ";
		gets(name);
		cout<<"Roll Number - ";
		cin>>rollno;
	}
	void printdata()
	{
		cout<<endl<<"Details of the student are - \nName: "<<name<<"\nRoll Number - "<<rollno;
	}
};
int main()
{
	Student os;
	os.getdata();
	os.printdata();
	return 0;
}
