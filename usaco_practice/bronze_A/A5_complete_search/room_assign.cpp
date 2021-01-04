// 방 배정하기 

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int A, B, C, N;
    cin >> A >> B >> C >> N;
    int indicator=0; // if this is 1, it means that possible
    // triple nested loop
    for (int i=0; i<=300; i++)
    {
        for (int j=0; j<=300; j++)
        {
            for (int k=0; k<=300; k++)
            {
                if (A*i + B*j + C*k == N)
                {
                    indicator=1;
                }
            }
        }
    }
    // checking the indicator
    if (indicator==1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}






