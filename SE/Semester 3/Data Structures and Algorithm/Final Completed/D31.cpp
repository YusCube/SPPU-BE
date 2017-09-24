/* 

Group D- Assignment Number-31

Problem Statements- Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed can not be cancelled. Write C++ program to simulate the system
using circular queue using array.

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class pizza
{
	int rear,front;
	int queue[MAX];
public:
	
	void initialize();
	void insert(int x);
	int delete1();
	void display();
};
void pizza::initialize()
{
	int i;
	front=rear=-1;
	for(i=0;i<MAX;i++)
	{
		queue[i]=0;
	}
}
void pizza::insert(int x)
{   
	if(((rear+1)%MAX)==front)
	{
		cout<<"\n Circular Queue is FULL";
	}
	else
	{  
		rear=(rear+1)%MAX;
		queue[rear]=x;
		if(front==-1)
         	    front=0;
       
	}
}
int pizza::delete1()
{
		int data;
		if(front==-1)
		{
			cout<<"\n Circular Queue is EMPTY";
		}
	
		data=queue[front];
		queue[front]=0;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%MAX;
		}
	return(data);
}
void pizza::display()
{
	int i;	
  	cout<<"\n All orders; Consider 0 as EMPTY\n";
  	for(i=0;i<MAX;i++)
  	{
		cout<<"  "<<queue[i];
  	}
	
}

int main()
{
	pizza s1;
	int ch,n,x;
	s1.initialize();
	while(1)
	{
		cout<<"\n JJ Pizza parlor; Maximum size is 10 \n";
		cout<<"\n 1. Accept Order (Insert order)";
		cout<<"\n 2. Served order (Delete order)";
		cout<<"\n 3. Display All order";
		cout<<"\n 4. Exit";
		cout<<"\n Enter your choice= ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter the New Order Number=  ";
				cin>>x;
				s1.insert(x);
				s1.display();
			break;

			case 2:
				x=s1.delete1();
				cout<<"\n Order number "<<x<<" is Serverd to the Customer\n(Deleted from the Queue)";
				s1.display();
			break;

			case 3:
				s1.display();
			break;
			case 4:
				exit(0);
		}
	}

}
	
/*
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 3

 All orders; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  11

 All orders; Consider 0 as EMPTY
  11  0  0  0  0  0  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  12

 All orders; Consider 0 as EMPTY
  11  12  0  0  0  0  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  13

 All orders; Consider 0 as EMPTY
  11  12  13  0  0  0  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  14

 All orders; Consider 0 as EMPTY
  11  12  13  14  0  0  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  15

 All orders; Consider 0 as EMPTY
  11  12  13  14  15  0  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  16

 All orders; Consider 0 as EMPTY
  11  12  13  14  15  16  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 2

 Order number 11 is Serverd to the Customer
(Deleted from the Queue)
 All orders; Consider 0 as EMPTY
  0  12  13  14  15  16  0  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  17

 All orders; Consider 0 as EMPTY
  0  12  13  14  15  16  17  0  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  18

 All orders; Consider 0 as EMPTY
  0  12  13  14  15  16  17  18  0  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  19

 All orders; Consider 0 as EMPTY
  0  12  13  14  15  16  17  18  19  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 2

 Order number 12 is Serverd to the Customer
(Deleted from the Queue)
 All orders; Consider 0 as EMPTY
  0  0  13  14  15  16  17  18  19  0
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  20

 All orders; Consider 0 as EMPTY
  0  0  13  14  15  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  21

 All orders; Consider 0 as EMPTY
  21  0  13  14  15  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  22

 All orders; Consider 0 as EMPTY
  21  22  13  14  15  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 1

 Enter the New Order Number=  23

 Circular Queue is FULL
 All orders; Consider 0 as EMPTY
  21  22  13  14  15  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 2

 Order number 13 is Serverd to the Customer
(Deleted from the Queue)
 All orders; Consider 0 as EMPTY
  21  22  0  14  15  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 2

 Order number 14 is Serverd to the Customer
(Deleted from the Queue)
 All orders; Consider 0 as EMPTY
  21  22  0  0  15  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 2

 Order number 15 is Serverd to the Customer
(Deleted from the Queue)
 All orders; Consider 0 as EMPTY
  21  22  0  0  0  16  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 2

 Order number 16 is Serverd to the Customer
(Deleted from the Queue)
 All orders; Consider 0 as EMPTY
  21  22  0  0  0  0  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 3

 All orders; Consider 0 as EMPTY
  21  22  0  0  0  0  17  18  19  20
 JJ Pizza parlor; Maximum size is 10 

 1. Accept Order (Insert order)
 2. Served order (Delete order)
 3. Display All order
 4. Exit
 Enter your choice= 4
*/
