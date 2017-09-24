/*

Write C++ program to store roll numbers of student in array who attended training program
in random order. Write function for-
a) Searching whether particular student attended training program or not using linear search
   and sentinel search.
b) Searching whether particular student attended training program or
   not using binary search and Fibonacci search.

*/

#include<iostream>
#include<cstdlib>
using namespace std;

class SearchTrainees
{
	int rantr[100];
	int sort[100];	
	int n;

	public:
	void getTrainees()
	{
		cout<<"\nEnter the number of students who attended the training program - ";
		cin>>n;
		
		cout<<"\nEnter the roll number of the students - ";
		for(int i = 0; i<n; i++)
		{
			cin>>rantr[i];
			sort[i] = rantr[i];
		}
		

	}

	int LinearSearch()
	{
		int r;
		cout<<"\nEnter the roll number to be searched - ";
		cin>>r;
		
		for(int i = 0; i<n; i++)
		{
			if(rantr[i] == r)
			return 1;
		}

		return 0;
	}

	int SentinelSearch()
	{
		int r;
		cout<<"\nEnter the roll number to be searched - ";
		cin>>r;

		int i = 0;
		rantr[n] = r;
		while(rantr[i] != r)
		{
			i++;
			if(i!=n)
			return 1;
		}
		
		return 0;
	}


	void SelectionSort()
	{
		int i, j, min, t;
		for(i = 0; i<n; i++)
		{
			min = i;
			for(j = j+1; j<n; j++)
			{
				if(sort[j] < sort[min])
				min = j;
			}

			t = sort[min];
			sort[min] = sort[i];
			sort[i] = t;
		}

		//return sort;
	}
		
	
	int BinarySearch()
	{
		SelectionSort();
		int r, l, u = n-1, m;
		cout<<"\nEnter the roll number to be searched - ";
		cin>>r;

		while(l<=u)
		{
			m = (l+u)/2;
			if(sort[m]==r)
			return 1;
			else if(sort[m] > r)
			l = m+1;
			else if(sort[m] < r)
			u = m-1;
		}
		
		return 0;
	}
		
	void display()
	{
		cout<<"Roll Numbers of the trainees attended are -\n";
		for(int i=0; i<n; i++)
		cout<<rantr[i]<<" ";
	}

};

int main()
{
	SearchTrainees ost;
	int ch;
	while(1)
	{
		cout<<"\n\n*****************Training Attendance Checker*****************\n";
		cout<<"1. Enter trainees attended\n";
		cout<<"2. Display trainees attended\n";
		cout<<"3. Search Trainee using Linear Search\n";
		cout<<"4. Search Trainee using Sentinel Search\n";
		cout<<"5. Search Trainee using Binary Search\n";
		cout<<"6. Exit\n";
		cout<<"Choice - ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: ost.getTrainees(); break;
			case 2: ost.display(); break;
			case 3: 
				{
					if(ost.LinearSearch()==1)
					cout<<"\nThe trainee attended the training program...";
					else
					cout<<"\nThe trainee didn't attended the training program...";
					break;
				}
			case 4: 
				{
					if(ost.SentinelSearch()==1)
					cout<<"\nThe trainee attended the training program...";
					else
					cout<<"\nThe trainee didn't attended the training program...";
					break;
				}
			case 5: 
				{
					if(ost.BinarySearch()==1)
					cout<<"\nThe trainee attended the training program...";
					else
					cout<<"\nThe trainee didn't attended the training program...";
					break;
				}
			case 6: exit(0);
			default: "Wrong option...!!!\n\n";
		}

	}
	return 0;
}				
				
	


