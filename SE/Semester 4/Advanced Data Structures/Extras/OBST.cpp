/*
Group D
Assignment 18

Given sequence k = k1 <k2 < ... < kn of n sorted keys, with a search probability pi for each
key ki . Build the Binary search tree that has the least search cost given the access probability
for each key.
*/

#include<iostream>
#include<cstdlib>
#define max 20
using namespace std;

class leaf
{
public:
char name[10];
} leaf[max];

int i, j, k, n, min, r[max][max];
float p[max], q[max], w[max][max], c[max][max];
void OBST();
void print(int, int);
void print_tab();

int main()
{
cout << "\n Enter no. of leaves in tree:";
cin >> n;
cout << "\n Enter leaf label";
for(i = 1; i <= n; i++)
cin >> leaf[i].name;
cout << "\n Enter the probability of successful search:";
for(i = 1; i <= n; i++)
{
cout << "p["<<i<<"]";
cin >> p[i];
}
cout << "\n Enter the probability of unsuccessful search: ";
for(i = 0; i <= n; i++)
{
cout << "q["<<i<<"]";
cin >> q[i];
}
cout << "\ninput:\n"<<"Leaf ("<<n<<")";
for(i = 1; i <= n; i++)
{
cout << "leaf["<<i<<"].name";
cout << "n p(1:"<<n<<")";
}
for(i = 1; i <= n; i++)
{
cout << "p["<<i<<"]";
cout << "\nq(0:"<< n<<")=";
}
for(i = 0; i <= n; i++)
cout << "\t"<<q[i];
OBST();
print_tab();
print(0, n);
return 0;
}

void OBST()
{
for(i = 0; i < n; i++)
{
r[i][i] = c[i][i] = 0; w[i][i] = q[i];
w[i][i + 1] = p[i + 1] + q[i + 1] + w[i][i];
c[i][i + 1] = w[i][i + 1];
r[i][i + 1] = i + 1;
}
c[n][n] = 0.0; r[n][n] = 0.0; w[n][n] = q[n];
for(i = 2; i <= n; i++)
{
	for(j=0; j<=n-i; j++)
	{
		w[j][j+i] = w[j][j+i-1] + p[j+i] + q[j+i];
		c[j][j + i] = 999;
		for(k = j + 1; k < j + i; k++)
		{
			if(c[j][j+i] > c[j][k-1] + c[k][j+i])
			class leaf
{
char name[10];
} leaf[max];{
				
				c[j][j+i] = c[j][k-1] + c[k][j+i];
				r[j][j + i] = k;
			}
		}
		c[j][j+i]+=w[j][j+i];
	}
}
}

void print(int l, int rr)
{
if(l >= rr) 
	return ;

if(r[l][r[l][rr]-1] != 0)
cout<<"\nLeft Child of "<<leaf[r[l][rr]].name<<"\t"<<leaf[r[l][r[l][rr]-1]].name;
if(r[r[l][rr]][rr] != 0)
cout << "\nright child of"<< leaf[r[l][rr]].name<<"\t" <<leaf[r[r[l][rr]][rr]]. name;
print(l, r[l][rr]-1);
print(r[l][rr],rr);
}

void print_tab()
{
cout << "\noutput:\n";
cout <<"---------------------------------------------------------\n";
for(i = 0; i <= n; i++)
cout << "w" << i << i << "=" << w[i][i] << "\n";
for(i = 0; i <= n; i++)
cout << "w" << i << i << "=" << c[i][i] << "\n";
for(i = 0; i <= n; i++)
cout << "w" << i << i << "=" << r[i][i] << "\n";
cout << "---------- -----------------------------------------------\n";
k = 1;
while(k <= n)
{
for(i = 0, j = i + k; i < n, j <= n; i++, j++)
cout << "w" << i << j << "=" << w[i][j] << "\n";
for(i = 0 , j = i + k; i < n, j <= n; i++, j++)
cout << "C" << i << j << "=" << c[i][j] << "\n";
for(i = 0, j = i + k; i < n, j <= n; i++, j++)
cout << "R" << i << j << "=" << r[i][j] << "\n";
cout <<"----- ----------------------------------------------------\n";
k++;
}
cout << "\nOBST:"<<c[0][n]<<w[0][n]<<leaf[r[0][n]].name;
cout << ("\nOBST:c[0][%d] = %0.2f w[0][%d] = %0.2f r[0][%d] = %s", n, c[0][n], n, w[0][n], n, leaf[r[0][n]].name);
}
