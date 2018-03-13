#include <iostream>
#include<graphics.h>
#include<winbgim.h>
#include<math.h>
#include<stdio.h>

#define windowX 600
#define windowY 400

#define sz 100000

using namespace std;

struct st
{
    int x, y;
} list[sz];

int lx, ly, hx, hy;


void getInput()
{
    cout<<"Enter the first end point : ";
    scanf("%d%d", &lx, &ly);
    cout<<"Enter the second end point : ";
    scanf("%d%d", &hx, &hy);
}


int roundingValue(double temp)
{
    return floor(temp+0.5);
}


int absoluteValue(int temp)
{
    if(temp>=0)
        return temp;
    else
        return -temp;
}


int calculation_y_by_DLE(double m, int i, int b)
{
    int temp = roundingValue( b + (m*i) );

    return temp;
}


void stop()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";

    while(!kbhit())
        Sleep(1);
}


void drawaLine(int size)
{
    initwindow(windowX, windowY, "Basic Line Drawing");

    setcolor(10);

    for(int i=0; i<size; i++)
    {
        circle(list[i].x, list[i].y, 1);
    }

    stop();
}


void directLineEquation()
{
    double m = 1.0 / ( (1.0 * (absoluteValue(hx-lx) ) ) / (1.0 * (absoluteValue(hy-ly) )) );

    int b = ly - (m*lx);
    int size = 0;

    for(int i=lx; (i<=hx) && (i<sz); i++)
    {
        list[size].x = i;
        list[size].y = calculation_y_by_DLE(m, i, b);
        size++;
    }

    drawaLine(size);
}

void DDA()
{
    double m = 0.0;
    if( (hy-ly) != 0)
        m= 1.0 /  ((1.0 * (absoluteValue(hx-lx) ) ) / (1.0 * (absoluteValue(hy-ly) ) ) );

    //cout<<temp_m<<endl;

    int size = 1;
    list[0].x = lx;
    list[0].y = ly;

    for(int i=lx+1; (i<=hx) && (i<sz); i++)
    {
        list[size].x = i;
        list[size].y = roundingValue(list[size-1].y + m);
        size++;
    }

    drawaLine(size);
}


void Bresenham()
{
    int ax=lx, ay=ly;
    int dx = hx-lx;
    int dy = hy-ly;
    int dt = 2*(dy-dx);
    int ds = 2*dy;

    int d = (2*dy) - dx;
    int size=0;

    list[0].x = ax;
    list[0].y = ay;

    while(ax < hx)
    {
        ax++;

        if(d<0)
        {
            d = d+ds;
        }
        else
        {
            ay++;
            d = d+dt;
        }

        list[size].x = ax;
        list[size].y = ay;
        size++;
    }

    drawaLine(size);
}


int main()
{
    int choice;

    cout<<"Enter Your Choice : "<<endl;
    cout<<"\t1 For Direct Line Equation"<<endl;
    cout<<"\t2 For DDA"<<endl;
    cout<<"\t3 For Bresenham"<<endl;

    cin>>choice;

    if(choice==1 || choice==2 || choice==3)
    {
        getInput();

        if(choice == 1)
        {
            directLineEquation();
        }
        else if(choice == 2)
        {
            DDA();
        }
        else if(choice == 3)
        {
            Bresenham();
        }
    }
    else
    {
        cout<<"Not Valid\n";
    }

    return 0;
}
