//Class 2
public class Parameters extends MyClass
{
	
	String progname = " Java Program for SE Computer students"; // Global variable
	
	public void displayMethod (String name, String course, String grade)
	{
    /* A. Formal parameters are those defined in method declaration
	   name, course and grade are formal parameters of type String */  
	
		
		//priVar = "private variable" // error..private variable of base class is not accessible in derived class
		pubVar = "Computer Engineering" ; // can access public variable from base class MyClass 
      	proVar = "DYPSOE"	; // can access protected varible of baseclass in derived class 
      						  //but it acts as private variable in derived class								
		
		
		
		String message = "*** Thank you ***"; // local variable
			
		
		//Print details
		
		
		displayVar(); // can access public method of base class
		 
		System.out.println("*** " + progname + " ***"); 
		System.out.println("Name : " + name); 
		System.out.println("Course : " + course);
		System.out.println("Grade : " + grade);
		System.out.println(message);
			        
	}
	
	public static void main(String[] args) 
	{
		String studentName = "Shiva Saran";
		String studentcourse = "Java Programming Course";
		String studentGrade = "A";
	
		//  Actual parameters are the parameters in the method call
		// 	studentName, studentcourse, studentGrade are acutal parameters
		Parameters paramObj = new Parameters();
		
		paramObj.displayMethod(studentName,studentcourse, studentGrade);
		
		Parameters paramObj2 = new Parameters();
		paramObj2.pubVar = " only public variable canbe accesssed by objects  ";
		paramObj2.displayVar();
	}

}

/*
Output - 
[shivasaran@sss-ragemachine Assign_G_26]$ javac MyClass.java
[shivasaran@sss-ragemachine Assign_G_26]$ javac Parameters.java
[shivasaran@sss-ragemachine Assign_G_26]$ java Parameters
Object number :- 1
 DYP Technical Campus
Computer Engineering
DYPSOE
***  Java Program for SE Computer students ***
Name : Shiva Saran
Course : Java Programming Course
Grade : A
*** Thank you ***
Object number :- 2
 DYP Technical Campus
 only public variable canbe accesssed by objects  
Proteced value
[shivasaran@sss-ragemachine Assign_G_26]$ 

*/

