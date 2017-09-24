/*
Group B
Assignment 11

Write C++/Java program to draw a convex polygon and fill it with desired color using Seed
fill algorithm.

*/

#include<stdio.h>
#include<graphics.h>
void flood(int,int,int,int);
void bfill(int,int,int,int);
void main()

{
	int gd = DETECT, gm;
	printf("Enter type of Seed fill algorithm\n1. Flood Fill\n2. Boundary Fill\nChoice - ");
	int ch;
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			initgraph (&gd, &gm, "..\\bgi");
			rectangle(50,50,100,100);
			flood(55,55,12,0);
		break;

		case 2:
			initgraph (&gd, &gm, "..\\bgi");
			setcolor(12);
			rectangle(50,50,100,100);
			bfill(55,55,12,10);
			break;
	}
	getch();
}

void bfill(int sx,int sy,int bc,int fc)
{
	if((getpixel(sx,sy)!=fc)&&(getpixel(sx,sy)!=bc))
	{
		delay(1);
		putpixel(sx,sy,fc);
		bfill(sx+1,sy,bc,fc);
		bfill(sx-1,sy,bc,fc);
		bfill(sx,sy+1,bc,fc);
		bfill(sx,sy-1,bc,fc);
	}
}

void flood(int x,int y, int fill_col, int old_col)
{
	if(getpixel(x,y)==old_col)
	{
		delay(1);
		putpixel(x,y,fill_col);
		flood(x+1,y,fill_col,old_col);
		flood(x-1,y,fill_col,old_col);
		flood(x,y+1,fill_col,old_col);
		flood(x,y-1,fill_col,old_col);
	}
}

/*
Output - 
[shivasaran@sss-ragemachine CGA]$ gcc B11.c -o B11 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./B11
Enter type of Seed fill algorithm
1. Flood Fill
2. Boundary Fill
Choice - 1

[shivasaran@sss-ragemachine CGA]$ ./B11
Enter type of Seed fill algorithm
1. Flood Fill
2. Boundary Fill
Choice - 2

*/

