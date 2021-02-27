#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int arr[1005][1005]={};
    int arr2[1005][1005]={};
    int N, K; cin >> N >> K;
    for (int i=0; i<N; i++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int j=y1; j<y2; j++)
        {
            arr[j][x1]+=1;
            arr[j][x2]+=(-1);
        }
    }
    int sum=0;
    for (int i=0; i<1001; i++)
    {
        for (int j=0; j<1001; j++)
        {
            arr2[i][j]=sum;
            sum+=arr[i][j];
        }
    }
    int counter=0;
    for (int i=0; i<1001; i++)
    {
        for (int j=0; j<1001; j++)
        {
            if (arr2[i][j]==K) counter++;
        }
    }
    cout << counter;
}



/*
3 2
1 1 5 5
4 4 7 6
3 3 8 7

2 2
1 1 5 5
1 1 5 5

*/


