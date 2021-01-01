#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int x1, y1, x2, y2; // first billboard
    int x3, y3, x4, y4; // second billboard
    int x, y, X, Y; // truck
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x >> y >> X >> Y;
    // check if x1 < x3
    if (x1>x3)
    {
        int t1=x1, t2=y1, t3=x2, t4=y2;
        x1=x3;
        y1=y3;
        x2=x4;
        y2=y4;
        x3=t1;
        y3=t2;
        x4=t3;
        y4=t4;
    }
    // sum area of billboards
    int total_area = (x2-x1)*(y2-y1) + (x4-x3)*(y4-y3);
    int final_area = 0;
    // locating the position of lower left of truck
    if (x<x1)
    {
        if (X<x1) // doesn't cover
        {
            final_area = total_area - 0;
        }
        else if (X>=x1 and X<x2) // covers part of first billboard
        {
            if (Y>y1 and Y<=y2) // covers part of first billboard
            {
                final_area = total_area - (X-x1)*(Y-y1);
            }
            else if (Y>y1 and Y>y2)
            {
                final_area = total_area - (X-x1)*(y2-y1);
            }
        }
        else if (X>=x2 and X<x3) // covers part of first billboard
        {
            if (Y>y1 and Y<=y2) // covers part of first billboard
            {
                final_area = total_area - (x2-x1)*(Y-y1);
            }
            else if (Y>y1 and Y>y2)
            {
                final_area = total_area - (x2-x1)*(y2-y1);
            }
        }
        else if (X>=x3 and X<x4) // covers first and second 
        {
            if (Y>y1 and Y<=y2) 
            {
                
            }
            else if (Y>y1 and Y>y2)
            {
                
            }
        }
        else if (X>=x4)
        {

        }
    }
    else if (x>=x1 and x<x2)
    {

    }
    else if (x>=x2 and x<x3)
    {

    }
    else if (x>=x3 and x<x4)
    {

    }
    else
    {
        
    }
}