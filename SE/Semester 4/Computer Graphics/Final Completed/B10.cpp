/*
Group B
Assignment 10

Write C++/Java program for line drawing using DDA or Bresenhams algorithm with patterns
such as solid, dotted, dashed, dash dot and thick.
*/

#include<graphics.h>
#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class pt
{
	protected:
		int xco,yco;
	public:
		pt()
		{
			xco=0;yco=0;
		}
		void setco(int x,int y)
		{
			xco=x;
			yco=y;
		}
		void draw()
		{
			putpixel(xco,yco,15);
		}
};

class dline: public pt //derived class
{
	private:
		int x2,y2;
	public:
		dline():pt()
		{
			x2=0,y2=0;
		}
		void setline(int x, int y, int xx, int yy)
		{
			pt::setco(x,y);
			x2=xx;
			y2=yy;
		}
		void drawsi() //Simple DDA Line
		{
			float x,y,dx,dy,len;
			int i;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			if(dx >= dy)
			{
				len=dx;
			}
			else
			{
				len=dy;
			}
			dx=(x2-xco)/len;
			dy=(y2-yco)/len;
			x = xco + 0.5;
			y = yco + 0.5;
			i=1;
			while(i<=len)
			{
				pt::setco(x,y);
				pt::draw();
				x = x + dx;
				y = y + dy;
				i = i + 1;
			}
			pt::setco(x,y);
			pt::draw();
		}
		void drawda() //Dash DDA Line
		{
			float x,y,dx,dy,len;
			int i,dash_pixel=0, dash_space=0;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			if(dx >= dy)
			{
				len=dx;
			}
			else
			{
				len=dy;
			}
			dx=(x2-xco)/len;
			dy=(y2-yco)/len;
			x = xco + 0.5;
			y = yco + 0.5;
			i=1;
			while(i<=len)
			{
				dash_pixel=0;
				while(dash_pixel<5)
				{
					pt::setco(x,y);
					pt::draw();
					x = x + dx;
					y = y + dy;
					i = i + 1;
					dash_pixel = dash_pixel +1;
				}
				dash_space=0;
				while(dash_space<=2)
				{
					x = x + dx;
					y = y + dy;
					i = i + 1;
					dash_space = dash_space +1;
				}
			}
		}
		void drawdo() //Dotted DDA Line
		{
			float x,y,dx,dy,len;
			int i,dot_space;
			dx=abs(x2-xco);
			dy=abs(y2-yco);
			if(dx >= dy)
			{
				len=dx;
			}
			else
			{
				len=dy;
			}
			dx=(x2-xco)/len;
			dy=(y2-yco)/len;
			x = xco + 0.5;
			y = yco + 0.5;
			i=1;
			while(i<=len)
			{
				dot_space=0;
				while(dot_space<=1)
				{
					x = x + dx;
					y = y + dy;
					i = i + 1;
					dot_space = dot_space +1;
				}
				pt::setco(x,y);
				pt::draw();
			}
		}
		void drawth(int x1,int y1, int x2, int y2,int colour=15 )
		{
			float x,y,dx,dy,len;
			int i;
			dx=abs(x2-x1);
			dy=abs(y2-y1);
			if(dx >= dy)
			{
				len=dx;
			}
			else
			{
				len=dy;
			}
			dx=(x2-x1)/len;
			dy=(y2-y1)/len;
			x = x1 + 0.5;
			y = y1 + 0.5;
 			i=1;
			while(i<=len)
			{
				putpixel(x,y,15);
				x = x + dx;
				y = y + dy;
				i = i + 1;
			}
			putpixel(x,y,15);
		}
};

int main()
{
	int gd=DETECT,gm;
	int i, ch,x1,y1,x2,y2, dx,dy,xmax,ymax,xmid,ymid,wx,wy,th;
	char a;
	initgraph(&gd,&gm,NULL);
	//setbkcolor(BLACK);
	//setcolor(WHITE);
	dline ls;
	xmax = getmaxx();
	ymax = getmaxy();
	xmid = xmax /2;
	ymid = ymax /2;
	line(xmid,0,xmid,ymax); //Y co-ordinate
	line(0,ymid,xmax,ymid); //X co-ordinate
	do
	{
		cout<<"\nEnter Line Styles";
		cout<<"\n1.SIMPLE";
		cout<<"\n2.DASH";
		cout<<"\n3.DOTTED";
		cout<<"\n4.THICK";
		cout<<"\n5.EXIT";
		cout<<"\nChoice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"Enter x1,y1:\n";
				cin>>x1>>y1;
				cout<<"Enter x2,y2:\n";
				cin>>x2>>y2;
				ls.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
				ls.drawsi();
			break;
			case 2:
				cout<<"Enter x1,y1:\n";
				cin>>x1>>y1;
				cout<<"Enter x2,y2:\n";
				cin>>x2>>y2;
				ls.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
				ls.drawda();
			break;
			case 3:
				cout<<"Enter x1,y1:\n";
				cin>>x1>>y1;
				cout<<"Enter x2,y2:\n";
				cin>>x2>>y2;
				ls.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
				ls.drawdo();
			break;
			case 4:
				cout<<"Enter x1,y1:\n";
				cin>>x1>>y1;
				cout<<"Enter x2,y2:\n";
				cin>>x2>>y2;
				cout<<"Enter Thickness:\n";
				cin>>th;
				ls.drawth(x1+xmid,ymid-y1,x2+xmid,ymid-y2,0);
				if((y2-y1)/(x2-x1) <1)
				{
					wy=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(x2-x1));
					for(i=0;i<wy;i++)
					{
						ls.drawth(x1+xmid,ymid-y1-i,x2+xmid,ymid-y2-i,0);
						ls.drawth(x1+xmid,ymid-y1+i,x2+xmid,ymid-y2+i,0);
					}
				}
				else
				{
					wx=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(y2-y1));
					for(i=0;i<wx;i++)
					{
						ls.drawth(x1+xmid-i,ymid-y1,x2+xmid-i,ymid-y2,0);
						ls.drawth(x1+xmid+i,ymid-y1,x2+xmid+i,ymid-y2,0);
					}
				}
			break;
			case 5:
				exit (0);
			break;
		}
		cout<<"\nDo you wanna continue (y/n): ";
		cin>>a;
	}while(a=='y');
	//exit(0);
	getch();
	closegraph();
	return 0;
}
/*
Output - 
[shivasaran@sss-ragemachine CGA]$ g++ B10.cpp -o B10 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./B10

Enter Line Styles
1.SIMPLE
2.DASH
3.DOTTED
4.THICK
5.EXIT
Choice: 1
Enter x1,y1:
50 50
Enter x2,y2:
200 50

Do you wanna continue (y/n): y

Enter Line Styles
1.SIMPLE
2.DASH
3.DOTTED
4.THICK
5.EXIT
Choice: 2
Enter x1,y1:
50 70
Enter x2,y2:
200 70

Do you wanna continue (y/n): y

Enter Line Styles
1.SIMPLE
2.DASH
3.DOTTED
4.THICK
5.EXIT
Choice: 3
Enter x1,y1:
50 90
Enter x2,y2:
200 90

Do you wanna continue (y/n): y

Enter Line Styles
1.SIMPLE
2.DASH
3.DOTTED
4.THICK
5.EXIT
Choice: 4
Enter x1,y1:
50 110
Enter x2,y2:
200
110
Enter Thickness:
5

Do you wanna continue (y/n): n
[shivasaran@sss-ragemachine CGA]$ 

*/
