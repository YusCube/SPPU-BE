/*
Group A
Assignment 5


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

Construct the Database with suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member functions,
friend class, this pointer, inline code and dynamic memory allocation operators-new and
delete.

By Shiva Saran
SE A-03

*/


#include <iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class database
{
	char name[50],cl[50],div[15],dob[15],blood[5],address[30],dlic[50];
	int rollno,lic;
	long int mobile;

public:
	static int record;
	static void disprecord()
	{
		cout<<"No. of records="<<record;
	}
	database()
	{
		strcpy(name,"abc");
		strcpy(cl,"SE");
		strcpy(div,"A");
		strcpy(dob,"01-01-2014");
		strcpy(blood,"AB+");
		strcpy(address,"pune");
		strcpy(dlic,"a123");
		rollno=lic=mobile=0;

	}
	database(database *s4)
		{
			strcpy(name,s4->name);
			strcpy(cl,s4->cl);
			strcpy(div,s4->div);
			strcpy(dob,s4->dob);
			strcpy(blood,s4->blood);
			strcpy(address,s4->address);
			strcpy(dlic,s4->dlic);
			rollno=s4->rollno;
			lic=s4->lic;
			mobile=s4->mobile;
		}
	void accept()
	{
		cout<<"\nEnter name\nRollno\nClass\nDivision\nDOB\nBlood group\naddress\nInsurance policy no\nmobile no\ndriving licence no\n ";
		cin>>name>>"\n">>rollno>>"\n">>cl>>"\n">>div>>"\n">>dob>>"\n">>blood>>"\n">>address>>"\n">>lic>>"\n">>mobile>>"\n">>dlic;
	    	++record;
	}

	friend void display(database d);
        inline int A()
      	  {

      		  cout<<"inline function";
      	  }


	~database()
	{
		 cout<<"\n Object is destroyed..... ";
	}
};	
	void display(database d)
	{
		cout<<d.name<<setw(20)<<d.cl<<setw(20)<<d.div<<setw(20)<<d.dob<<setw(20)<<d.blood<<setw(20)<<d.address<<setw(20)<<d.lic<<setw(20)<<d.mobile<<setw(20)<<d.dlic<<"\n";
	}
                                                                                                                                                                                                                                


int database::record;

int main() 
{
	database s1,s2,*s3[20];

	int i,n,ch;

		while(1)
		{
		 cout<<"\n\n\t***** MENU ******";
		 cout<<"\n1.Default values";
		 cout<<"\n2.Copy Constructor values";
		 cout<<"\n3.Accept Records";
		 cout<<"\n4.Display All Records";
		 cout<<"\n5.Delete All Records";
		 cout<<"\n6. Exit"<<endl<<"Enter ur choice:";
		 cin>>ch;

		switch(ch)
		{
		case 1:
			cout<<"name"<<setw(10)<<"Roll No"<<setw(10)<<"Class"<<setw(10)<<"Division"<<setw(10)<<"Date_of_birth"<<setw(10)<<"blood group"<<setw(10)<<"address"<<setw(10)<<"Insurance Policy"<<setw(10)<<"mobile no"<<setw(10)<<"driving licence no"<<"\n";

			display(s1);
		break;
		case 2:
			cout<<"name"<<setw(10)<<"Roll No"<<setw(10)<<"Class"<<setw(10)<<"Division"<<setw(10)<<"Date_of_birth"<<setw(10)<<"blood group"<<setw(10)<<"address"<<setw(10)<<"Insurance Policy"<<setw(10)<<"mobile no"<<setw(10)<<"driving licence no"<<"\n";
			s2=database(&s1);
			display(s2);
		break;
		case 3:
		   cout<<"\nEnter no. of details you want to enter: ";
		   cin>>n;

		for(i=0;i<n;i++)
		  {
			s3[i]=new database;
			s3[i]->accept();
		  }
		break;

		case 4:
			cout<<"name"<<setw(10)<<"Roll No"<<setw(10)<<"Class"<<setw(10)<<"Division"<<setw(10)<<"Date_of_birth"<<setw(10)<<"blood group"<<setw(10)<<"address"<<setw(10)<<"Insurance Policy"<<setw(10)<<"mobile no"<<setw(10)<<"driving licence no"<<"\n";

			for(i=0;i<n;i++)
			{
			  display(s3[i]);
			}
			database::disprecord();
			s1.A();

		  break;

		case 5:
			for(i=0;i<n;i++)
			{
				delete(s3[i]);
			}
			cout<<"\nObjects Memory is deleted.....\n";
			
		break;
		}
	}
	return 0;
}




/*Output:
[student@localhost OOPPractical]$ g++ GrA - 6.cpp
[student@localhost OOPPractical]$ ./a.out

Enter First number, operator, second number - 
Input - 10/3

Result of 10/3 = 3.33333

Do you want continue...?(Yes/No) -N
*/

