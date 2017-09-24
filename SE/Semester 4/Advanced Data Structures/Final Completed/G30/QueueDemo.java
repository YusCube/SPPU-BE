/* Asignment No. 30-4 From Group-G 

Problem Statement-
Write a Java program for the implementation of Queue data structures using JAVA
collection libraries (Standard toolkit library).
*/

import java.util.Scanner;

import java.util.LinkedList;
import java.util.Queue;

public class QueueDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Queue<Integer> s1 = new LinkedList();
		
		Scanner sc=new Scanner(System.in);  
		
		while(true)
		{
			System.out.println("**************** Queue Implementation Using Java Collections ********** ");
			System.out.println("1. Insert new Element ");
			System.out.println("2. Delete Element");
			System.out.println("3. Display Queue");
			System.out.println("4. Exit");
			System.out.println("Enter Ur Choice= ");
			int ch=sc.nextInt();
			switch(ch)
			{
				case 1:
						System.out.println("Enter Element= ");
						s1.add(sc.nextInt());
						break;
				case 2:
					if(s1.isEmpty())
					{
						System.out.println("Queue is Empty....");
					}
					else
					{
						int s=(int) s1.remove();
						System.out.println("Deleted element is= "+s);
					}
										
				break;
				
				case 3:
					if(s1.isEmpty())
					{
						System.out.println("Queue is Empty....");
					}
					else
					{
						System.out.println("Queue Elements are= ");
						for(int i=0; i < s1.size(); i++) {
						    Object obj = ((LinkedList) s1).get(i);
						    System.out.print("  "+obj);
						   
						}
						 System.out.println();	
					}
											
					
				break;		
				case 4:
					System.exit(0);
						
				
			}
			
		}
	}

}


/* *************************** OUPUT ********************************************************
 * **************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
10
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
20
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
30
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
3
Queue Elements are= 
  10  20  30
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Deleted element is= 10
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Deleted element is= 20
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Deleted element is= 30
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Queue is Empty....
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
10
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
25
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
3
Queue Elements are= 
  10  25
**************** Queue Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete Element
3. Display Stack
4. Exit
Enter Ur Choice= 
4
*/
