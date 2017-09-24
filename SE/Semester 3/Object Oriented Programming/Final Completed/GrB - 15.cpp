
/*Write a menu driven program that will create a data file containing the list of telephone 
numbers in the following form 
John 23456
Ahmed 9876

Use a class object to store each set of data, access the file created and implement the following 
tasks 
I.  Determine the telephone number of specified person
II. Determine the name if telephone number is known
III. Update the telephone number, whenever there is a change. 

By Shiva Saran
SE-A A-03

*/



#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;
class person
{
	 public:
	 char name[10];
	 int phno;
	 void input_data()
	 {
		cout<<"\n Enter name:";
		cin>>name;
		cout<<"\n Enter phone number:";
		cin>>phno;
 	 }
	 void put_data()
	 {
 		cout<<setw(10)<<name<<setw(10)<<phno<<endl;
	 }
 };

 int main()
 {
	 person rec;
	 int phone,pos,choice,offset,i;
	 fstream fp;
	 ifstream in;
	 ofstream out;
	 char nm[20];
	 char ans = 'y';
	 do
	{
		 cout<<"\n Main Menu";
		 cout<<"\n 1. Read file";
		 cout<<"\n 2. Write file";
		 cout<<"\n 3. Determine name if telephone no is specified";
		 cout<<"\n 4. Determine telephone number if name is specified";
		 cout<<"\n 5. Update telephone number";
		 cout<<"\n Enter your choice :";
		 cin>> choice;
		 switch(choice)
		 {
			 case 1:
				 in.open("Menu.txt",ios::in|ios::binary);
				 cout<<"\n The contents of file are ....\n";
				 while(in.read((char *) & rec,sizeof(rec)))
				 {
					 rec.put_data();
				 }
				 in.close();	
				 break;
			 case 2:
				 rec.input_data();
				 char ch;
				 cin.get(ch);
				 out.open("Menu.txt",ios::out|ios::app|ios::binary);
				 out.write((char *) & rec ,sizeof(rec));
				 out.close();
				 break;
			 case 3:
				 cout<<"\n Enter the phone number:";
				 cin>> phone;
				 fp.open("Menu.txt", ios::ate|ios::in|ios::out|ios::binary);
				 pos=-1;
				 i=0;
				 while(fp.read((char *)&rec,sizeof(rec)))
				 {
					 if(phone==rec.phno)
					 {
						 pos=i;
						 break;
					 }
					 i++;
				 }
				 offset=pos*sizeof(rec);
				 fp.seekp(offset);
				 fp.read((char *) &rec, sizeof(rec));
				 cout<<"\n Name:"<<rec.name;
				 fp.close();
				 break;
			 case 4:
				 cout<<"\n Enter the name:";
				 cin>>nm;
				 fp.open("Menu.txt",ios::ate|ios::in|ios::out|ios::binary);
				 fp.seekg(0,ios::beg);
				 pos=-1;
				 i=0;
				 while(fp.read((char *) & rec, sizeof(rec)))
				 {
					 if((strcmp(nm,rec.name))==0)
					 {
						 pos=i;
						 break;
					 }
					 i++;
				 }
				 offset = pos * sizeof(rec);
				 fp.seekp(offset);		
				 fp.read((char *) & rec, sizeof(rec));
				 cout<<"\n telephone number:"<<rec.phno;
				 fp.close();
				 break;
			 case 5:
				 cout<<"\n Enter the name:";
				 cin>>nm;
				 fp.open("Menu.txt",ios::ate|ios::in|ios::out|ios::binary);
				 fp.seekg(0,ios::beg);
				 pos=-1;
				 i=0;
				 while(fp.read((char *) &rec,sizeof(rec)))
				{
					if ((strcmp(nm,rec.name))==0)
					{
						pos=i;
						break;
					}
					i++;
				}
				offset=pos * sizeof(rec);
				fp.seekp(offset);
				cout<<"\n current phone:"<<rec.phno;
				cout<<"\n Enter new telephone number:";
				cin>> phone;
				rec.phno=phone;
				fp.write((char *) & rec,sizeof(rec))<<flush;
				cout<<"\n Record updated \n";
				fp.seekg(0);
				while(fp.read((char *) & rec, sizeof(rec)))
				{
					rec.put_data();
				}
				fp.close();
				break;
		}
		cout<<"\n Do you want to  continue?(y/n)";
		cin>> ans;
	}while(ans=='y');
	return 0;
}








/***************************Output******************************************





[dypsoe@localhost ~]$ g++ telephone.cpp
[dypsoe@localhost ~]$ ./a.out

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :2

 Enter name:rimi

 Enter phone number:6778

 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :2

 Enter name:dolly

 Enter phone number:90889

 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :2

 Enter name:jai

 Enter phone number:08898

 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :1

 The contents of file are ....
      rimi      6778
     dolly     90889
       jai      8898

 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :3

 Enter the phone number:90889

 Name:jai
 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :4

 Enter the name:jai

 telephone number:8898
 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :5

 Enter the name:jai

 current phone:8898
 Enter new telephone number:567

 Record updated 
      rimi      6778
     dolly     90889
       jai       567

 Do you want to  continue?(y/n)y

 Main Menu
 1. Read file
 2. Write file
 3. Determine name if telephone no is specified
 4. Determine telephone number if name is specified
 5. Update telephone number
 Enter your choice :4

 Enter the name:dolly

 telephone number:90889
*/


