#include <iostream>

using namespace std;

struct st{
    int x, y;
}vertex[100];

struct str{
    int source, destination;
}edge[100], modify_edge_list[100];


int n, e;

void edge_remove()
{
    int temp_source, temp_destination, sx, sy, dx, dy;
    int list=0;
    for(int i=0; i<e; i++)
    {
        temp_source = edge[i].source;
        temp_destination = edge[i].destination;
        sx = vertex[temp_source].x;
        sy = vertex[temp_source].y;
        dx = vertex[temp_destination].x;
        dy = vertex[temp_destination].y;
        if(sy == dy)
        {
            //nothing
        }
        else
        {
            modify_edge_list[list].source = temp_source;
            modify_edge_list[list].destination = temp_destination;
        }
    }
}

void getInput()
{
    cout<<"Enter Number of Vertex : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>vertex[i].x>>vertex[i].y;
    }

    cout<<"Enter Number of Edge : ";
    cin>>e;
    for(int i=0; i<e; i++)
    {
        cin>>edge[i].source>>edge[i].destination;
    }
}

int main()
{
    getInput();

    edge_remove();

    cout << "Hello world!" << endl;
    return 0;
}
