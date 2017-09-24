/*
Develop an Object Oriented Programming in C++ to create a database of student information system containing the following information: 
-Name
-Roll Number
-Class
-Division
-DOB
-Blood Group
-Contact Address
-Telephone number 
-Driving License Number

Construct the Database with suitable member functions
*/


#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

class StudentDatabase
{
	char name[50], div[5], DOB[15],BlGr[5], ConAdd[150] ;
	long rollno, cla, telph, drlic;
	
	public: void getdata()
	{
		cout<<"Hello student...\nPlease enter your details - \nName - ";
		gets(name);
		cout<<"Roll Number - ";
		cin>>rollno;
		cout<<"Class - ";
		cin>>cla;
		cin.ignore();
		cout<<"Division - ";
		gets(div);
		cout<<"Date of Birth - ";
		gets(DOB);
		cout<<"Blood Group - ";
		gets(BlGr);
		cout<<"Contact Address - ";
		gets(ConAdd);
		cout<<"Contact Number - ";
		cin>>telph;
		cout<<"Driving License Number - ";
		cin>>drlic;
	}

	void displaydata()
	{
		cout<<"\n\n\n\nThe details entered by you are as follows:\nName: ";
		puts(name);
		cout<<endl<<"Roll Number: "<<rollno;
		cout<<endl<<"Class "<<cla;
		cout<<endl<<"Division: ";
		puts(div);
		cout<<endl<<"Date of Birth - ";
		puts(DOB);
		cout<<endl<<"Blood Group: ";
		puts(BlGr);
		cout<<endl<<"Contact Address: ";
		puts(ConAdd);
		cout<<endl<<"Contact Number - "<<telph;
		cout<<endl<<"Driving License Number - "<<drlic;
		cout<<"\n\n\n\n\n";
			
	}
};

int main()
{
	StudentDatabase sd;
	sd.getdata();
	sd.displaydata();
	return 0;
}
	
