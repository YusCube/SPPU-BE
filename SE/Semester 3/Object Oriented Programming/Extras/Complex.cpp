/*
Implement a class Complex which represents the Complex Number data type. Implement the
following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.
*/
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

class Complex
{
	float x, y;
	public:
	Complex()
	{
		x = 0;
		y = 0;
		cout<<"\nDefault Constructor...!\nx + iy = "<<x<<" + "<<y<<"i"<<endl<<endl;;
	}
			
	Complex(float real, float imag)
	{
		x = real;
		y = imag;
	}

	friend istream & operator >> (istream &din, Complex &a)
	{
		din>>a.x;
		din>>a.y;
		return (din);
	}
	
	friend ostream & operator << (ostream &dout, Complex &a) 
	{
		dout<<a.x<<" + "<<a.y<<"i\n";
		return (dout);
	}
	
	Complex operator + (Complex a)
	{
		Complex temp;
		temp.x = x+a.x;
		temp.y = y+a.y;
		return(temp);
	}
	
	Complex operator * (Complex a)
	{
		Complex temp;
		temp.x = x*a.x;
		temp.y = y*a.y;
		return(temp);
	}
	
	/*void display()
	{
		cout<<x<<" + "<<y<<"i\n";
	}*/
};

int main()
{
	Complex C1;
	cout<<endl<<"Enter the first x and y of the Complex Equation";
	cin>>C1; 
	//cout<<" First - ";
	//cout<<C1;
	Complex C2;
	cout<<endl<<"Enter the second x and y of the Complex Equation";
	cin>>C2; 
	Complex C3 = C1+C2;
	Complex C4 = C1*C2;
	cout<<"Complex Addition = "<< C3 <<endl;
	cout<<"Complex Multiplication = "<<C4<<endl;
}
