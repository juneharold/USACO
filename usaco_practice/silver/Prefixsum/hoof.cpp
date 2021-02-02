#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char FJ[100005]={};
char A[3][100005]={};

int main()
{
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        char a;
        cin >> a;
        if (a=='H') A[0][i]++;
        if (a=='P') A[1][i]++;
        if (a=='S') A[2][i]++;
    }
    for (int i=0; i<3; i++)
    {
        for (int j=1; j<=N; j++)
        {
            A[i][j]+=A[i][j-1];
        }
    }
    int ans=0;
    for (int i=1; i<=N; i++)
    {
        for (int j=0; j<3; j++) for (int k=0; k<3; k++)
        {
            ans = max(ans, A[j][i]+(A[k][N]-A[k][j]));
        }
    }
    cout << ans-1;
}




