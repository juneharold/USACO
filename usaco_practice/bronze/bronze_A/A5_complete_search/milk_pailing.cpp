// milk pailing

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int X, Y, M;
    cin >> X >> Y >> M;
    // use double nested loop
    int max=0;
    for (int i=0; i<=1000; i++)
    {
        for (int j=0; j<=1000; j++)
        {
            if (X*i+Y*j<=M and X*i+Y*j>max)
            {
                max=X*i+Y*j;
            }
        }
    }
    cout << max;
}






