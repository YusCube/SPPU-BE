/*
Group A
Assignment 1

Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel
class and Use function overloading.
*/

#include<graphics.h>
#include<iostream>

using namespace std;

class pixel
{

	public:
	void draw(int x,int y)
	{
		putpixel(x,y,15);
	}
};

class drawline: public pixel
{
	public:
	void drawBRE(int x1,int y1,int x2,int y2)
	{
		int x,y,xend,yend,dy,dx,d;
		dx=x2-x1;
		dy=y2-y1;
		x=x1;
		y=y1;
		if(abs(dx)>=abs(dy))
		{
			d=(2*dy)-dx;
			while(x<=x2)
			{
				pixel::draw(x,y);
				x=x+1;
				if(d>=0)
				{
					y=y+1;
					d+=2*(dy-dx);
				}
				else
				d+=2*dy;
			}
		}
		else
		{
			d=(2*dx)-dy;
			while(y<=y2)
			{
				pixel::draw(x,y);

				y++;
				if(d>=0)
				{
					x=x+1;
					d+=2*(dx-dy);
				}
				else
				{
					d+=2*dx;
				}
			}
		}
	}

	void drawDDA(int x1,int y1,int x2,int y2)
	{
		int dx,dy,step,k;
		float xinc,yinc,x,y;
		dx=x2-x1;
		dy=y2-y1;

		if(abs(dx)>abs(dy))
		step=abs(dx);
		else
		step=abs(dy);

		xinc=dx/(float)step;
		yinc=dy/(float)step;

		x=x1;
		y=y1;

		pixel::draw(x,y);
		for(k=1;k<=step;k++)
		{
			x=x+xinc;
			y=y+yinc;
			pixel::draw(x,y);
		}
	}
};

int main()
{
	int gd=DETECT,gm;
	int ch,x1,y1,x2,y2;
	char a;
	initgraph(&gd,&gm,NULL);
	pixel p;
	drawline dl;
	while(1)
	{
		cout<<"\n1.DDA LINE..";
		cout<<"\n2.BRESENHAM'S LINE..";
		cout<<"\n3.EXIT..";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter (x1,y1)\n";
				cin>>x1>>y1;
				cout<<"\nEnter (x2,y2)\n";
				cin>>x2>>y2;
				dl.drawDDA(x1,y1,x2,y2);
			break;
			case 2:
				cout<<"\nEnter (x1,y1)\n";
				cin>>x1>>y1;
				cout<<"\nEnter (x2,y2)\n";
				cin>>x2>>y2;
				dl.drawBRE(x1,y1,x2,y2);
			break;
			case 3:
				exit (0);
			break;
		}
	}
	getch();
	closegraph();
return 0;
}

/*
Output - 

[shivasaran@sss-ragemachine ~]$ cd C++/CGA
[shivasaran@sss-ragemachine CGA]$ g++ A1.cpp -o A1 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./A1

1.DDA LINE..
2.BRESENHAM'S LINE..
3.EXIT..
Enter your choice: 1

Enter (x1,y1)
150
150

Enter (x2,y2)
250
250

1.DDA LINE..
2.BRESENHAM'S LINE..
3.EXIT..
Enter your choice: 2

Enter (x1,y1)
100
100

Enter (x2,y2)
300
300

1.DDA LINE..
2.BRESENHAM'S LINE..
3.EXIT..
Enter your choice: 3
[shivasaran@sss-ragemachine CGA]$
