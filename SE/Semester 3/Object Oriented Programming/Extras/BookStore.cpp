/*
Group A
Assignment 12


A book shop maintains the inventory of books that are being sold at the shop. The list
includes details such as author, title, price, publisher and stock position.

Whenever a customer wants a book, the sales person inputs the title and author and the system searches
the list and displays whether it is available or not.
If it is not, an appropriate message is displayed. If it is, then the system displays the book details and requests for the number of
copies required. If the requested copies book details and requests for the number of copies
required.

If the requested copies are available, the total cost of the requested copies is
displayed; otherwise the message "Required copies not in stock" is displayed.

Design a system using a class called books with suitable member functions and Constructors. Use
new operator in constructors to allocate memory space required. Implement C++ program
for the system.

By Shiva Saran, SE-A, A-03
*/

#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;


class BookShop
{
	public:
	
	char *author, *title; string publisher;
	int price, quan;

	BookShop()
	{
		author = new char[100];
		title = new char[100];
		//publisher = new char[100];
		
	}
	
	public:
	void inventory()
	{
		cout<<"\nEnter the details of the book - ";
		cout<<"\nBook Title: ";
		cin.getline(title, 100);
		cout<<"Author: ";
		cin.getline(author, 100);
		cout<<"Publisher: ";
		getline(cin, publisher);
		cout<<"Price: Rs.";	
		cin>>price;	
		cin.ignore();
		cout<<"Quantity: ";
		cin>>quan;
		cin.ignore();

	}
	
	void display(int k)
	{
			cout<<k+1<<".";
			cout<<"\t";
			cout<<title;
			cout<<"\t"; //setw(8);
			cout<<author;
			cout<<"\t"; //setw(8);
			cout<<publisher;
			cout<<"\t\t"; //setw(8);
			cout<<price;
			cout<<"\t"; //setw(8);
			cout<<quan;
			cout<<endl;
		
		
	}

	int search(char *name)
	{
		int check;
		check = strcmp (title, name);
		if(check == 0)
		return 1;
		else
		return 0;
	}

	void requestition(int x)
	{
		int bc = 0, total;		
		cout<<"\nBook found...!!!";
		cout<<endl<<endl<<"\tTitle\t\tAuthor\t\tPublisher\tPrice\tQuantity"<<endl;	
		display(x);
		cout<<endl<<"How many number of copies required - ";
		cin>>bc;
		
		total = bc*price;	
		if(bc <= quan)
		{
			cout<<"\nRequested copies are available...\nThe total cost of the requested copies is Rs. "<<total;
		}
		else
		cout<<"\nRequired copies not in stock :(\nEstimated cost of the books - Rs. "<<total;
	}

};

int main()
{
	int nb, flag = 1, bc = 0, total, ch;
	char ser[100];
	cout<<"\n\n\nInventory Details\n";
	cout<<"Enter the number of books that you wanna enter - ";	
	cin>>nb;
	
	cin.ignore();
	
	BookShop *ob[nb];
	
	for(int i = 0; i<nb; i++)
	{
		ob[i] = new BookShop;
		ob[i] -> inventory();
	}
	
	//system("gnome-cls");

	while(ch!=3)
	{
		cout<<"\n\n----------Book Shop Menu----------\n1. Display Inventory\n2. Search and get estimation\n3. Exit\n\nChoice - ";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
			case 1:
			cout<<"Inventory Details - \n";
			//cout<<endl<<setw(10)<<"Title"<<setw(10)<<"Author"; cout<<setw(10)<<"Publisher"<<setw(10)<<"Price"; cout<<setw	(10)<<"Quantity"<<endl;
			cout<<endl<<"\tTitle\t\tAuthor\t\tPublisher\tPrice\tQuantity"<<endl;	
			for(int i = 0; i<nb; i++)
			{
				ob[i] -> display(i);
			}
			break;

	
			case 2:
			cout<<endl<<"Enter the book title to be searched - ";
			cin.getline(ser, 100);
			for(int i = 0; i<nb; i++)
			{
				flag = ob[i] -> search(ser);
				if(flag==1)
				{
					ob[i] -> requestition(i);
					break;
				}
			}
			if(flag!=1)
			cout<<"\nBook not found...\nPlease try again...\nP.S. - Search Input is case senstitve :P\n\n";
			break;

			case 3:
			cout<<"\n\nProgram Terminated....!!!\n\n\n\n";break;

			default:
			cout<<"\n\nWrong Option...!!!\nPlease Try Again...\n\n";
	
		}
	}

	return 0;
}
		
		
			
	
