/*
Group A
Assignment 2
 
Write C++/Java program to draw circle using Bresenham‘s algorithm. Inherit pixel class.

*/

# include<iostream>
# include<graphics.h>

using namespace std;

class pixel
{
public:
    void putpix(int x,int y,int color)
    {
        putpixel(x,y,color);
    }
};
class brecircle : public pixel
{
        int gd=DETECT,gm;
    	int xc,yc,r,x,y,Pk;

public:
    void brecircledraw()
    {
        cout<<"Enter the coordinates for center point:\n";
        cin>>xc>>yc;
        cout<<"Enter the Radius of circle\n";
        cin>>r;
        x=0;
        y=r;
        initgraph(&gd,&gm,NULL);

        putpix(xc+x,yc-y,15);
        Pk=3-(2*r);
        for(x=0;x<=y;x++)
        {
        	if (Pk<0)
        	{
                	y=y;
                	Pk=(Pk+(4*x)+6);
                }
                else
                {
                	y=y-1;
                        Pk=Pk+((4*(x-y)+10));
                }
                putpix(xc+x,yc-y,15);
                putpix(xc-x,yc-y,15);
                putpix(xc+x,yc+y,15);
                putpix(xc-x,yc+y,15);
                putpix(xc+y,yc-x,15);
                putpix(xc-y,yc-x,15);
                putpix(xc+y,yc+x,15);
                putpix(xc-y,yc+x,15);
        }
    }
};
int main()
{
        brecircle pix;
        pix.brecircledraw();

	getch();
	closegraph();
	return 0;
}

/*
Output - 

[shivasaran@sss-ragemachine CGA]$ g++ A2.cpp -o A2 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./A2
Enter the coordinates for center point:
300
300
Enter the Radius of circle
150

[shivasaran@sss-ragemachine CGA]$

