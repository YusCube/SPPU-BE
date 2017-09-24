/*
 * Group-G
 * Asignment No. 30-3
 * 
Write a Java program for the implementation of Stack data structures using JAVA
collection libraries (Standard toolkit library).
*/


import java.util.Scanner;
import java.util.Stack;
public class StackDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Stack<Integer> s1 = new Stack<Integer>();
		Scanner sc=new Scanner(System.in);  
		
		while(true)
		{
			System.out.println("**************** Stack Implementation Using Java Collections ********** ");
			System.out.println("1. Push Element ");
			System.out.println("2. Pop Element");
			System.out.println("3. Display Stack");
			System.out.println("4. Exit");
			System.out.println("Enter Ur Choice= ");
			int ch=sc.nextInt();
			switch(ch)
			{
				case 1:
						System.out.println("Enter Element= ");
						s1.push(sc.nextInt());
				break;
				case 2:
					if(s1.empty())
					{
						System.out.println("Stack is Empty....");
					}
					else
					{
						int s=s1.pop();
						System.out.println("Poped element is= "+s);
					}
										
				break;
				
				case 3:
					Stack<Integer> s2 = (Stack<Integer>)(s1.clone());
						System.out.println("Stack Elements are= ");
						
						while(!s2.empty())
						{							
							System.out.println(s2.lastElement());
							s2.pop();
						}
				break;		
				case 4:
					System.exit(0);
						
				
			}
			
		}
	}
}

/* ************************************** OUTPUT *******************************************
 * **************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
10
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
20
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
30
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
3
Stack Elements are= 
30
20
10
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Poped element is= 30
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Poped element is= 20
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Poped element is= 10
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
2
Stack is Empty....
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
55
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
1
Enter Element= 
66
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
3
Stack Elements are= 
66
55
**************** Stack Implementation Using Java Collections ********** 
1. Push Element 
2. Pop Element
3. Display Stack
4. Exit
Enter Ur Choice= 
4

 */
		
	
