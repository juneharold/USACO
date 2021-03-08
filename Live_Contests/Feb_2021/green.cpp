#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505]={};
int pfs100[505][505]={};
int pfs0[505][505]={};


int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++)
    {
        int count100=0, count0=0;
        for (int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j]==100) count100++;
            if (arr[i][j]<100) count0++;
            pfs100[i][j]=count100+pfs100[i-1][j];
            pfs0[i][j]=count0+pfs0[i-1][j];
        }
    }
    int counter=0;
    for (int Y=1; Y<N+1; Y++)
    {
        for (int y=1; y<=Y; y++)
        {
            for (int X=1; X<N+1; X++)
            {
                for (int x=1; x<=X; x++)
                {
                    // 100 exists
                    // less than 100 does not exist
                    int num100=pfs100[Y][X]-pfs100[y-1][X]-pfs100[Y][x-1]+pfs100[y-1][x-1];
                    int num0=pfs0[Y][X]-pfs0[y-1][X]-pfs0[Y][x-1]+pfs0[y-1][x-1];
                    if ((num100>0) and (num0==0)) 
                    {
                      counter++;
                    }
                }
            }
        }
    }
    cout << counter;
}

/*
3
57 120 87
200 100 150
2 141 135

3
57 120 100
200 2 100
2 141 2
*/
