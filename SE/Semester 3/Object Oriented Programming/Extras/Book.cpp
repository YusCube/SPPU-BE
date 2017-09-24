/*A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, prize, publisher, and stock information. Whenevr a customer wants a book the sales person inputs the writer and author and the system searches add  displays wether it is available or not. If it is not, an appropriate message will be displayed. If it is, then the system displays the book list and reference for the number of copies required.If the requested copies book details and request for the number of copies required. If the requested copies are available, tyhe total cost of requested copies are displayed otherwise the message required copies not in stock is displayed. Design a system using a class called vbook with suitable member function and contructor,. Use new operator in constructor to allocate  memory space required. IMplement C++ program for the sytem.*/   
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class book
{
	public:char author[30], title[15], publisher[15],t[20];
	       int prize,si,i,n;
               
             book()
		{
		
                }	
		void get()
		{ 
  	 	  cout<<"\nEnter the number of books you want to enter:";cin>>n;
		  for(i=0;i<n;i++)		 
		     {
  		      cout<<"\nEnter the name of ["<<(i+1)<<"] book:";cin>>title;
		      cout<<"\nEnter the name of its author :";cin>>author;
		      cout<<"\nEnter the name of its Publisher:";cin>>publisher;
		      cout<<"\nEnter prize:";cin>>prize;
		      cout<<"\nENter the number of books available:";cin>>si;
		     }
		}
		
		
		void disp()
		{ 
		  for(i=0;i<n;i++)		 
		     {
  		      cout<<"\n["<<(i+1)<<"]:\n Book name"<<title;
		      cout<<"\nauthor :"<<author;
		      cout<<"\nPrize:"<<prize;
		      cout<<"\nPublisher:"<<publisher;
		      cout<<"\nNumber of books available:"<<si;
		     }
		}
	
               void search()
		{
		  for(i=0;i<n;i++ )  
		   {
                    if(strcmp(t,title)==0)		 
		      {
  		       cout<<"\nBook Name:"<<title;
		       cout<<"\nAuthor:"<<author;
		       cout<<"\nEnter prize:"<<prize;
		       cout<<"\nNumber of books available:"<<si;
		      }
		  }
		    else
	             {
                      cout<<"\n NO such book available";
                      cout<<"\n "<<title<<" is required in the library";		 
                     }
		}

};

int main()
{
 book ob;
 ob.get();
 char t[20];
 int j,flag=0;
 cout<<"\n\t*********MENU*********";
 cout<<"\n Enter 1  to display the information of all books:";  
 cout<<"\nEnter 2 to search any book";
 cout<<"\nEnter 3 for Exit";
 cin>>j;
 while(flag==0)
 { 
  switch(j) 
    {
      case 1:  
               ob.disp();
               break;
            
      case 2: 
              cout<<"\nEnter title of book you want to search:";
              cin>>t;
              ob.search();break;
   
  //case 3:cout<<"\nEnter 3 for requesition"; 

     case 3: flag=1;
             exit(0); 
             break; 
   
     default:cout<<"\nEnter correct choice:";
             break;   
   }     
 } 
return 0;

}
