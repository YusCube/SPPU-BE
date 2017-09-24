/* 

Group D- Assignment Number-28

Problem Statements- Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating
job queue. Write functions to add job and delete job from queue.


By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class Jobqueue
{
	int rear,front;
	int queue[MAX];
public:
	
	void initialize();
	void insert(int x);
	int delete1();
	void display();
};
void Jobqueue::initialize()
{
	int i;
	front=rear=-1;
	for(i=0;i<MAX;i++)
	{
		queue[i]=0;
	}
}
void Jobqueue::insert(int x)
{   
	if(rear==MAX-1)
	{
		cout<<"\n Job Queue is FULL";
	}
	else
	{  
		rear ++;
		queue[rear]=x;
		if(front==-1)
         	    front=0;
       
	}
}
int Jobqueue::delete1()
{
		int data;
		if(front==-1 && rear==-1)
		{
			cout<<"\n Job Queue is EMPTY";
		}
	
		data=queue[front];
		queue[front]=0;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front ++;
		}
	return(data);
}
void Jobqueue::display()
{
	int i;	
  	cout<<"\n Operating System Job Queue; Consider 0 as EMPTY\n";
  	for(i=0;i<MAX;i++)
  	{
		cout<<"  "<<queue[i];
  	}
	
}

int main()
{
	Jobqueue s1;
	int ch,n,x;
	s1.initialize();
	while(1)
	{
		cout<<"\n\n Opearting System Job Queue (Queue size is 10)";
		cout<<"\n 1. Add Job (Insert Job)";
		cout<<"\n 2. Delete Job";
		cout<<"\n 3. Display Job Queue";
		cout<<"\n 4. Exit ";
		cout<<"\n Enter your choice= ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter the Job Number=  ";
				cin>>x;
				s1.insert(x);
				s1.display();
			break;

			case 2:
				x=s1.delete1();
				if(x > 0)
				{
					cout<<"\n Job number "<<x<<" is Completed\n(Deleted from the Queue)";
				}
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
Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 3

 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  11

 Operating System Job Queue; Consider 0 as EMPTY
  11  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  12

 Operating System Job Queue; Consider 0 as EMPTY
  11  12  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  13

 Operating System Job Queue; Consider 0 as EMPTY
  11  12  13  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  14

 Operating System Job Queue; Consider 0 as EMPTY
  11  12  13  14  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  15

 Operating System Job Queue; Consider 0 as EMPTY
  11  12  13  14  15  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  16

 Operating System Job Queue; Consider 0 as EMPTY
  11  12  13  14  15  16  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 11 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  12  13  14  15  16  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  17

 Operating System Job Queue; Consider 0 as EMPTY
  0  12  13  14  15  16  17  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  18

 Operating System Job Queue; Consider 0 as EMPTY
  0  12  13  14  15  16  17  18  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 12 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  13  14  15  16  17  18  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  19

 Operating System Job Queue; Consider 0 as EMPTY
  0  0  13  14  15  16  17  18  19  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  20

 Operating System Job Queue; Consider 0 as EMPTY
  0  0  13  14  15  16  17  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  21

 Job Queue is FULL
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  13  14  15  16  17  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 13 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  14  15  16  17  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 14 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  15  16  17  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 15 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  16  17  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 16 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  17  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 17 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  18  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 18 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  21

 Job Queue is FULL
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  19  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 19 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  0  20

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job number 20 is Completed
(Deleted from the Queue)
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 2

 Job Queue is EMPTY
 Operating System Job Queue; Consider 0 as EMPTY
  0  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 1

 Enter the Job Number=  21

 Operating System Job Queue; Consider 0 as EMPTY
  21  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 3

 Operating System Job Queue; Consider 0 as EMPTY
  21  0  0  0  0  0  0  0  0  0

 Opearting System Job Queue (Queue size is 10)
 1. Add Job (Insert Job)
 2. Delete Job
 3. Display Job Queue
 4. Exit 
 Enter your choice= 4
*/
