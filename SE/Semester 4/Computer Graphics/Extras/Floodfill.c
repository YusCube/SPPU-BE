#include<stdio.h>
#include<graphics.h>
void MAK(int,int,int,int);


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi;");
	rectangle(50,50,200,200);
	MAK(199,199,1,0);
	getch();
	return 0;
}

void MAK(int x,int y,int fill_cd,int dd_cd)
{
  if(getpixel(x,y)==dd_cd)
	{
	 delay(0.01);
	 putpixel(x,y,fill_cd);
	 MAK(x+1,y,fill_cd,dd_cd);
	 MAK(x-1,y,fill_cd,dd_cd);
	 MAK(x,y+1,fill_cd,dd_cd);
	 MAK(x,y-1,fill_cd,dd_cd);
	}
}
