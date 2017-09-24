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


*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


class books
{
	protected:
	
	char author[100], title[100], publisher[100];
	int price, quan;
	
	public:
	void inventory()
	{
		cout<<"\nEnter the details of the book - ";
		cout<<"\nBook Title: ";
		gets(title);
		cout<<"Author: ";
		gets(author);
		cout<<"Publisher: ";
		gets(publisher);
		cout<<"Price: Rs.";	
		cin>>price;	
		cin.ignore();
		cout<<"\nQuantity: ";
		cin>>quan;
		cin.ignore();

	}
	
	void display(int ch)
	{
		switch(ch)
		{
			case 1: 
			//cout<<"Inventory Details - \n";
			puts(title);
			cout<<setw[8];
			puts(author);
			cout<<setw[8];
			puts(publisher);
			cout<<setw[8];
			cout<<price;
			cout<<setw[8];
			cout<<quan;
			break;
		
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

	void requestition()
	{
		
		
			
	
