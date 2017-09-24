/*
Mini-Project
Assignment 25

Design and develop the Tic-Tac-Toe Game using C++


By Shiva Saran, SE-A, A-03
*/


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


class TicTacToe
{
	char A[3][3];
	int r,c;
	public: int matrix;
	TicTacToe()
	{
		matrix = 0;
	}
	public: 
	void player1()
	{
		cout<<"\nPlayer 1 - "<<endl;
		cin>>r>>c;
		while(r>3 || c>3 || (A[r-1][c-1]=='O') || (A[r-1][c-1]=='X'))
		{
			cout<<"\nIncorrect Input...!!!\nPlease Enter again - ";
			cin>>r>>c;
		}
		A[r-1][c-1] = 'O';
		display();
		computeO();
	}

	void player2()
	{
		cout<<"\nPlayer 2 - "<<endl;
		cin>>r>>c;
		while(r>3 || c>3 || (A[r-1][c-1]=='O') || (A[r-1][c-1]=='X'))
		{
			cout<<"\nIncorrect Input...!!!\nPlease Enter again - ";
			cin>>r>>c;
		}
		A[r-1][c-1] = 'X';
		display();
		computeX();
	}
	
	void display()
	{
		cout<<endl;		
		for(int i = 0; i<3; i++)
		{	
			for(int j = 0; j<3; j++)
		{
			if(A[i][j]=='O' || A[i][j]=='X')			
			cout<<"\t"<<A[i][j]<<"| ";
			else
			cout<<"\t | ";
		}
		cout<<endl;
		}
			
		
	}
	
	void computeO()
	{
		int ckr, ckc, ckd1=0, ckd2=0;
		for(int i = 0; i<3; i++)
		{
			ckr = 0;
			ckc = 0;
			for (int j = 0; j<3; j++)
			{
				if(A[i][j] == 'O')
				ckr++;
				if(A[j][i] == 'O')
				ckc++;
				
				if(i==j)
				{
					if(A[i][j] == 'O')
					ckd1++;
				}
				
				
				if(i+j+1 == 3)
				{
					if(A[i][j] == 'O')
					ckd2++;
				}
			}
			if((ckr==3) || (ckc==3) || ckd1==3 || ckd2==3)
			{
				cout<<"\n\nPlayer 1 Wins...!!!\n\n";
				exit(0);
			}
			
		}
		matrix++;
		if(matrix==9)
		{
			cout<<"\n\nIt's a draw...!!!\n\n";
			exit(0);
		}
			
	}

	void computeX()
	{
		int ckr, ckc, ckd1=0, ckd2=0;
		for(int i = 0; i<3; i++)
		{
			ckr = 0;
			ckc = 0;
			for (int j = 0; j<3; j++)
			{
				if(A[i][j] == 'X')
				ckr++;
				if(A[j][i] == 'X')
				ckc++;
				
				if(i==j)
				{
					if(A[i][j] == 'X')
					ckd1++;
				}
				
				
				if(i+j+1 == 3)
				{
					if(A[i][j] == 'X')
					ckd2++;
				}
			}
			if((ckr==3) || (ckc==3) || ckd1==3 || ckd2==3)
			{
				cout<<"\n\nPlayer 2 Wins...!!!\n\n";
				exit(0);
			}
			
		}
		matrix++;
		if(matrix==9)
		{
			cout<<"\n\nIt's a draw...!!!\n\n";
			exit(0);
		}

			
	}
};

int main()
{
	TicTacToe TO;
	cout<<"\n\n\n\t\t-TicTacToe Game-\nTwo player game, Player 1 is O & Player 2 is X\nEnter row and column locations points with space\n\n\n";
	while(true)
	{
		TO.player1();
		TO.player2();
	}
	return 0;

}
	
				
