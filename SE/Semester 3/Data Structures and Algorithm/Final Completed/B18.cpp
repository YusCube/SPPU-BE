/* 

Group B- Assignment No- 18

Write C++ program to store set of negative and positive numbers using linked list. Write functions
a) Insert numbers
b) Delete nodes with negative numbers
c) To create two more linked lists using this list, one containing all positive numbers and other containing negative numbers
d) For two lists that are sorted; Merge these two lists into third resultant list that is sorted

By Shiva Saran
SE-A A-03

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
  int data;
  node *next;

public:
   node * createlist(node *head);
   void insertnumber(node *,int);
   void deleteno(node *);
   void separate(node *);
   void merge(node *);
   void sortlist(node *);

   void display(node *);
};

node* node:: createlist(node *head)
{
  head=new node;
  head->data=0;
  head->next=NULL;
  
  return(head);
}

void node::insertnumber(node *head, int ndata)
{
  node * nw,*temp;

 
  nw=new node;
  nw->data=ndata;
  nw->next=NULL;

  temp=head;

  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
 
  temp->next=nw;
  head->data++;
}
void node::display(node *head)
{
  node *temp;

  
     
   temp=head->next;
  cout<<"\nList Elements are= \n ";
  cout<<" (";
  while(temp!=NULL)
  {
   cout<<temp->data;
   if(temp->next!=NULL)
   {
   		cout<<" , ";
    }	
   temp=temp->next;
  }
 
  cout<<" )";
}


void node::deleteno(node  *head)
{
  node *temp,*d1;
  int del,flag=0;

  
  cout<<"\nEnter number (- ve) for deletion operation= ";
  cin>>del;
  
  temp=head;
  while(temp->next!=NULL)
  {
	
	
  		if(temp->next->data!=del)
  		{
   			temp=temp->next;
                	flag=0;
  		}
       		else if (temp->next->data==del)
		{
          		if(del < 0)
			{
			        d1=temp->next;
        	   		temp->next=d1->next;
			        d1->next=NULL;
        	   		cout<<"\nNumber "<< d1->data << " is successfully deleted. ";
			
		   		delete(d1);
			        flag=1;
           			break;
			}
			else
			{
				cout<<"Number is positive..Please enter -Ve Number....";			
				flag=1;
				break;
			}
         	}
   	
 }
if(flag==0)
   cout<<"\nNumber "<< del<< " is not available in Database. ";
   

   
}

void node:: separate(node *head)
{
  node *temp, * poshead, *neghead;
  
  

  poshead =createlist(poshead);
  neghead =createlist(neghead);
  
  
  temp=head;
  while(temp->next!=NULL)
  {
  	if(temp->next->data>0)
  	{
   		insertnumber(poshead, temp->next->data);
		
                  
  	}
       else
	{
               insertnumber(neghead, temp->next->data);
		
        }
     temp=temp->next;
   }
 display(poshead);
 display(neghead);
}

void node:: merge(node *head)
{
  node *temp, * poshead, *neghead,*mergelist;
  

  poshead =createlist(poshead);
  neghead =createlist(neghead);
  
  
  temp=head;
  while(temp->next!=NULL)
  {
  	if(temp->next->data>0)
  	{
   		insertnumber(poshead, temp->next->data);
		
                  
  	}
       else
	{
               insertnumber(neghead, temp->next->data);
		
        }
     temp=temp->next;
   }

 sortlist(neghead);
 sortlist(poshead);

 mergelist=neghead;
 temp=mergelist;
 while(temp->next!=NULL)
 {
   temp=temp->next;
 }
 
 temp->next=poshead->next;

 display(mergelist);
 
}

void node:: sortlist(node *head)
{
   node *temp;
   int counter=0,i,j,tdata;
 temp=head;

counter=head->data;

  
 for(i=0; i<counter; i++)
 {
   temp=head->next;
    for(j=i+1; j<counter; j++)
    {
        
       if(temp->data > temp->next->data)
       {
          tdata=temp->data;
          temp->data= temp->next->data;
          temp->next->data=tdata;
       }
        temp=temp->next;
     }
  }
}

   
   

int main()
{
 int i,ch,data,number;

node * head;
node s1;


head =s1.createlist(head);
 while(1)
	{
		cout<<"\n----------Menus----------\n1. Insert number (+ve or - ve) \n2. Delete nodes with negative numbers \n3. To create two more linked lists( i.e +ve Number and -ve Number)\n4. Merge two sorted lists \n5. Exit\nEnter ur choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"\n How many elements (+ve and -ve) u want to insert?= ";
				cin>>number;
				for(i=0;i<number;i++)
				{
	                                cout<<"\nEnter number (+ve or - ve)= ";
	 				cin>>data;
					s1.insertnumber(head,data);
				}
				s1.display(head);
				
			break;
			case 2:
				s1.deleteno(head);
				s1.display(head);
			break;
			case 3:
				s1.separate(head);
			break;
			case 4:
				s1.merge(head);
			break;
			case 5:
				exit(0);
		}
	}
 }
   
/*
----------Menus----------
1. Insert number (+ve or - ve) 
2. Delete nodes with negative numbers 
3. To create two more linked lists( i.e +ve Number and -ve Number)
4. Merge two sorted lists 
5. Exit
Enter ur choice :1

 How many elements (+ve and -ve) u want to insert?= 10

Enter number (+ve or - ve)= 10

Enter number (+ve or - ve)= -25

Enter number (+ve or - ve)= -11

Enter number (+ve or - ve)= 60

Enter number (+ve or - ve)= 45

Enter number (+ve or - ve)= 23

Enter number (+ve or - ve)= 25

Enter number (+ve or - ve)= -15

Enter number (+ve or - ve)= -99

Enter number (+ve or - ve)= 12

List Elements are= 
  (10 , -25 , -11 , 60 , 45 , 23 , 25 , -15 , -99 , 12 )
----------Menus----------
1. Insert number (+ve or - ve) 
2. Delete nodes with negative numbers 
3. To create two more linked lists( i.e +ve Number and -ve Number)
4. Merge two sorted lists 
5. Exit
Enter ur choice :2

Enter number (- ve) for deletion operation= -15

Number -15 is successfully deleted. 
List Elements are= 
  (10 , -25 , -11 , 60 , 45 , 23 , 25 , -99 , 12 )
----------Menus----------
1. Insert number (+ve or - ve) 
2. Delete nodes with negative numbers 
3. To create two more linked lists( i.e +ve Number and -ve Number)
4. Merge two sorted lists 
5. Exit
Enter ur choice :2

Enter number (- ve) for deletion operation= 10
Number is positive..Please enter -Ve Number....
List Elements are= 
  (10 , -25 , -11 , 60 , 45 , 23 , 25 , -99 , 12 )
----------Menus----------
1. Insert number (+ve or - ve) 
2. Delete nodes with negative numbers 
3. To create two more linked lists( i.e +ve Number and -ve Number)
4. Merge two sorted lists 
5. Exit
Enter ur choice :3

List Elements are= 
  (10 , 60 , 45 , 23 , 25 , 12 )
List Elements are= 
  (-25 , -11 , -99 )
----------Menus----------
1. Insert number (+ve or - ve) 
2. Delete nodes with negative numbers 
3. To create two more linked lists( i.e +ve Number and -ve Number)
4. Merge two sorted lists 
5. Exit
Enter ur choice :4

List Elements are= 
  (-99 , -25 , -11 , 10 , 12 , 23 , 25 , 45 , 60 )
----------Menus----------
1. Insert number (+ve or - ve) 
2. Delete nodes with negative numbers 
3. To create two more linked lists( i.e +ve Number and -ve Number)
4. Merge two sorted lists 
5. Exit
Enter ur choice :5

*/
