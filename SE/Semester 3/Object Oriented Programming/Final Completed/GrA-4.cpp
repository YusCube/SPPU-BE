/*
Implement a class CppArray which is identical to a one-dimensional C++ array (i.e., the
index set is a set of consecutive integers starting at 0) except for the following :
1. It performs range checking.
2. It allows one to be assigned to another array through the use of the assignment
operator (e.g. cp1= cp2)
3. It supports a function that returns the size of the array.
4. It allows the reading or printing of array through the use of cout and cin.

By Shiva Saran
SE-A A-03
*/




#include<iostream>
using namespace std;

class CppArray
{
	int A[50], B[50], n;

	public: void accept()
	{
		cout<<"Enter the size of the array - ";
		cin>>n;
		
		cout<<endl<<"Enter the elements of the array - \nInput: ";
		for(int i = 0; i<n; i++)
		{
			cout<<"A["<<i<<"] - ";			
			cin>>A[i];
		}
			

	}

	void bubblesort()
	{
		int tmp;
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n-i-1; j++)
			{
				if(A[j] > A[j+1])
				{
					tmp = A[j];
					A[j] = A[j+1];
					A[j+1] = tmp;
				}
			}
		}
	}
		
	void display()
	{
		cout<<"\nElements of the array A before sorting are as - \n";	
		for(int i = 0; i<n; i++)
		{
			cout<<"A["<<i<<"] - ";			
			cout<<A[i]<<endl;
		}

		bubblesort();
		

		cout<<"\nElements of the array A after sorting are as - \n";	
		for(int i = 0; i<n; i++)
		{
			cout<<"A["<<i<<"] - ";			
			cout<<A[i]<<endl;
		}
		
		cout<<"\nRange of the array is from "<<A[0]<<" to "<<A[n-1]<<"...";

		cout<<"\n\nFor copying the contents of Array A to be Array B,\n the contents of Array B are as follows - \n";
		for(int i = 0; i<n; i++)
		{
			B[i] = '\0';
			cout<<"B["<<i<<"] - ";			
			cout<<B[i]<<endl;
			
		}
		
		cout<<"\n\nAfter copying the contents of Array A to be Array B,\n the contents of Array B are as follows - \n";
		for(int i = 0; i<n; i++)
		{
			B[i] = A[i];
			cout<<"B["<<i<<"] - ";			
			cout<<B[i]<<endl;
		}
	}

	int sizeB()
	{		
		cout<<"\n\nThe size of Array B is - ";
		int i;
		for(i = 0; i<n; i++);
		cout<<i<<" elements...";
		return n;
	}
};

int main()
{
	cout<<endl<<endl<<"Class CppArray\n\n";	
	CppArray oca;
	oca.accept();
	oca.display();
	oca.sizeB();
	cout<<endl<<endl;
	return 0;
}

	
		

/*OUTPUT:
[student@localhost OOPPractical]$ g++ GrA - 4.cpp
[student@localhost OOPPractical]$ ./a.out

 Enter the limit of array 5

 Enter the array elements 
 a[0]=56

 a[1]=23

 a[2]=23

 a[3]=5

 a[4]=10

 The entered array is 
 a[0]=56
 a[1]=23
 a[2]=23
 a[3]=5
 a[4]=10
 The exchanged array is 
 b[0]=56
 b[1]=23
 b[2]=23
 b[3]=5
 b[4]=10
 The sorted array is 
 a[0]=5
 a[1]=10
 a[2]=23
 a[3]=23
 a[4]=56
 The range of array is from 5 to 56
 The size of array is 5
*/











