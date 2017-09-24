#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


class node
{
	string name;
	string sec;
	string place;
	int marks;
	
	int no;
	node *next;
	
	public:
	node *create(node *head)
	{
		head=new node;
  		head->no=0;
		head->next=NULL;
  
  		return(head);
	}
	
	
	void save(node * head)
	{
		node * nw,*temp;
		nw=new node;
  		nw->next=NULL;
  		
  		
	  	cout<<"\nEnter name - ";
	  	getline(cin, nw->name);
	  	cout<<"Enter Class - ";
	  	getline(cin, nw->sec);
	  	cout<<"Enter Native Place - ";
	  	getline(cin, nw->place);
	  	cout<<"Enter CGPA - ";
	  	cin>>nw->marks;
	  	cin.ignore();

  		temp=head;
   	
  		while(temp->next!=NULL)
  		{
  			temp=temp->next;
  		}
 
  			temp->next=nw;
  			head->no++;
	}
	
	
	void display(node *head)
	{
		node *temp;
   
   		temp=head->next;
    	
    	cout<<"\nPeople Details - "<<endl<<endl;;
    	while(temp!=NULL)
  		{
   			cout<<temp->name<<endl;
   			cout<<temp->sec<<endl;
   			cout<<temp->place<<endl;
   			cout<<temp->marks<<" CGPA"<<endl;
   			if(temp->next!=NULL)
   			{
				cout<<".\n.\n.\n.\n.\n.\n";
    		}
   	
			temp=temp->next;
  		}
 
 	}
 	
 };
 
 
 int main()
 {
 	node *people;
 	node on;
 	int ch;
 	
 	people = on.create(people);
 	
 	while(1)
 	{
 	 	cout<<"\n\nMenu\n1. Save person's details\n2. Display Contacts\n3. Exit\nChoice - ";
 		cin>>ch;
 		cin.ignore();
 		
 		switch(ch)
 		{
 			case 1: on.save(people);break;
 			case 2: on.display(people);break;
 			case 3: cout<<"\n\n\nProgram Terminated..."; exit(0); break;
 			default: cout<<"\nIncorrect Option...\n\n";
 		}
 	}
 	
 	return 0;
 }
 	
 	
