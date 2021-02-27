//lonesome partners

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int x_coor[500]={}, y_coor[500]={};
    // input of x and y
    for (int i=0; i<N; i++)
    {
        cin >> x_coor[i] >> y_coor[i];
    }
    // finding out the distance between the cows. use nested loop
    int max_a=0, max_b=0; // these are the indices of the two partners
    int max_distance=0;
    for (int a=0; a<N; a++)
    {
        for (int b=0; b<N; b++)
        {
            int distance=sqrt((x_coor[a]-x_coor[b])*(x_coor[a]-x_coor[b])+(y_coor[a]-y_coor[b])*(y_coor[a]-y_coor[b]));
            if (distance > max_distance)
            {
                max_distance=distance;
                max_a=a;
                max_b=b;
            }
            
        }
    }
    if (max_a>max_b)
    {
        printf("%d %d", max_b+1, max_a+1);
    }
    else
    {
        printf("%d %d", max_a+1, max_b+1);
    }
}






