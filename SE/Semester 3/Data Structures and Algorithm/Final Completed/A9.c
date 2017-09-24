/*

Write C/C++ program for storing matrix. Write functions for
a) Check whether given matrix is upper triangular or not
b) Compute summation of diagonal elements
c) Compute transpose of matrix
d) Add, subtract and multiply two matrices

By Shiva Saran
SE-A A-03

*/


#include<stdio.h>
#include<stdlib.h>
void accept();
void display();
void uppertri();
void diasum();
void transpose();
void addsubmul();
int A[10][10], B[10][10], C[10][10], D[10][10], E[10][10], transA[10][10], transB[10][10], r,c,i,j,k;

int main()
{
	int ch;
	while(1)
	{

		printf(" \n ************ Program Menus ********** \n");
		printf(" \n1. Accept and Display Matrix \n");
		printf(" \n2. Check whether given matrix is upper triangular or not\n");
		printf(" \n3. Compute summation of diagonal elements \n");
		printf(" \n4. Compute transpose of matrix\n");
		printf(" \n5. Add, subtract and multiply two matrices \n");
		printf(" \n6. Exit \n");
		printf(" \n Enter UR Choice= ");
		scanf("%d",&ch);

	switch(ch)
	{
		case 1: 
			accept();
			display();
			break;
		case 2: 
			uppertri();
			break;
		case 3: 
			diasum();
			break;	
		case 4: 
			transpose();
			break;	
		case 5:
			addsubmul();
			break;	
		case 6:
			exit(0);
			break;		
		default: 
			printf("\n Wrong Choice... Enter correct choice.");
			break;
	}
	}
	return 0;
}

void accept()
{
  
	  printf("\nEnter Row and Column= \n");
	  scanf("%d%d",&r,&c);

	  printf("\nEnter elements of Matrix A= \n");
	  for(i=0; i<r; i++)
	  {
		for(j=0; j<c; j++)
		{
			scanf("%d",&A[i][j]);
		}
	  }
  	  
	  printf("\nEnter elements of Matrix B= \n");
	  for(i=0; i<r; i++)
	  {
		for(j=0; j<c; j++)
		{
			scanf("%d",&B[i][j]);
		}
	  }
}

void display()
{
  
	printf("\nElements of Matrix A= \n  ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",A[i][j]);
		}
		printf("\n");
	}
  	  
	printf("\nElements of Matrix B= \n  ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",B[i][j]);
		}
		printf("\n");
	}
}

void uppertri()
{
	//MATRIX A
	int flag=1;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(i>j)
			{
				if(A[i][j]==0)
				{
				flag=0;
				}
				else
				{
				flag=1;			
				break;
				}
			}
		}
		 
	}
	
	if(flag ==0)
	printf("\n Given Matrix A is Upper Triangular  ");
	else
	printf("\n Given Matrix A is Not Upper Triangular  ");
  	 
  	//MATRIX B 
	flag=1;
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(i>j)
			{
				if(B[i][j]==0)
				{
				flag=0;
				}
				else
				{
				flag=1;			
				break;
				}
			}
		}
		 
	}
	
	if(flag ==0)
	printf("\n Given Matrix B is Upper Triangular  ");
	else
	printf("\n Given Matrix B is Not Upper Triangular  ");
}

void diasum()
{
	int d1sum=0,d2sum=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				d1sum=d1sum+A[i][j];
			}
		}
	}
	printf("\n Sum of diagonal of matrix A is = %d",d1sum);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				d2sum=d2sum+B[i][j];
			}
		}
	}
	printf("\n Sum of diagonal of matrix B is = %d",d2sum);
}

void transpose()
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			transA[i][j]=A[j][i];
		}
	}
	printf("\n Transpose of matrix A : \n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",transA[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			transB[i][j]=B[j][i];
		}
	}
	printf("\n Transpose of matrix B : \n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",transB[i][j]);
		}
		printf("\n");
	}
}

void addsubmul()
{
	//Addition
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	printf("\n Sum of matrix A and B : \n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",C[i][j]);
		}
		printf("\n");
	}
	
	//Substraction
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			D[i][j]=A[i][j]-B[i][j];
		}
	}
	printf("\n Substraction of matrix A and B : \n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",D[i][j]);
		}
		printf("\n");
	}
	
	//Multiplication
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			for(k=0;k<r;k++)
			{
				E[i][j]=E[i][j]+(A[i][k]*B[k][j]);
			}
		}
	}
	printf("\n Multiplication of matrix A and B : \n");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("\t%d",E[i][j]);
		}
		printf("\n");
	}
}

/*

 ************ Program Menus ********** 
 
1. Accept and Display Matrix 
 
2. Check whether given matrix is upper triangular or not
 
3. Compute summation of diagonal elements 
 
4. Compute transpose of matrix
 
5. Add, subtract and multiply two matrices 
 
6. Exit 
 
 Enter UR Choice= 1

Enter Row and Column= 
3
3

Enter elements of Matrix A= 
1
2
3
4
5
6
7
8
9

Enter elements of Matrix B= 
9
8
7
0
5
4
0
0
1

Elements of Matrix A= 
  	1	2	3
	4	5	6
	7	8	9

Elements of Matrix B= 
  	9	8	7
	0	5	4
	0	0	1
 
 ************ Program Menus ********** 
 
1. Accept and Display Matrix 
 
2. Check whether given matrix is upper triangular or not
 
3. Compute summation of diagonal elements 
 
4. Compute transpose of matrix
 
5. Add, subtract and multiply two matrices 
 
6. Exit 
 
 Enter UR Choice= 2

 Given Matrix A is Not Upper Triangular  
 Given Matrix B is Upper Triangular   
 ************ Program Menus ********** 
 
1. Accept and Display Matrix 
 
2. Check whether given matrix is upper triangular or not
 
3. Compute summation of diagonal elements 
 
4. Compute transpose of matrix
 
5. Add, subtract and multiply two matrices 
 
6. Exit 
 
 Enter UR Choice= 3

 Sum of diagonal of matrix A is = 15
 Sum of diagonal of matrix B is = 15 
 ************ Program Menus ********** 
 
1. Accept and Display Matrix 
 
2. Check whether given matrix is upper triangular or not
 
3. Compute summation of diagonal elements 
 
4. Compute transpose of matrix
 
5. Add, subtract and multiply two matrices 
 
6. Exit 
 
 Enter UR Choice= 4

 Transpose of matrix A : 
	1	4	7
	2	5	8
	3	6	9

 Transpose of matrix B : 
	9	0	0
	8	5	0
	7	4	1
 
 ************ Program Menus ********** 
 
1. Accept and Display Matrix 
 
2. Check whether given matrix is upper triangular or not
 
3. Compute summation of diagonal elements 
 
4. Compute transpose of matrix
 
5. Add, subtract and multiply two matrices 
 
6. Exit 
 
 Enter UR Choice= 5

 Sum of matrix A and B : 
	10	10	10
	4	10	10
	7	8	10

 Substraction of matrix A and B : 
	-8	-6	-4
	4	0	2
	7	8	8

 Multiplication of matrix A and B : 
	9	18	18
	36	57	54
	63	96	90
 
 ************ Program Menus ********** 
 
1. Accept and Display Matrix 
 
2. Check whether given matrix is upper triangular or not
 
3. Compute summation of diagonal elements 
 
4. Compute transpose of matrix
 
5. Add, subtract and multiply two matrices 
 
6. Exit 
 
 Enter UR Choice= 6
*/	
