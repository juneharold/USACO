#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505]={};
int pfs100[505][505]={};
int pfs0[505][505]={};

int main()
{
    int N; cin >> N;
    int count100=0;
    for (int i=1; i<N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j]==100) count100++;
            pfs100[i][j]=count100+pfs100[i-1][j];
        }
        count100=0;
    }
    int counter=0;
    for (int Y=1; Y<N; Y++)
    {
        for (int y=0; y<N-1; y++)
        {
            for (int X=1; X<N; X++)
            {
                for (int x=0; x<N-1; x++)
                {
                    int min=200;
                    for (int yy=y; yy<=Y; yy++)
                    {
                        for (int xx=x; xx<=X; xx++)
                        {
                            if (arr[yy][xx]<min) min=arr[yy][xx];
                        }
                    }
                    if (min==100) counter++;
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
*/