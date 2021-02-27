// 백설 공주와 일곱 난쟁이 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int dwarfs[9]={}, sum=0;
    for (int i=0; i<9; i++)
    {
        cin >> dwarfs[i];
        sum += dwarfs[i];
    }
    // double nested loop subtract
    for (int a=0; a<9; a++)
    {
        for (int b=0; b<9; b++)
        {
            if (b!=a and sum-dwarfs[a]-dwarfs[b]==100)
            {
                for (int j=0; j<9; j++)
                {
                    if (j!=a and j!=b)
                    {
                        cout << dwarfs[j] << endl;
                    }
                }
            }
        }
    }
}
