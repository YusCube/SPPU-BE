/*
Group G
Assignment 26

Any application defining scope of Formal parameter, Global parameter, Local parameter
accessing mechanism and also relevance to private, public and protected access. Write a Java
program which demonstrates the scope rules of the programming mechanism.
*/

//Class 1
public class MyClass
{
	static int numObj ;
	private String priVar = " DYP Technical Campus";

	public String pubVar  ;	
	
	protected String proVar = "Proteced value" ;
	
	MyClass()
	{
		numObj++ ;
	}
	
	public void displayVar()
	{
		System.out.println("Object number :- " + numObj);
		System.out.println(priVar); // can access private variable within class methods
		System.out.println(pubVar); // can access public  variable within class methods
		System.out.println(proVar); // can access protected  variable within class methods
		
	}
}
