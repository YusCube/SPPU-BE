/*

Write a C++ program that creates an output file, writes information to it, closes the file and
open it again as an input file and read the information from the file.

By Shiva Saran
SE-A A-03

*/
#include<fstream>
#include<iostream>
using namespace std;


class fpro
{
	string str;
	public:
	void create()
	{
		ofstream of1, of2;
		of1.open("List of Countries.txt");
		of2.open("List of Capitals.txt");
		cout<<"How many countries do you wanna enter - ";
		int n;
		cin>>n;
		cin.ignore();
		for(int i = 0; i<n; i++)
		{
			getline(cin, str);
			of1<<str<<endl;
			cout<<" - ";
			getline(cin, str);
			of2<<str<<endl;
			
			
		}
		of1.close();
		of2.close();
	}

	void read()
	{
		ifstream rf1, rf2;
		rf1.open("List of Countries.txt");
		rf2.open("List of Capitals.txt");
		string line;
		cout<<"\nContents of File - \n";	
		while(rf1.eof()==0 && rf2.eof()==0)
		{
			getline(rf1, line);
			cout<<line;
			getline(rf2, line);
			cout<<" - "<<line<<endl;
		}
		rf1.close();
		rf2.close();
	}

};

int main()
{
	fpro op;
	op.create();
	op.read();
	return 0;
}
	op.read();
	return 0;
}
