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
int ox1, ox2, ox3, oy1, oy2, oy3, oz1, oz2, oz3, tx, ty, tz, Sx, Sy, Sz;
int nx1, nx2, nx3, ny1, ny2, ny3, nz1, nz2, nz3;

using namespace std;

void getInput()
{
    cout<<"Enter the first end point : ";
    scanf("%d%d%d", &ox1, &oy1, &oz1);
    cout<<"Enter the second end point : ";
    scanf("%d%d%d", &ox2, &oy2, &oz2);
    cout<<"Enter the third end point : ";
    scanf("%d%d%d", &ox3, &oy3, &oz3);
}

void create_input_Matrix()
{
    input_matrix[0][0] = ox1;
    input_matrix[0][1] = ox2;
    input_matrix[0][2] = ox3;
    input_matrix[0][3] = 1;
    input_matrix[1][0] = oy1;
    input_matrix[1][1] = oy2;
    input_matrix[1][2] = oy3;
    input_matrix[1][3] = 1;
    input_matrix[2][0] = oz1;
    input_matrix[2][1] = oz2;
    input_matrix[2][2] = oz3;
    input_matrix[2][3] = 1;
    input_matrix[3][0] = 1;
    input_matrix[3][1] = 1;
    input_matrix[3][2] = 1;
    input_matrix[3][3] = 1;
}

void create_scaling_Matrix()
{
    function_matrix[0][0] = Sx;
    function_matrix[0][1] = 0.0;
    function_matrix[0][2] = 0.0;
    function_matrix[0][3] = 0.0;

    function_matrix[1][0] = 0.0;
    function_matrix[1][1] = Sy;
    function_matrix[1][2] = 0.0;
    function_matrix[1][3] = 0.0;

    function_matrix[2][0] = 0.0;
    function_matrix[2][1] = 0.0;
    function_matrix[2][2] = Sz;
    function_matrix[2][3] = 0.0;

    function_matrix[3][0] = 0.0;
    function_matrix[3][1] = 0.0;
    function_matrix[3][2] = 0.0;
    function_matrix[3][3] = 1.0;
}

void create_rotation_Matrix()
{
    double rad = theta * (PI/180.0);

    function_matrix[0][0] = 1.0;
    function_matrix[0][1] = 0.0;
    function_matrix[0][2] = 0.0;
    function_matrix[0][3] = 0.0;


    function_matrix[1][0] = 0.0;
    function_matrix[1][1] = cos(rad);
    function_matrix[1][2] = -sin(rad);
    function_matrix[1][3] = 0.0;

    function_matrix[2][0] = 0.0;
    function_matrix[2][1] = sin(rad);
    function_matrix[2][2] = cos(rad);
    function_matrix[2][3] = 0.0;

    function_matrix[3][0] = 0.0;
    function_matrix[3][1] = 0.0;
    function_matrix[3][2] = 0.0;
    function_matrix[3][3] = 1.0;
}

void create_translation_Matrix()
{
    function_matrix[0][0] = 1;
    function_matrix[0][1] = 0;
    function_matrix[0][2] = 0;
    function_matrix[0][3] = tx;
    function_matrix[1][0] = 0;
    function_matrix[1][1] = 1;
    function_matrix[1][2] = 0;
    function_matrix[1][3] = ty;
    function_matrix[2][0] = 0;
    function_matrix[2][1] = 0;
    function_matrix[2][2] = 1;
    function_matrix[2][3] = tz;
    function_matrix[3][0] = 0;
    function_matrix[3][1] = 0;
    function_matrix[3][2] = 0;
    function_matrix[3][3] = 1;
}

void new_position()
{
    nx1 = output_matrix[0][0];
    ny1 = output_matrix[1][0];
    nz1 = output_matrix[2][0];
    nx2 = output_matrix[0][1];
    ny2 = output_matrix[1][1];
    nz2 = output_matrix[2][1];
    nx3 = output_matrix[0][2];
    ny3 = output_matrix[1][2];
    nz3 = output_matrix[2][2];

    cout<<"\nNew Position of the value are : \n";
    cout<<"1st position : "<<nx1<<" "<<ny1<<" "<<nz1<<endl;
    cout<<"2nd position : "<<nx2<<" "<<ny2<<" "<<nz2<<endl;
    cout<<"3rd position : "<<nx3<<" "<<ny3<<" "<<nz3<<endl;
}

int roundingValue(double temp)
{
    return floor(temp+0.5);
}

void calculation()
{
    int i, j, k, sum;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            sum = 0.0;
            for(k=0; k<4; k++)
            {
                sum = sum + (function_matrix[i][k] * (input_matrix[k][j] * 1.0));
            }
            output_matrix[i][j] = roundingValue(sum);
        }
    }
}

void scaling()
{
    cout<<"Enter Scaling input : "<<endl;
    cin>>Sx>>Sy>>Sz;

    create_input_Matrix();
    create_scaling_Matrix();
    calculation();
    new_position();
}

void rotation()
{
    cout<<"Enter Rotation input : "<<endl;
    cin>>theta;

    create_input_Matrix();
    create_rotation_Matrix();
    calculation();
    new_position();
}

void traslation()
{
    cout<<"Enter The value of tx, ty and tz : "<<endl;
    cin>>tx>>ty>>tz;

    create_input_Matrix();
    create_translation_Matrix();
    calculation();
    new_position();
}

void developerOption()
{
    cout<<"\n\nSupervised By : Mahadi Hasan Nahid\n";
    cout<<"Developed By : Aziz Ahmed Chowdhury & Ahmed Dider Rahat\n";
}

int main()
{
    int choice;

    cout<<"Enter Your Choice : "<<endl;
    cout<<"\t1 For 3-D Traslation"<<endl;
    cout<<"\t2 For 3-D Rotation"<<endl;
    cout<<"\t3 For 3-D Scaling"<<endl;

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

    developerOption();

    return 0;
}

/*
1
20 20
100 20
60 50
100 100

2
100 20 0
200 20 0
150 50 0
45

3
100 20 10
200 20 20
150 50 30
2 2 2



*/
