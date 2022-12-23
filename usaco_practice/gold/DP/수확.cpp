/*
dp[i][j]=maximum profit when i from left and j from right
dp[i][j]=dp[i-1][j]+v[i]*(i+j) or dp[i][j-1]+v[N-j-1]*(i+j)
basecase: dp[0][0]=0

answer is dp[i][j] where i+j=N
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, v[2005], dp[2005][2005]={};

int solve(int i, int j) {
    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=0;
    if (i>0) dp[i][j]=max(dp[i][j], solve(i-1, j)+v[i]*(i+j));
    if (j>0) dp[i][j]=max(dp[i][j], solve(i, j-1)+v[N-j+1]*(i+j));
    return dp[i][j];
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> v[i];
    fill(&dp[0][0], &dp[N+1][N+1], -1);
    dp[0][0]=0;

    int ans=0;
    for (int i=0; i<=N; i++) ans=max(ans, solve(i, N-i));
    cout << ans;
}