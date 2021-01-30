#include <iostream>
using namespace std;

int arr[1025][1025]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            int num;
            cin >> num;
            arr[i][j] = arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]+num;
        }
    }
    for (int i=0; i<M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1] << "\n";
    }
}


/*
4 2
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7

1 3 6 10
3 8 15 24
*/
