/*
dp[i][j]=minimum cost when combining slimes from i to j
dp[i][j]=min(dp[i][k]+dp[k+1][j]+cost) (where k is between i and j inclusive)
cost = pfs[j] - pfs[i-1]
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, a[405]={}, dp[405][405]={}, pfs[405]={};

ll DP(int i, int j) {
    if (i==j) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=1e18;
    for (int k=i; k<j; k++) {
        dp[i][j]=min(dp[i][j], DP(i, k)+DP(k+1, j)+pfs[j]-pfs[i-1]);
    }
    return dp[i][j];
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        pfs[i]=pfs[i-1]+a[i];
    }
    fill(&dp[0][0], &dp[N+1][N+1], -1);
    cout << DP(1, N);
}
