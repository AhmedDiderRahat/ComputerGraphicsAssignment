#include <iostream>
#include <stdio.h>
#include<graphics.h>
#include<winbgim.h>
#include<math.h>

#define PI acos(-1)
#define windowX 600
#define windowY 400

using namespace std;

void stop()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";

    while(!kbhit())
        Sleep(1);
}

int main()
{
    int gm,gr,xcmin,ycmin,xcmax,ycmax,x,y,c;

    initwindow(windowX, windowY, "Point Clip.");

    printf("Enter the clipmin coordinate :\n");
    scanf("%d%d", &xcmin, &ycmin);

    printf("Enter the clipmax coordinate :\n");
    scanf("%d%d", &xcmax, &ycmax);

    //rectangle(xMin, yMin, xMax, YMax);
    rectangle(xcmin,ycmin, xcmax,ycmax);
   // line

    printf("Enter the coordinate of the point:\n");
    scanf("%d%d",&x,&y);

 //   putpixel(x,y,15);

//    rectangle(xcmin,ycmax,xcmax,ycmin);

    if((xcmin<=x) && (x<=xcmax))
    {
        if((ycmin<=y) && (y<=ycmax))
        {
            cout<<"\n\nThe point is inside the clip window\n";
        }
        else
            cout<<"\n\nThe point is outside the clipwindow\n";

        circle(x, y, 2);
    }

    cout<<endl<<endl<<endl;

    stop();

    return 0;
}

/*
30 30
300 300
50 50


*/
