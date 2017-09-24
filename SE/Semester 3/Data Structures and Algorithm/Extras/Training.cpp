/*

Training Program Attendees

*/

#include<iostream>
#include<cstdlib>
using namespace std;

class Training
{
	int at[100], ats[100];
	int n;

	public:
	void input()
	{
		cout<<"Enter the number of students who attended the training program - ";
		cin>>n;

		cout<<"\nEnter the the roll numbers - ";
		for(int i = 0; i<n; i++)
		{
			cin>>at[i];
			ats[i] = at[i];
		}
	
		cout<<"\nThe Data that you have entered in random orderare - \nRoll Numbers - ";
		for(int i = 0; i<n; i++)
		{
			cout<<ats[i]<<" ";
		}

	}

	void sort()
	{
		int i, j, temp;
		for(i = 0; i<n; i++)
		{
			for(j = 0; j<n-i-1; j++)
			{
				if(ats[j] > ats[j+1])
				{
					temp = ats[j];
					ats[j] = ats[j+1];
					ats[j+1] = temp;
				}
			}
		}
		/*cout<<"\nThe Data that you have entered in random order are - \nRoll Numbers - ";
		for(int i = 0; i<n; i++)
		{
			cout<<ats[i]<<" ";
		}*/
	}

	int BinSr(int sn)
	{
		sort();
		
		int l=0 , u=n-1 , m=0;
		
		while(l<=u)
		{
			m = (l+u)/2;
			if(ats[m] == sn)
			return 1;
			
			else if(ats[m] < sn)
			l = m+1;

			else if(ats[m] > sn)
			u = m-1;
		
			//cout<<endl<<m<<endl;

		}

		return 0;

	}

};


int main()
{

	cout<<"\n***************************Training Program Attendance Manager*********************************\n";
	
	int ch, s;
	Training ot;

	do
	{
		cout<<"\n\n*********Operations*****************\n";
		cout<<"1. Enter trainees attended data\n";
		cout<<"2. Find whether trainee attended or not\n";
		cout<<"3. Quit\n";
		cout<<"Choice - ";
		cin>>ch;

		switch(ch)
		{
			case 1: ot.input(); break;
			case 2: 
			{
				cout<<"\nEnter the trainee roll that you wanna search - ";
				cin>>s;
				if(ot.BinSr(s)== 1)
				cout<<"\nTrainee "<<s<<" attended the program...\n";
				else if(ot.BinSr(s)==0)
				cout<<"\nTrainee "<<s<<" didn't attend the program...\n";
			}
			break;

			case 3: cout<<"\n\nProgram Terminated....\n\n"; exit(0); break;
			default: cout<<"\nIncorrect option...\n\n";
		}

	}while(1);

	return 0;
}
						
		
