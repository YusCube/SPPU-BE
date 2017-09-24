/*

A MAGIC SQUARE IS AN N*N MATRIX OF THE INTEGER 1 to n^2 SUCH THAT SUM OF EACH ROW ,COLUMN AND DIAGONAL IS EQUAL

By Shiva Saran
SE-A A-03

*/


#include<stdio.h>

int mat[10][10],i,j,k,n; 
int rsum=0, csum=0, dig1=0, dig2=0;
int flag=0;

void accept();
void display();

int main()
{
	accept();
  	display();
	return 0;
}

void accept()
{
   printf("\nEnter the no of row or column of matrix\n");
   scanf("%d",&n);
   printf("\nEnter the elements of Matrix\n");
   for(i=0; i<n; i++)
   {
       for(j=0; j<n; j++)
       {
           scanf("%d",&mat[i][j]);
       }
   }
}

void display()
{
	k=n-1;
	for(i=0; i<n; i++)
	{
		rsum=0;
		csum=0;
		for(j=0; j<n; j++)
		{ 
			rsum=rsum+mat[i][j];
			csum=csum+mat[j][i];
   
			if(i==j)
			{
			dig1=dig1+mat[i][j];
			}
		}
		dig2=dig2+mat[i][k--];
	if(rsum==csum)
	{
		flag=1;
		continue;
	}
	else
	{
		flag=0;
		printf("\nGiven Marix is not magic square.\n");
		break;
	} 
	}
	if (flag==1 && rsum==dig1 && dig1==dig2)
	{
		printf("\nGiven Matrix is magic square.\n");
	}

}
   
 /*
Enter the no of row or column of matrix
3

Enter the elements of Matrix
2
2
2
2
2
2
2
2
2

Given Matrix is magic square.
*/
