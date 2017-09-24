/*
Group B
Assignment 22

Write C++/Java program to draw 3-D cube and perform following transformations on it using
OpenGL. a) Scaling b) Translation c) Rotation about one axis

*/

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

void main()
{
	int gd=DETECT,gm;
	int x,y,x1,y1,choice;
	int ux,uy;
	printf("Enter points for 3d bar\n");
	scanf("%d%d%d%d",&x,&y,&x1,&y1);
	initgraph(&gd,&gm,"");
	bar3d(x,y,x1,y1,100,1);
	delay(2000);
	//closegraph();
	printf("Enter choice\n1)Translation\n2)Scaling\nChoice - ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
       		printf("Enter translation factor\n");
       		scanf("%d%d",&ux,&uy);
			initgraph(&gd,&gm,"");
			setcolor(1);
       		x=ux+x;
       		y=uy+y;
       		x1=ux+x1; 
       		y1=uy+y1;
       		bar3d(x,y,x1,y1,100,1);
			delay(2000);
			//closegraph();
			break;
	
		case 2:
      		printf("Enter Scaling Factor\n");
      		scanf("%d%d",&ux,&uy);
			initgraph(&gd,&gm,"");
			setcolor(4);
       		x=ux*x;
       		y=uy*y;
       		x1=ux*x1; 
       		y1=uy*y1;
       		bar3d(x,y,x1,y1,100,1);
			delay(2000);
			//closegraph();
			break;
	
		default:
 			printf("Wrong choice");
			break;
	}
	getch();
	closegraph();
}

/*
Output - 
[shivasaran@sss-ragemachine CGA]$ gcc C22.c -o C22 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./C22
Enter points for 3d bar50
100
150
200

[shivasaran@sss-ragemachine CGA]$ ./C22
Enter points for 3d bar
50
70
90
120

*/
