#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include<math.h>
int main()
{
int gm;
int gd=DETECT;
int x1,x2,x3,y1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3,c;
int sx,sy,xt,yt,r;
float t;
printf("\t Program for basic Transformation");
printf("\n\t Enter the points of triangle x1,y1,x2,y2,x3,y3");
scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
initgraph(&gd,&gm,NULL);
setcolor(1);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
delay(5000);
closegraph();
printf("\n 1.Translation\n 2.Rotation\n 3.Scaling\n 4.exit");
printf("Enter your choice:");
scanf("%d",&c);
switch(c)
{
case 1:
printf("\n Enter the translation factor");
scanf("%d%d",&xt,&yt);
nx1=x1+xt;
ny1=y1+yt;
nx2=x2+xt;
ny2=y2+yt;
nx3=x3+xt;
ny3=y3+yt;
initgraph(&gd,&gm,NULL);
setcolor(3);
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
delay(5000);
closegraph();
case 2:
printf("\n Enter the angle of rotation");
scanf("%d",&r);
//t=((3.14*r)/180);
nx1=abs(x1*cos(90)-y1*sin(90));
ny1=abs(x1*sin(90)+y1*cos(90));
nx2=abs(x2*cos(90)-y2*sin(90));
ny2=abs(x2*sin(90)+y2*cos(90));
nx3=abs(x3*cos(90)-y3*sin(90));
ny3=abs(x3*sin(90)+y3*cos(90));
initgraph(&gd,&gm,NULL);
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
delay(5000);
closegraph();
case 3:
printf("\n Enter the scalling factor");
scanf("%d%d",&sx,&sy);
nx1=x1*sx;
ny1=y2*sy;
nx2=x2*sx;
ny2=y2*sy;
nx3=x3*sx;
ny3=y3*sy;
initgraph(&gd,&gm,NULL);
setcolor(4);
line(nx1,ny1,nx2,ny2);
line(nx2,ny2,nx3,ny3);
line(nx3,ny3,nx1,ny1);
delay(5000);
closegraph();
case 4:
break;
default:
printf("Enter the correct choice");
}
closegraph();
return 0;
}

