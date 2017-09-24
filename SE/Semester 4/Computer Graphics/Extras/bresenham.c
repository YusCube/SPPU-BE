#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
void main()
{
int x1,y1,x2,y2,dx,dy,ddx,ddy,p;
int gdriver = DETECT,gmode;

printf("\nEnter values for X1 & Y1:");
scanf("%d%d",&x1,&y1);
printf("\nEnter values for X2 & Y2:");
scanf("%d%d",&x2,&y2);
initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
putpixel(x1,y1,10);
dx=x2-x1;
dy=y2-y1;
ddx=2*dx;
ddy=2*dy;
p=ddy-dx;
do
{
if(p<0)
{
x1=x1+1;
delay(100);
putpixel(x1,y1,8);
p=p+ddy;
}
else
{
x1=x1+1;
y1=y1+1;
delay(100);
putpixel(x1,y1,8);
p=p+ddy-ddx;
}
dx=dx-1;
}while(dx!=0);
getch();
closegraph();
}
