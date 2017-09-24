/*
Name : Dhanesh. B. Sabane
Class : S.E	Div: A
Roll No.: 221056 Batch: SA4
TITLE:Develop an object oriented program in C++ to create a database of the personnel
information system containing the following information: Name, Date of Birth, Blood
group, Height, Weight, Insurance Policy, number, Contact address, telephone number,
driving license no. etc Construct the database with suitable member functions for
initializing and destroying the data viz constructor, default constructor, copy, constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete.
*/

#include<iostream>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
using namespace std;


class personnel1;

class personnel
{
	private:
		char name[50];
		char address[200];
		char dob[15];
		char bg[5];
		char license_no[20];
		float height;
		float weight;
		char insurance_no[20];
		long long telephone_no;
		personnel *head;
		personnel *link;

	public:
		static int count;
		friend class personnel1;

		personnel()
		{
			strcpy(	name,"XXX");
			strcpy(address,"XXX");
			strcpy(dob,"XXX");
			strcpy(bg,"XXX");
			strcpy(license_no,"XXX");
			height = 00.00;
			weight = 00.00;
			strcpy(insurance_no,"XXX") ;
			telephone_no = 0;
			link = NULL;
		}

		~personnel()
		{
			cout<<"The object has been destroyed!\n";
		}

		personnel *create(void)
		{
			personnel *newpersonnel;
			newpersonnel = new personnel;
			newpersonnel->link = NULL;
			return newpersonnel;
		}
}p;

class personnel1
{
	public:
		void acceptdata(void);
		personnel *search(void);
		void display(void);
		personnel *delete1(void);
		static void displaycount(void);
}p1;

int personnel::count = 0;

void personnel1 :: displaycount(void)
{
	cout<<"\nThe total count is: "<<personnel::count<<endl;
}

void personnel1 :: acceptdata(void)
{
	char ch;
	personnel *temp,*first;
	p.head = NULL;

	do
	{

	temp = p.create();

	cout<<"Enter the name of the person.\n";
	cin.ignore(256,'\n');
	cin.getline(temp->name,50);

	cout<<"Enter the address of "<<temp->name<<endl;
	cin.getline(temp->address,200);

	cout<<"Enter the date of birth of "<<temp->name<<"(DD/MM/YYYY)\n";
	cin.getline(temp->dob,15);

	cout<<"Enter the blood group of "<<temp->name<<endl;
	cin.getline(temp->bg,5);

	cout<<"Enter the height of "<<temp->name<<endl;

	while(!(cin >> temp->height))
	{
		cin.clear();
		cin.ignore(1024,'\n');
		cout<<"Invalid input! Try again.\n";
	}

	cout<<"Enter the weight of "<<temp->name<<endl;
	while(!(cin>>temp->weight))
	{
		cin.clear();
		cin.ignore(1024,'\n');
		cout<<"Invalid input! Try again.\n";
	}

	cout<<"Enter the license number of "<<temp->name<<endl;
	cin.ignore(256,'\n');
	cin.getline(temp->license_no,20);

	cout<<"Enter the insurance policy number of "<<temp->name<<endl;
	cin.getline(temp->insurance_no,20);

	cout<<"Enter the contact number of "<<temp->name<<endl;
	cout<<"(Enter 000 if not available.)\n";
	while(!(cin>>temp->telephone_no))
	{
		cin.clear();
		cin.ignore(1024,'\n');
		cout<<"Invalid input! Try again.\n";
	}

	if(p.head == NULL)
	{
		p.head = temp;
		p.head->link = NULL;
		first = p.head;
	}
	else
	{
		first->link = temp;
	}

	first = temp;
	personnel::count ++;

	cout<<"Do you want to enter new data?(Y/N)\n";
	while(!(cin>>ch))
	{
		cin.clear();
		cin.ignore(1024,'\n');
		cout<<"Invalid input! Try again.\n";
	}

	}while(ch == 'y' || ch == 'Y');

}

void personnel1 :: display(void)
{
	personnel *first;
	first = p.head;

	if(first == NULL)
	{
		cout<<"Database is empty!\n";
	}
	else
	{

		while(first->link!=NULL)
		{
			cout<<"\nName: "<<first->name<<endl;
			cout<<"Address: "<<first->address<<endl;
			cout<<"DoB: "<<first->dob<<endl;
			cout<<"Blood Group: "<<first->bg<<endl;
			cout<<"Height: "<<first->height<<endl;
			cout<<"Weight: "<<first->weight<<endl;
			cout<<"Insurance No.: "<<first->insurance_no<<endl;
			cout<<"License No.: "<<first->license_no<<endl;

			first = first->link;
		}

		cout<<"\nName: "<<first->name<<endl;
		cout<<"Address: "<<first->address<<endl;
		cout<<"DoB: "<<first->dob<<endl;
		cout<<"Blood Group: "<<first->bg<<endl;
		cout<<"Height: "<<first->height<<endl;
		cout<<"Weight: "<<first->weight<<endl;
		cout<<"Insurance No.: "<<first->insurance_no<<endl;
		cout<<"License No.: "<<first->license_no<<endl;
		}
}

personnel * personnel1:: search()
{
	personnel *first;
	first = p.head;
	char name1[50];
	char license[20];

	if(p.head == NULL)
	{
		cout<<"Database empty!\n";
	}
	else
	{

		cout<<"Enter the name of the person you want to search\n";
		cin.ignore(256,'\n');
		cin.getline(name1,50);

		cout<<"Enter the license number of "<<name1<<endl;
		cin.getline(license,20);
		while(first->link!=NULL)
		{
			if(strcmp(first->name,name1)==0)
			{
				if(strcmp(first->license_no,license) == 0)
				{
					cout<<"\nFound!\n";
					cout<<"\nName: "<<first->name<<endl;
					cout<<"Address: "<<first->address<<endl;
					cout<<"DoB: "<<first->dob<<endl;
					cout<<"Blood Group: "<<first->bg<<endl;
					cout<<"Height: "<<first->height<<endl;
					cout<<"Weight: "<<first->weight<<endl;
					cout<<"Insurance No.: "<<first->insurance_no<<endl;
					cout<<"License No.: "<<first->license_no<<endl;
					break;
				}
			}
			else
			{
				first=first->link;
			}
		}
		if(strcmp(first->name,name1)==0)
				{
					if(strcmp(first->license_no,license) == 0)
					{
						cout<<"\nFound!\n";
						cout<<"\nName: "<<first->name<<endl;
						cout<<"Address: "<<first->address<<endl;
						cout<<"DoB: "<<first->dob<<endl;
						cout<<"Blood Group: "<<first->bg<<endl;
						cout<<"Height: "<<first->height<<endl;
						cout<<"Weight: "<<first->weight<<endl;
						cout<<"Insurance No.: "<<first->insurance_no<<endl;
						cout<<"License No.: "<<first->license_no<<endl;
					}
			}
			else
			{
				cout<<"Personnel data not available in database.\n";
			}
		}

	return first;
}


personnel *personnel1 :: delete1(void)
{
	personnel *temp2,*temp1,*first1;
	temp1 = p.head;

	if(temp1 == NULL)
	{
		cout<<"Database is empty!";
	}
	else
	{
		first1 = search();
		if(first1 == temp1)
		{
			first1 = temp1->link;
			p.head = first1;
			delete temp1;
			p.count --;
		}
		else
		{
			while(temp1->link!=first1)
			{
				temp1 = temp1->link;
			}

			temp2 = first1->link;
			temp1->link = temp2;

			delete first1;
			p.count--;

		}
	}

	return p.head;
}
int main(void)
{
	personnel *temp;
	int ch;
	cout<<"=====***===== PERSONNEL DATABASE =====***=====\n";
	while(1)
	{
		cout<<"\n1.Create\n2.Display\n3.Search\n4.Delete\n5.Display total database count\n6.Exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1: p1.acceptdata();
		break;

		case 2: p1.display();
		break;

		case 3: temp = p1.search();
		break;

		case 4: temp = p1.delete1();
		break;

		case 5: p1.displaycount();
		break;

		case 6: cout<<"Done!\n";
				exit(0);

		}
	}

	return 0;
}


