#include <iostream>
#include<graphics.h>
#include<winbgim.h>
#include<math.h>
#include<stdio.h>

#define windowX 600
#define windowY 400

int xMin, xMax, yMin, YMax, xl, yl, xh, yh;

using namespace std;

void getInput();
bool testSign(int a, int b);
void endPointCalculation();
void drawInGraph();
void stop();

int main()
{
    getInput();
    endPointCalculation();
    drawInGraph();

    return 0;
}

void getInput()
{
    cout<<  "Enter the lower points of the clipping window : ";
    cin>>xMin>>yMin;

    cout<<  "Enter the Upper points of the clipping window : ";
    cin>>xMax>>YMax;

    cout<<  "Enter the lower points of the Line : ";
    cin>>xl>>yl;

    cout<<  "Enter the Upper points of the Line : ";
    cin>>xh>>yh;
}

void endPointCalculation()
{
    bool Al, Bl, Rl, Ll, Ah, Bh, Rh, Lh;

    Al = testSign(yl, YMax);
    Ah = testSign(yh, YMax);

    Bl = testSign(yMin, yl);
    Bh = testSign(yMin, yh);

    Rl = testSign(xl, xMax);
    Rh = testSign(xl, xMax);

    Ll = testSign(xMin, xl);
    Lh = testSign(xMin, xh);

    cout<<"\n\nThe OutPut is : \n\n";
    if( (Al==Ah) && (Bl==Bh) && (Rl==Rh) && (Ll==Lh) )
        cout<< "Visible";
    else if( (Al&Ah) || (Bl&Bh) || (Rl&Rh) || (Ll&Lh) )
        cout << "Not Visible";
    else
        cout<< "Clipping Candidate";

    cout<<endl<<endl;
}

bool testSign(int a, int b)
{
    if(a>=b)
        return true;
    return false;
}

void drawInGraph()
{
    initwindow(windowX, windowY, "Line Clipping");
    rectangle(xMin, yMin, xMax, YMax);
    Sleep(1000);
    line(xl, yl, xh, yh);
    stop();
}

void stop()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";

    while(!kbhit())
        Sleep(1);
}

/*
50 30
400 300
70 60
350 280

50 30
300 200
20 250
500 220

50 30
400 300
200 20
200 400

*/
