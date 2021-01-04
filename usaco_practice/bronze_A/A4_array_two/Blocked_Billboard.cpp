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
    int plane[2001][2001]={}; // ranges from -1000 to 1000
    // first billboard
    for (int i=y1; i<y2; i++)
    {
        for (int j=x1; j<x2; j++)
        {
            plane[j+1000][i+1000]=1;
        }
    }
    // second billboard
    for (int k=y3; k<y4; k++)
    {
        for (int l=x3; l<x4; l++)
        {
            plane[l+1000][k+1000]=1;
        }
    }
    // truck
    for (int p=y; p<Y; p++)
    {
        for (int q=x; q<X; q++)
        {
            plane[q+1000][p+1000]=0;
        }
    }
    // counting the places that are 1.
    int counter=0;
    for (int a=0; a<2001; a++)
    {
        for (int b=0; b<2001; b++)
        {
            if (plane[a][b]==1)
            {
                counter+=1;
            }
        }
    }
    cout << counter << endl;
}
