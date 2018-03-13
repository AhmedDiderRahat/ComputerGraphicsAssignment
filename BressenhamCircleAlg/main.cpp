#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#include <stdio.h>

using namespace std;

void stop()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";

    while(!kbhit())
        Sleep(1);
}

void bresenhamCircle(int r)
{
    initwindow(800,400,"Circle");

    int x=0, y=r, h=400, k=200;

    int d=3-2*r;

    while(x<=y)
    {
        putpixel(x+h,y+k,15);
        putpixel(y+h,x+k,15);
        putpixel(-y+h,x+k,15);
        putpixel(-x+h,y+k,15);
        putpixel(-x+h,-y+k,15);
        putpixel(-y+h,-x+k,15);
        putpixel(y+h,-x+k,15);
        putpixel(x+h,-y+k,15);

        if(d<0)
        {
            d=d+4*x+6;
        }
        else
        {
            d=d+4*(x-y)+10;
            y--;
        }
       x++;
    }

    stop();
}

int main()
{
    int r;

    cout<<"Enter The Radius of the circle :  ";
    cin>>r;

    bresenhamCircle(r);

    return 0;
}
