/* 
 * Group-G
 * Assignment No. 30-5 

Write a Java program for the implementation of Deque data structures using JAVA
collection libraries (Standard toolkit library).
*/

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class DequeDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Deque<Integer> s1=new LinkedList<Integer>();

		
		Scanner sc=new Scanner(System.in);  
		
		while(true)
		{
			System.out.println("**************** Deque(Double Ended Q) Implementation Using Java Collections ********** ");
			System.out.println("1. Insert From Front end ");
			System.out.println("2. Insert From Rear end ");
			System.out.println("3. Delete From Front end");
			System.out.println("4. Delete From Rear End");
			System.out.println("5. Display All Deque Elements ");
			System.out.println("6. Exit");
			System.out.println("Choice - ");
			int ch=sc.nextInt();
			switch(ch)
			{
				case 1:
						System.out.println("Enter Element= ");
						s1.addFirst(sc.nextInt());
						break;
				case 2:
					System.out.println("Enter Element= ");
					s1.addLast(sc.nextInt());
					break;
				case 3:
					if(s1.isEmpty())
					{
						System.out.println("Deque is Empty....");
					}
					else
					{
						int s=(int) s1.removeFirst();
						System.out.println("Deleted Front element is= "+s);
					}
										
				break;
				case 4:
					if(s1.isEmpty())
					{
						System.out.println("Deque List is Empty....");
					}
					else
					{
						int s=(int) s1.removeLast();
						System.out.println("Deleted Rear element is= "+s);
					}
										
				break;
				case 5:
					if(s1.isEmpty())
					{
						System.out.println("Deque is Empty....");
					}
					else
					{
						System.out.println("Deque Elements are= ");
						for(int i=0; i < s1.size(); i++) {
						    Object obj = ((LinkedList<Integer>) s1).get(i);
						    System.out.print("  "+obj);
						   
						}
						 System.out.println();	
					}
											
					
				break;		
				case 6:
					System.exit(0);
						
				
			}
			
		}
	
		

	}

}
