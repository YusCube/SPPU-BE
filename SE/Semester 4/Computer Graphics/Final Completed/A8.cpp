/*
Group A
Assignment 8

Write C++/Java program to draw the following pattern using any Line drawing algorithms.
*/

#include<graphics.h>
#include<iostream>

using namespace std;

void draw(int x1,int y1,int x2,int y2)
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

		putpixel(x,y,15);
		for(k=1;k<=step;k++)
		{
			x=x+xinc;
			y=y+yinc;
			putpixel(x,y,15);
		}

	}
int main()
{
	int gd=DETECT,gm;
	int ch,x1,y1,x2,y2;
	char a;
	initgraph(&gd,&gm,NULL);

    draw(100,100,300,100);
    draw(300,100,300,250);
    draw(300,250,100,250);
    draw(100,250,100,100);
    draw(200,100,300,175);
    draw(300,175,200,250);
    draw(200,250,100,175);
    draw(100,175,200,100);
    draw(150,137,250,137);
    draw(250,137,250,212);
    draw(250,212,150,212);
    draw(150,212,150,137);

	getch();
	closegraph();
	return 0;
}

/*
Output - 

[shivasaran@sss-ragemachine CGA]$ g++ A8.cpp -o A8 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./A8
[shivasaran@sss-ragemachine CGA]$

*/
