/*
Group A
Assignment 9

Write C/C++ program for storing matrix. Write functions for
a) Check whether given matrix is upper triangular or not
b) Compute summation of diagonal elements
c) Compute transpose of matrix
d) Add, subtract and multiply two matrices

By Shiva Saran, SE-A
*/



#include<stdio.h>


void accept();
void acceptB();
void print();
void printB();
void uptr();
void sumdg();
void trans();
void add();
void sub();
void multi();
void loop();
int A[3][3], B[3][3], C[3][3],i, j, loch;


void main()
{
	
	printf("\n\nMatrix Operations");	
	do
	{
	int ch;	
	printf("\n\nWhat would you like to do...?\n1. Check whether the matrix is upper triangular or not...?\n2. Sum of Diagonal Elements\n3. Transpose of a matrix\n4. Add, Subtract and Multiply 2 Matrices\n\nChoice Number - ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: accept();
			print();
			uptr();
			loop();
			break;
		case 2: accept();
			print();
			sumdg();
			loop();			
			break;
		case 3: accept();
			print();
			trans();
			loop();
			break;
		case 4: accept();
			acceptB();
			print();
			printB();
			add();
			sub();
			multi();
			loop();
			break;
		default: printf("Wrong Choice Number...!!!\n");
			 loop();
	}
	}while(loch!=2);
	printf("\nProgram Terminated...!!!\n\n\n");
}

void accept()
{
	printf("\nEnter Matrix A- \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
}

void acceptB()
{
	printf("\nMatrix B- \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}
}


void print()
{
	printf("\n\nThe Matrix A - \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			printf("%d   ", A[i][j]);
		}
		printf("\n");
	}
}

void printB()
{
	printf("\n\nThe Matrix B - \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			printf("%d   ", B[i][j]);
		}
		printf("\n");
	}
}


void uptr()
{	
	int up = 0;
	for(i = 0; i<3; i++)
	{
		for(j = i - 1; j >= 0; j--)
		{
			if(A[i][j]!=0)
			up++;
			
		}
	}
	if(up==0)
	printf("\nThe matrix A is Upper Triangular matrix...!\n\n");
	else
	printf("\nThe matrix A is not Upper Triangular matrix...!\n\n");
}

void sumdg()
{
	int sumd = 0;	
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			if(i==j)
			sumd += A[i][j];
		}
	}
	printf("\nThe sum of diagonal elements of the matrix A is %d...!\n\n", sumd);
}

void trans()
{
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			B[j][i] = A[i][j];
		}
	}
	printf("\n\nThe transpose of the matrix A is- \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			printf("%d   ", B[i][j]);
		}
		printf("\n");
	}
}

void add()
{
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			C[i][j] = A[i][j]+B[i][j];
		}
	}
	printf("\n\nThe Addition of the matrix A and B is- \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			printf("%d   ", C[i][j]);
		}
		printf("\n");
	}
}

void sub()
{
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			C[i][j] = A[i][j]-B[i][j];
		}
	}
	printf("\n\nThe Subraction of the matrix A and B is- \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			printf("%d   ", C[i][j]);
		}
		printf("\n");
	}
}

void multi()
{
	
	int k;	
	
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			C[i][j] = 0;
			for(k = 0; k<3; k++)
			C[i][j] += A[i][k]*B[k][j];
		}
	}
	printf("\n\nThe Multiplication of the matrix A and B is- \n");
	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			printf("%d   ", C[i][j]);
		}
		printf("\n");
	}
}

void loop()
{
	printf("\nDo you wanna try again...?\n1. Yes\n2. No\n\nOption - ");
	scanf("%d", &loch);
	if(loch!=1 && loch!=2)
	{
		printf("\n\nWrong Choice...!\n\nPlease try again...!!!");
		loop();
	}
}
