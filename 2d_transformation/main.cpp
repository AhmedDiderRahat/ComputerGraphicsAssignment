#include <iostream>
#include <stdio.h>
#include<graphics.h>
#include<winbgim.h>
#include<math.h>

#define PI acos(-1)
#define windowX 600
#define windowY 400

double function_matrix[10][10];
int input_matrix[10][10];
int output_matrix[10][10];
double theta;
int ox1, ox2, ox3, oy1, oy2, oy3, tx, ty, Sx, Sy;
int nx1, nx2, nx3, ny1, ny2, ny3;

using namespace std;

void getInput()
{
    cout<<"Enter the first end point : ";
    scanf("%d%d", &ox1, &oy1);
    cout<<"Enter the second end point : ";
    scanf("%d%d", &ox2, &oy2);
    cout<<"Enter the third end point : ";
    scanf("%d%d", &ox3, &oy3);
}

void create_input_Matrix()
{
    input_matrix[0][0] = ox1;
    input_matrix[0][1] = ox2;
    input_matrix[0][2] = ox3;
    input_matrix[1][0] = oy1;
    input_matrix[1][1] = oy2;
    input_matrix[1][2] = oy3;
    input_matrix[2][0] = 1;
    input_matrix[2][1] = 1;
    input_matrix[2][2] = 1;
}

void create_scaling_Matrix()
{
    function_matrix[0][0] = Sx;
    function_matrix[0][1] = 0.0;
    function_matrix[0][2] = 0.0;
    function_matrix[1][0] = 0.0;
    function_matrix[1][1] = Sy;
    function_matrix[1][2] = 0.0;
    function_matrix[2][0] = 0.0;
    function_matrix[2][1] = 0.0;
    function_matrix[2][2] = 1.0;
}

void create_rotation_Matrix()
{
    double rad = theta * (PI/180.0);

    function_matrix[0][0] = cos(rad);
    function_matrix[0][1] = -sin(rad);
    function_matrix[0][2] = 0.0;
    function_matrix[1][0] = sin(rad);
    function_matrix[1][1] = cos(rad);
    function_matrix[1][2] = 0.0;
    function_matrix[2][0] = 0.0;
    function_matrix[2][1] = 0.0;
    function_matrix[2][2] = 1.0;
}

void create_translation_Matrix()
{
    function_matrix[0][0] = 1.0;
    function_matrix[0][1] = 0.0;
    function_matrix[0][2] = tx;
    function_matrix[1][0] = 0.0;
    function_matrix[1][1] = 1.0;
    function_matrix[1][2] = ty;
    function_matrix[2][0] = 0.0;
    function_matrix[2][1] = 0.0;
    function_matrix[2][2] = 1.0;
}

void new_position()
{
    nx1 = output_matrix[0][0];
    ny1 = output_matrix[1][0];
    nx2 = output_matrix[0][1];
    ny2 = output_matrix[1][1];
    nx3 = output_matrix[0][2];
    ny3 = output_matrix[1][2];
}

int roundingValue(double temp)
{
    return floor(temp+0.5);
}

void calculation()
{
    int i, j, k, sum;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            sum = 0.0;
            for(k=0; k<3; k++)
            {
                sum = sum + (function_matrix[i][k] * (input_matrix[k][j] * 1.0));
            }
            output_matrix[i][j] = roundingValue(sum);
        }
    }
}

void draw_original(int color, int ax, int ay, int bx, int by, int cx, int cy)
{
    setcolor(color);

    line(ax, ay, bx, by);
    line(bx, by, cx, cy);
    line(ax, ay, cx, cy);

    Sleep(1000);
}

void stop()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";

    while(!kbhit())
        Sleep(1);
}

void scaling()
{
    cout<<"Enter Scaling input : "<<endl;
    cin>>Sx>>Sy;

    create_input_Matrix();

    initwindow(windowX, windowY, "2-D Scaling.");

    draw_original(5, ox1, oy1, ox2, oy2, ox3, oy3);
    Sleep(3000);

    create_scaling_Matrix();
    calculation();

    new_position();

    draw_original(10, nx1, ny1, nx2, ny2, nx3, ny3);
    Sleep(3000);

    stop();
}

void rotation()
{
    cout<<"Enter Rotation input : "<<endl;
    cin>>theta;

    create_input_Matrix();

    initwindow(windowX, windowY, "2-D Roation");

    draw_original(5, ox1, oy1, ox2, oy2, ox3, oy3);
    Sleep(3000);

    create_rotation_Matrix();
    calculation();

    new_position();
    draw_original(10, nx1, ny1, nx2, ny2, nx3, ny3);
    Sleep(3000);

    stop();
}

void traslation()
{
    cout<<"Enter The value of Tx and Ty : "<<endl;
    cin>>tx>>ty;

    create_input_Matrix();

    create_translation_Matrix();

    calculation();

    initwindow(windowX, windowY, "2-D Translation");

    draw_original(5, ox1, oy1, ox2, oy2, ox3, oy3);
    Sleep(3000);
    new_position();
    draw_original(10, nx1, ny1, nx2, ny2, nx3, ny3);

    stop();
}

int main()
{
    int choice;

    cout<<"Enter Your Choice : "<<endl;
    cout<<"\t1 For 2-D Traslation"<<endl;
    cout<<"\t2 For 2-D Rotation"<<endl;
    cout<<"\t3 For 2-D Scaling"<<endl;

    cin>>choice;

    if(choice==1 || choice==2 || choice==3)
    {
        getInput();

        if(choice == 1)
        {
            traslation();
        }
        else if(choice == 2)
        {
            rotation();
        }
        else if(choice == 3)
        {
            scaling();
        }
    }
    else
    {
        cout<<"Not Valid\n";
    }

    return 0;
}

/*
1
20 20
100 20
60 50
100 100

2
100 20
200 20
150 50
45

3
100 20
200 20
150 50
2 2

: 10 10 30 10 10 30
: 30 30 80 60 110 110

*/
