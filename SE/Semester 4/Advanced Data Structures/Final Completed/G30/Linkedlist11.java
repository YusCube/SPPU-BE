/* 
 * Group-G
 * Asignment No. 30-2 

Write a Java program for the implementation of Linked List data structures using JAVA
collection libraries (Standard toolkit library).
*/

import java.util.LinkedList;
import java.util.Scanner;

public class Linkedlist11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LinkedList<Integer> s1=new LinkedList<Integer>();

		
		Scanner sc=new Scanner(System.in);  
		
		while(true)
		{
			System.out.println("**************** LINKED LIST Implementation Using Java Collections ********** ");
			System.out.println("1. Insert new Element ");
			System.out.println("2. Delete First Element");
			System.out.println("3. Delete Last Element");
			System.out.println("4. Display All Elements");
			System.out.println("5. Exit");
			System.out.println("Choice - ");
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
						System.out.println("Linked List is Empty....");
					}
					else
					{
						int s=(int) s1.removeFirst();
						System.out.println("Deleted First element is= "+s);
					}
										
				break;
				case 3:
					if(s1.isEmpty())
					{
						System.out.println("Linked List is Empty....");
					}
					else
					{
						int s=(int) s1.removeLast();
						System.out.println("Deleted Last element is= "+s);
					}
										
				break;
				case 4:
					if(s1.isEmpty())
					{
						System.out.println("Linked List is Empty....");
					}
					else
					{
						System.out.println("Linked List Elements are= ");
						for(int i=0; i < s1.size(); i++) {
						    
						    System.out.print("  "+s1.get(i));
						   
						}
						 System.out.println();	
					}
											
					
				break;		
				case 5:
					System.exit(0);
						
				
			}
			
		}
	
		
	}

}

/* ****************************** OUTPUT ****************************************
 * **************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
1
Enter Element= 
10
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
1
Enter Element= 
40
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
1
Enter Element= 
50
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
1
Enter Element= 
60
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
4
Linked List Elements are= 
  10  40  50  60
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
2
Deleted First element is= 10
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
3
Deleted Last element is= 60
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
3
Deleted Last element is= 50
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
4
Linked List Elements are= 
  40
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
2
Deleted First element is= 40
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
2
Linked List is Empty....
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
3
Linked List is Empty....
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
4
Linked List is Empty....
**************** LINKED LIST Implementation Using Java Collections ********** 
1. Insert new Element 
2. Delete First Element
3. Delete Last Element
4. Display Stack
5. Exit
Enter Ur Choice= 
5
*/
