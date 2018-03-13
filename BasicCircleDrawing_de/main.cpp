#include <iostream>
#include <cmath>
#include<graphics.h>
#include<winbgim.h>

#define windowX 600
#define windowY 400
#define PI acos(-1)

#define sz 100

using namespace std;

int centerX, centerY, radius, counter;

struct st{
    int x, y;
};

st list1[sz], list2[sz], list3[sz], list4[sz];

int roundingValue(double temp)
{
    return floor(temp+0.5);
}

void directEquationOfCircle()
{
    double a, b, theta = 0.0;
    double rad;

    for(int i=0; i<=90; i++)
    {
        counter++;
        rad = theta * (PI/180.0);
        a = centerX + (radius * cos(rad) );
        b = centerY + (radius * sin(rad) );

        list1[i].x =  roundingValue(a);
        list1[i].y =  roundingValue(b);

        theta += 1.0;

        list2[i].x = centerX - (list1[i].x - centerX);
        list2[i].y = list1[i].y;

        list3[i].x = list1[i].x;
        list3[i].y = centerY - (list1[i].y - centerY);

        list4[i].x = centerX - (list1[i].x - centerX);
        list4[i].y = centerY - (list1[i].y - centerY);
    }
    //cout<<endl;
}

void stop()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";

    while(!kbhit())
        Sleep(1);
}

void drawaCircle()
{
    initwindow(windowX, windowY, "Basic Circle Drawing");

    int a = list1[0].x;
    int b = list1[0].y;
    int c = list2[0].x;
    int d = list2[0].y;
    int e = list3[0].x;
    int f = list3[0].y;
    int g = list4[0].x;
    int h = list4[0].y;

    setcolor(5);
    circle(centerX, centerY, 2);

    setcolor(10);
    for(int i=1; i<counter; i++)
    {
        line(a, b, list1[i].x, list1[i].y);
        line(c, d, list2[i].x, list2[i].y);
        line(e, f, list3[i].x, list3[i].y);
        line(g, h, list4[i].x, list4[i].y);

        a = list1[i].x;
        b = list1[i].y;
        c = list2[i].x;
        d = list2[i].y;
        e = list3[i].x;
        f = list3[i].y;
        g = list4[i].x;
        h = list4[i].y;
    }

    stop();
}

int main()
{
    cout << "Enter the value of center : " <<endl;
    cin>>centerX>>centerY;

    cout<<"\nEnter the value of Radius : ";
    cin>>radius;

    directEquationOfCircle();

    drawaCircle();

    return 0;
}
