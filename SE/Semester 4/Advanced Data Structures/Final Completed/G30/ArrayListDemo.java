/* 
 * Group-G
 * Asignment No. 30-1 

Write a Java program for the implementation of Array List data structures using JAVA
collection libraries (Standard toolkit library).
*/

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> s1 = new ArrayList();
		
		Scanner sc=new Scanner(System.in);  
		int i;
		while(true)
		{
			System.out.println("**************** Array List Implementation Using Java Collections ********** ");
			System.out.println("1. Insert new Element ");
			System.out.println("2. Delete Element");
			System.out.println("3. Display All Elements");
			System.out.println("4. Exit");
			System.out.println("Choice= ");
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
						System.out.println("Array is Empty....");
					}
					else
					{
						System.out.println("Enter elements to be Deleted= ");
						int ele=sc.nextInt();
						for(i=0; i < s1.size(); i++) {
						 
							if(s1.get(i)==ele)
							{
								s1.remove(i);
								break;
							}
							
						
						}
						if(i>s1.size())
						{		
							System.out.println("Element is not Present in the Array..");
						}
					}
										
				break;
				
				case 3:
					if(s1.isEmpty())
					{
						System.out.println("Array is Empty....");
					}
					else
					{
						System.out.println("Array List Elements are= ");
						for(i=0; i < s1.size(); i++) {
						    System.out.print("  "+s1.get(i));
						   
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
