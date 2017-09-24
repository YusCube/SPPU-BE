/*

Group B
Assignment 18

Write a function template selection Sort. Write a program that inputs, sorts and outputs an int
array and a float array.

By Shiva Saran
SE-A A-03

*/

#include<iostream>
using namespace std;

template <class T1>
class TemplateSorting
{
	public:	
	T1 A[5];
	//T2 B[5];
	public:
	/*SampleTemplate(T1 x, T2 y)
	{
		a = x;
		b = y;
	}*/
	
	void accept()
	{
		cout<<endl<<"Enter the elements of the array - \nInput: ";
		for(int i = 0; i<5; i++)
		{
			cout<<"A["<<i<<"] - ";			
			cin>>A[i];
		}
			

	}

	
	void SelectionSort()
	{
	double tmp;
	for(int i = 0; i<5; i++)
	{
		for(int j = 0; j<5; j++)
		{
			if(A[i] < A[j])
			{
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
	}

	void display()
	{
		cout<<"\nElements of the array A before sorting are as - \n";	
		for(int i = 0; i<5; i++)
		{
			cout<<"A["<<i<<"] - ";			
			cout<<A[i]<<endl;
		}

		SelectionSort();
		

		cout<<"\nElements of the array A after sorting are as - \n";	
		for(int i = 0; i<5; i++)
		{
			cout<<"A["<<i<<"] - ";			
			cout<<A[i]<<endl;
		}
	}
};
int main()
{
	TemplateSorting<int> test1;
	cout<<"\nSelection Sort for Integer Array - \n";	
	test1.accept();	
	test1.display();
		
	TemplateSorting<double> test2;
	cout<<"\nSelection Sort for Float Array - \n";		
	test2.accept();
	test2.display();
	return 0;
}


