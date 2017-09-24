/*

Write a function template selection Sort. Write a program that inputs, sorts and outputs an int
array and a float array.

*/

#include<iostream>
using namespace std;

template <class T1, class T2>
class SampleTemplate
{
	public:	
	T1 a;
	T2 b;
	public:
	SampleTemplate(T1 x, T2 y)
	{
		a = x;
		b = y;
	}

	void display()
	{
		cout<<endl<<a<<" "<<b<<endl;
	}
};
int main()
{
	SampleTemplate<int, string> test1(2013, "ABCD");
	SampleTemplate<float, int> test2(100.2, 500);	
	test1.display();
	test2.display();
	return 0;
}
