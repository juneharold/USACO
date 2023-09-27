#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, a[3005]={}, dp[3005][3005][2]={};

ll DP(int i, int j, int k) {
    if (i==j+1) return 0;
    if (dp[i][j][k]!=-1) return dp[i][j][k];
    if (k==0) {
        dp[i][j][k]=-1e18;
        dp[i][j][k]=max(dp[i][j][k], DP(i, j-1, 1)+a[j]);
        dp[i][j][k]=max(dp[i][j][k], DP(i+1, j, 1)+a[i]);
    }
    else {
        dp[i][j][k]=1e18;
        dp[i][j][k]=min(dp[i][j][k], DP(i, j-1, 0)-a[j]);
        dp[i][j][k]=min(dp[i][j][k], DP(i+1, j, 0)-a[i]);
    }
    return dp[i][j][k];
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    fill(&dp[0][0][0], &dp[N+1][N+1][2], -1);
    cout << DP(1, N, 0);
}
