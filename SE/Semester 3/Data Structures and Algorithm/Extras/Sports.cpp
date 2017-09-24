/*In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and display-

1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only cricket
4. Set of students who play only badminton
5. Number of students who play neither cricket nor badminton
   (Note- While realizing the set duplicate entries are to avoided)
*/



#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

	
	int search(int Arr[120],int tar, int n)
	{
			
		for(int i = 0; i<n; i++)
		{

			if(tar==Arr[i])
			{
				return (1);
			}		
		}
		
		return 0;

	}

void union1(int A[60], int B[60], int n, int l)
{
	int C[120],k,j;
	for(int i=0,k=0;i<n;i++,k++)
		C[k]=A[i];
	
	cout<<"\nUnion of Set A & Set B is= \n";
	for(j=0; j<k; j++)
		cout<<C[j]<<"\t";

        for(int i=0; i<l; i++)
	{
		if(search(C, B[i], k)==0)
		{
			C[k]=B[i];
			k++;
		}
	}
	
	cout<<"\nUnion of Set A & Set B is= \n";
	for(int i = 0; i<k; i++)
		cout<<C[i]<<"\t";		

}

	
int main()
{
        int A[60], B[60], C[120],n,l,M,j;
	
	cout<<"\nEnter Strength of Class SE Comp= ";
	cin>>M;
     
        cout<<"\nEnter the number of students who play Cricket = ";
	cin>>n;
	cout<<endl<<"Enter the roll number of students who play Cricket - \nSet Cricket: ";
		for(int i = 0; i<n; i++)
		cin>>A[i];
	
	cout<<"\nSet A Elements = \n";
	for(j=0; j<n; j++)
		cout<<A[j]<<"\t";
	cout<<"\nEnter the number of students who play Badminton = ";
	cin>>l;
	cout<<endl<<"Enter the roll number of students who play Badminton - \nSet Badminton: ";
		for(int i = 0; i<l; i++)
		cin>>B[i];
	cout<<"\nSet B Elements = \n";
	for(j=0; j<l; j++)
		cout<<B[j]<<"\t";
	
	
	union1(A,B,n,l);
	return 0;
}


/*Enter the roll number of students who play Cricket - 
Set Cricket: 1 20 16 13 5 9 6 7 8 4 2 14

Enter the number of students who play Badminton - 10

Enter the roll number of students who play Badminton - 
Set Badminton: 1 15 3 7 10 11 12 17 13  9
*/
