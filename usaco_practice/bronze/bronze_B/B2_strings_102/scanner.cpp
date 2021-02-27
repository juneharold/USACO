// 스캐너 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int R, C, ZR, ZC;
    cin >> R >> C >> ZR >> ZC;
    string rows[50]={};
    for (int i=0; i<R; i++)
    {
        cin >> rows[i];
    }
    // 
    for (int r=0; r<R*ZR; r++)
    {
        // rows[r/ZR]
        for (int c=0; c<C*ZC; c++)
        {
            cout << rows[r/ZR][c/ZC];
        }
        cout << endl;
    }
}