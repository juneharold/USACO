// 색종이 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
int main()
{
    int N;
    cin >> N;
    int paper_pos[200] = {};
    for (int paper=0; paper<2*N; paper++)
    {
        cin >> paper_pos[paper];
    }
    // calculating area
    int min_x=100, min_y=100;
    int max_x=0, max_y=0;
    for (int i=0; i<N; i++)
    {
        int x=paper_pos[2*i], y=paper_pos[2*i+1];
        printf("\n%d %d", x, y);
        if (x < min_x)
        {
            min_x = x;
        }
        if (y < min_y)
        {
            min_y = y;
        }
        if (x+10>max_x)
        {
            max_x=x+10;
        }
        if (y+10>max_y)
        {
            max_y=y+10;
        }
    }
    printf("\n%d %d %d %d\n", min_x, max_x, min_y, max_y);
    // N*10-(max_x-min_x)
    // N*10-(max_y-min_y)
    // larger_area = (max_x-min_x) * (max_y-min_y)
    // Area = larger_area - sub_area
    int sub_area = (N*10-(max_y-min_y)) * (N*10-(max_x-min_x));
    int larger_area = (max_x-min_x) * (max_y-min_y);
    int Area = larger_area - sub_area;
    cout << Area;
}
*/

int main()
{
    int N, plane[101][101]={};
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int i=y; i<y+10; i++)
        {
            for (int j=x; j<x+10; j++)
            {
                plane[j][i] = 1;
            }
        }
    }
    // counting
    int counter=0;
    for (int i=0; i<101; i++)
    {
        for (int j=0; j<101; j++)
        {
            if (plane[j][i] == 1)
            {
                counter+=1;
            }
        }
    }
    cout << counter << endl;
}
