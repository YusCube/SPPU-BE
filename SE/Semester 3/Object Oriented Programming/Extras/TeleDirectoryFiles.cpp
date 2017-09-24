/*

Write a menu driven program that will create a data file containing the list of telephone
numbers in the following form
John 23456
Ahmed 9876
........... .........

Use a class object to store each set of data, access the file created and implement the following
tasks
1. Determine the telephone number of specified person
2. Determine the name if telephone number is known
3. Update the telephone number, whenever there is a change.

*/

#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;


class TeleDirectoryFiles 
{
	string str;
	string line;
	long ph;
	
	public:
	void create()
	{
		ofstream of1 ;
		of1.open("Telephone Directory.txt", ios::out |ios::app| ios::binary);
		cout<<"Enter Name- ";
		getline(cin, str);
		cout<<"Enter Phone Number - ";
		cin>>ph;
		of1<<"\t\t"<<"Name"<<setw(35)<<"Phone Number\n";	
		of1<<"\t\t"<<str<<setw(25)<<ph<<endl;;
		of1.close();
	}

	void read()
	{
		ifstream rf1;
		rf1.open("Telephone Directory.txt", ios::in | ios::binary);
		string line;
		long no;
		cout<<"Telephone Directory - \n";		
		while(rf1.eof()==0)
		{
			getline(rf1, line);
		cout<<rf1;
		cout<<endl;
			
					
		}
		rf1.close();
	}
	
	string search(string name)
	{
		int f = 0;
		ifstream rf1;
		rf1.open("Telephone Directory.txt", ios::in | ios::binary);
		
		cout<<"Telephone Directory - \n";		
		while(rf1.eof()==0)
		{
			getline(rf1, line);
			if(line==name)
			{
				f = 1;
				break;
				
			}		
					
		}
		rf1.close();
		if(f==1)
		return line;
		else
		return 0;
	}
			
	
};

int main()
{
	int ch;
	ofstream of ;
	of2.open("Telephone Directory.txt", ios::binary);
	of<<"\t\t"<<"Name"<<setw(35)<<"Phone Number\n";	
	of.close();
	
	TeleDirectoryFiles  op;
	
	
	while(1)
	{
	cout<<"\nTelephone Directory - \n1. Enter record\n2. Display Records\n3. Search Phone Number\n4. Search Name\n5. Update Phone Number\n6. Exit\n\nChoice - ";
	cin<<ch; 
	switch(ch)
	{
		case 1: 
			{
				op.create();
			}

		case 2:
			{
				op.read();
			}
	
		case 3: 
			{
				string name;
				cout<<"\nEnter name whose Phone Number is to be searched - ";
				getline(cin, name);
				if(op.search(name)==name)
				{
						cout<<"Record found....\n"<<op.search(name);
				}
				else
				cout<<"\nRecord not found";
			}
		}
	}	

	return 0;
}
	
