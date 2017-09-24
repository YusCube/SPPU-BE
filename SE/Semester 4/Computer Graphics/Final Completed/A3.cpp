/*
Group A
Assignment 3

Write C++/Java program to draw 2-D object and perform following basic transformations, 
a) Scaling 
b) Translation 
c) Rotation 
Use operator overloading.

*/

#include<iostream>
#include<graphics.h>
#include<math.h>
#define SIZE 20

using namespace std;

class Translate1
{
      private:
                float input[SIZE][3],no;
                float sclmat[3][3];
                float rotmat[3][3],transmat[3][3];
                float resm[SIZE][3],mat1[SIZE][3];
      public:
                void accept();
                void Scale();
                void Translate();
                void Rotate();
                void multiply(float a[SIZE][3],float b[3][3],float c[SIZE][3]);
                void plot(float mat[SIZE][3]);

};
void Translate1::accept()
{
    int i,j;
    cleardevice();
    for(i=0;i<no;i++)
        for(j=0;j<3;j++)
            input[i][j]=1;
    cout<<"Enter the number of vertices in figure";
    cin>>no;
    cout<<"Enter the co-ordinate in matrix form\n";
    for(i=0;i<no;i++)
    {
        for(j=0;j<2;j++)
         {
            cout<<"A["<<i<<"]["<<j<<"]=";
            cin>>input[i][j];
         }
    }
    for(i=0;i<no;i++)
            input[i][2]=1;
    plot(input);
}
void Translate1::Scale()
{
    int i,j;
    float sx,sy;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            sclmat[i][j]=0;
    for(i=0;i<no;i++)
        for(j=0;j<3;j++)
            resm[i][j]=0;

    cout<<"Enter values of Sx & Sy : \n";
    cin>>sx>>sy;

    sclmat[0][0]=sx;
    sclmat[1][1]=sy;
    sclmat[2][2]=1;

    multiply(input,sclmat,resm);
    plot(resm);
}
void Translate1::Translate()
{

    int i,j,tx,ty;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            transmat[i][j]=0;
    for(i=0;i<no;i++)
        for(j=0;j<3;j++)
            resm[i][j]=0;

    cout<<"Enter values of tx & ty : \n";
    cin>>tx>>ty;

    transmat[2][0]=tx;
    transmat[2][1]=ty;
    transmat[0][0]=transmat[1][1]=transmat[2][2]=1;

    multiply(input,transmat,resm);
    plot(resm);
}
void Translate1::Rotate()
{
    int deg,i,j;
    float rad,pi=22/7;
    cout<<"Enter the angle of rotation : ";
    cin>>deg;
    rad=(deg)*pi/171;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            rotmat[i][j]=0;
    for(i=0;i<no;i++)
        for(j=0;j<3;j++)
            resm[i][j]=0;


    rotmat[0][0]=rotmat[1][1]=cos(rad);
    rotmat[0][1]=sin(rad);
    rotmat[1][0]=-sin(rad);
    rotmat[2][2]=1;

    multiply(input,rotmat,resm);
    plot(resm);
}

void Translate1::multiply(float a[SIZE][3],float x[3][3],float c[SIZE][3])
{
    int i,j,k;

    for(i=0;i<no;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                c[i][j]+=(int)a[i][k]*x[k][j];

    for(i=0;i<no;i++)
        for(j=0;j<3;j++)
            a[i][j]=c[i][j];
}
void Translate1::plot(float mat[SIZE][3])
{
    cleardevice();
    int i,x,y;
    setcolor(10);
    x=getmaxx();
    y=getmaxy();

    line(x/2,0,x/2,y);
    line(0,y/2,x,y/2);

        for(i=0;i<no;i++)
        {
            if(mat[i][0]>=0)
                mat1[i][0]=mat[i][0]+x/2;
            else
                mat1[i][0]=x/2+mat[i][0];
        }

        for(i=0;i<no;i++)
        {
            if(mat[i][1]>=0)
                mat1[i][1]=(y/2)-mat[i][1];
            else
                mat1[i][1]=y/2-mat[i][1];
        }
    setcolor(WHITE);
    for(i=0;i<no-1;i++)
     {
         line(mat1[i][0],mat1[i][1],mat1[i+1][0],mat1[i+1][1]);
     }
     line(mat1[i][0],mat1[i][1],mat1[0][0],mat1[0][1]);
}
int main()
{
    int gd=DETECT,gm,i;
    initgraph(&gd,&gm,NULL);
    char ch;
    Translate1 t;
    t.accept();
    do{
            cout<<"\n1. For Scalling ";
            cout<<"\n2. For Translate ";
            cout<<"\n3. For Rotate ";
            cout<<"\n4.  For Exit\nChoice - ";
            cin>>i;
        switch(i)
        {
            case 1:
                t.Scale();
                break;
            case 2:
                t.Translate();
                break;
            case 3:
                t.Rotate();
                break;
            case 4:
                break;
            default:
                cout<<"Sorry !!!!   Wrong Input";
        }

        cout<<"Do you want to continue (y/n): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    closegraph();
    return 0;
}

/*
Output - 
[shivasaran@sss-ragemachine CGA]$ g++ A3.cpp -o A3 -lgraph
[shivasaran@sss-ragemachine CGA]$ ./A3
Enter the number of vertices in figure - 5

Enter the co-ordinate in matrix form
A[0][0]=20
A[0][1]=20
A[1][0]=60
A[1][1]=20
A[2][0]=90
A[2][1]=50
A[3][0]=60
A[3][1]=100
A[4][0]=20
A[4][1]=100

1. For Scalling 
2. For Translate 
3. For Rotate 
4. For Exit
Choice - 1

Enter values of Sx & Sy : 
2
2

Do you want to continue : (y/n) y


1. For Scalling 
2. For Translate 
3. For Rotate 
4.  For Exit
Choice - 2

Enter values of tx & ty : 
10
20

Do you want to continue(y/n): y

1. For Scalling 
2. For Translate 
3. For Rotate 
4.  For Exit
Choice - 3

Enter the angle of rotation : 60

Do you want to continue (y/n): n

[shivasaran@sss-ragemachine CGA]$ 

*/

