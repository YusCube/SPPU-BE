/*
Group A
Assignment 7

A magic square is an n * n matrix of the integers 1 to n 2 such that the sum of each row,
column, and diagonal is the same. The figure given below is an example of magic square for
case n=5. In this example, the common sum is 65. Write C/C++ Program for magic square.
Eg. 			15   8   1   24   17   
			16   14   7   5   23   
			22   20   13   6   4   
			3   21   19   12   10   
			9   2   25   18   11 

By Shiva Saran, SE-A, A-03
*/


#include<stdio.h>
int main()
{
	int i, j,n;
	int sumr[n], sumcol[n], sumdia1=0, sumdia2=0, check, ch;
	
	do
	{
	printf("\n\nEnter the size of the Matrix - ");
	scanf("%d", &n);
	int A[n][n];

	printf("\nEnter Matrix A- \n");
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	printf("\n\nThe Matrix A - \n");
	

	
	
	//For Printing Matrix A and Summation of n row, column and Diagonal elements
	for(i = 0; i<n; i++)
	{
		sumr[i] = 0;
		sumcol[i] = 0;
		for(j = 0; j<n; j++)
		{
			printf("%d   ", A[i][j]);
			sumr[i] += A[i][j];
			sumcol[i] += A[j][i];

			if(i==j)
			sumdia1 += A[i][j];

			if(i+j+1 == n)
			sumdia2 += A[i][j];			
		}
		
		printf("\n");

		check = 0;
		if((sumr[i]==sumcol[i])&& sumdia1 && sumdia2)
		check = 1;
	}
	
		
	

	//Checking if it's a Magic Square or Not
	if(check==1)
	printf("\n\nMatrix A of %dx%d is a Magic Square...\n\n\n",n,n);
	else
	printf("\n\nMatrix A of %dx%d is not a Magic Square...\n\n\n",n,n);

	printf("Do you wanna try again...?\n1.Yes\n2.No\n\nChoice - ");
	scanf("%d", &ch);

	}while(ch!=2);
	printf("\n\nProgram Terminated...!!!\n\n\n\n");
	return 0;
}
}

	
