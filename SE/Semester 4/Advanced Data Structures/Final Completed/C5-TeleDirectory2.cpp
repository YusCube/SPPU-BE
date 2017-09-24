/* 
Group C
Assignment No.-14

Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.

*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#define MAX 10

using namespace std;
struct Database
{
  long int mobile;
  string name;
};

class  Dictionary
{
private:
	struct Database table[MAX];
	int count;
public:
	Dictionary();
	int hashfun(long int);
	void insert(int,long int, string);
	void search(int,long int);
	void delete1(int,long int);
	void display();
};
Dictionary::Dictionary()
{ 
	int i;
        count=0;
	for(i=0;i<MAX;i++)
	{
		table[i].mobile=-1;
		table[i].name="-";
	}
}

int Dictionary::hashfun(long int num)
{
	int key;
	key=num%10;
	return key;
}

void Dictionary::insert(int key,long int num, string sname)
{ 
  
  if (count==MAX)
	 cout<<"\nCan't perform Insertion..Hash Table is full!!";
  else
  {
		if(table[key].mobile==-1)
		{
		  table[key].mobile=num;
		  table[key].name=sname;
		}  
		else if(key==MAX-1 && table[key].mobile!=-1) 
	   {
	   	key=(key+1)%MAX;
		  	while(table[key].mobile!=-1)
			{     
				if(key==MAX-1)
					break;
				else
				key++;
			}
			if(table[key].mobile==-1)
			{
		  		table[key].mobile=num;
		  		table[key].name=sname;
			}  
		 }
		 
		 else 
	 	{
	        
				while(table[key].mobile!=-1)
				{   
					if(key==MAX-1 && table[key].mobile!=-1)
					{
						key=(key+1)%MAX;
					}
					else  
					key++;
				}
				if(table[key].mobile==-1)
				{
		  			table[key].mobile=num;
		  			table[key].name=sname;
				}  
	  }	

 	count ++;
	  
	
   } 		

}
void Dictionary::search(int key,long int num)
{
	int i;
	if(table[key].mobile==num)
		cout<<"\n"<<num<<" Mobile number is pesent at "<<key<< "position.";
	else
	{
		for(i=key+1; i<MAX; i++)
		{
			if(table[i].mobile==num)
			{
				cout<<"\n"<<num<<" Mobile number is pesent at "<<i<< "position.";
				break;
			}  
		}
		if(i==MAX)
		{
			for(i=0; i<key; i++)
			{
				if(table[i].mobile==num)
				{
					cout<<"\n"<<num<<" Mobile number is pesent at "<<i<< "position.";
					break;
				}  	
			}
			if(i==key)
				cout<<"\n Element is not present in Hash Table.";
		}
	}
				
}

void Dictionary::delete1(int key,long int num)
{
	int i;
	if(table[key].mobile==num)
	{
		table[key].mobile=-1;
		table[key].name="-";
		cout<<"\nMobile "<<num<<" is deleted sucessfully.";
		count--;
	}
	else
	{
		for(i=key+1; i<MAX; i++)
		{
			if(table[i].mobile==num)
			{
				table[key].mobile=-1;
				table[key].name="-";
				cout<<"\nMobile "<<num<<" is deleted sucessfully.";
				count--;
				break;
			}  
		}
		if(i==MAX)
		{
			for(i=0; i<key; i++)
			{
				if(table[i].mobile==num)
				{
					table[key].mobile=-1;
					table[key].name="-";
					cout<<"\nMobile "<<num<<" is deleted sucessfully.";
					count--;
					break;
				}  	
			}
			if(i==key)
				cout<<"\n Given Mobile Number is not present in Hash Table.";
		}
	}
				
}
void Dictionary::display()
{ 
int i;
cout<<"\n The TelePhone Directory table is.........\n";
cout<<"key\tMobile\t\tPerson Name";
for(i=0;i<MAX;i++)
	cout<<"\n"<<i<<"  "<<setw(10)<<table[i].mobile<<setw(20)<<table[i].name;

cout<<"\nTotal TelePhone Directory table Entries are= "<<count;
}

int main()
{
	int key,i,ch;
	long int num;
	string sname;
	char ans;
	Dictionary h;
	while(1)
	{
		cout<<"\n TelePhone Directory Program....";
		cout<<"\n1. Insert\n2. Delete\n3. Search\n4. Exit ";
		cout<<"\nEnter UR Choice= ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\n Enter the Mobile Number and Person Name for Insert Operation= ";
				cin>>num>>sname;
				key=h.hashfun(num);
				h.insert(key,num,sname);
				h.display();
			break;
			case 2:
				h.display();
				cout<<"\n Enter the Mobile Number for Delete Operation= ";
				cin>>num;
				key=h.hashfun(num);
				h.delete1(key,num);
				h.display();
			break;
			case 3:
				h.display();
				cout<<"\n Enter the Mobile Number for Search Operation= ";
				cin>>num;
				key=h.hashfun(num);
				h.search(key,num);
			break;
			case 4:
				exit(0);
		
		}
	}
	
		
return 0;
}

/*********************************** OUTPUT ******************************************

[shivasaran@sss-ragemachine ~]$  g++ Assign_C_14.cpp
[shivasaran@sss-ragemachine ~]$ ./a.out

 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1

 Enter the Mobile Number and Person Name for Insert Operation= 9158671333 Shiva

 The TelePhone Directory table is.........
key	Mobile		Person Name
0          -1                   -
1          -1                   -
2          -1                   -
3  9158671333               Shiva
4          -1                   -
5          -1                   -
6          -1                   -
7          -1                   -
8          -1                   -
9          -1                   -
Total TelePhone Directory table Entries are= 1
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1

 Enter the Mobile Number and Person Name for Insert Operation= 9822556169 Yogesh

 The TelePhone Directory table is.........
key	Mobile		Person Name
0          -1                   -
1          -1                   -
2          -1                   -
3  9158671333               Shiva
4          -1                   -
5          -1                   -
6          -1                   -
7          -1                   -
8          -1                   -
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 2
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1

 Enter the Mobile Number and Person Name for Insert Operation= 8421689898 Deepti

 The TelePhone Directory table is.........
key	Mobile		Person Name
0          -1                   -
1          -1                   -
2          -1                   -
3  9158671333               Shiva
4          -1                   -
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 3
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1 

 Enter the Mobile Number and Person Name for Insert Operation= 9130804062 Bharati

 The TelePhone Directory table is.........
key	Mobile		Person Name
0          -1                   -
1          -1                   -
2  9130804062             Bharati
3  9158671333               Shiva
4          -1                   -
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 4
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1

 Enter the Mobile Number and Person Name for Insert Operation= 8087477000 Shreya 

 The TelePhone Directory table is.........
key	Mobile		Person Name
0  8087477000              Shreya
1          -1                   -
2  9130804062             Bharati
3  9158671333               Shiva
4          -1                   -
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 5
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1

 Enter the Mobile Number and Person Name for Insert Operation= 7057778172 Shivani

 The TelePhone Directory table is.........
key	Mobile		Person Name
0  8087477000              Shreya
1          -1                   -
2  9130804062             Bharati
3  9158671333               Shiva
4  7057778172             Shivani
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 6
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 1

 Enter the Mobile Number and Person Name for Insert Operation= 7276030700 Nikita

 The TelePhone Directory table is.........
key	Mobile		Person Name
0  8087477000              Shreya
1  7276030700              Nikita
2  9130804062             Bharati
3  9158671333               Shiva
4  7057778172             Shivani
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 7
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 2

 The TelePhone Directory table is.........
key	Mobile		Person Name
0  8087477000              Shreya
1  7276030700              Nikita
2  9130804062             Bharati
3  9158671333               Shiva
4  7057778172             Shivani
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9  9822556169              Yogesh
Total TelePhone Directory table Entries are= 7
 Enter the Mobile Number for Delete Operation= 9822556169

Mobile 9822556169 is deleted sucessfully.
 The TelePhone Directory table is.........
key	Mobile		Person Name
0  8087477000              Shreya
1  7276030700              Nikita
2  9130804062             Bharati
3  9158671333               Shiva
4  7057778172             Shivani
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9          -1                   -
Total TelePhone Directory table Entries are= 6
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 3

 The TelePhone Directory table is.........
key	Mobile		Person Name
0  8087477000              Shreya
1  7276030700              Nikita
2  9130804062             Bharati
3  9158671333               Shiva
4  7057778172             Shivani
5          -1                   -
6          -1                   -
7          -1                   -
8  8421689898              Deepti
9          -1                   -
Total TelePhone Directory table Entries are= 6
 Enter the Mobile Number for Search Operation= 7276030700

7276030700 Mobile number is pesent at 1position.
 TelePhone Directory Program....
1. Insert
2. Delete
3. Search
4. Exit 
Enter UR Choice= 4
[shivasaran@sss-ragemachine ~]$  

*/

 
