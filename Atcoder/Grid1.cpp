#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

char grid[1005][1005]={};
ll dp[1005][1005]={};

ll solve(int i, int j) {
    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=0;
    if (i-1>0 && grid[i-1][j]=='.') {
        dp[i][j]+=solve(i-1, j);
    }
    if (j-1>0 && grid[i][j-1]=='.') {
        dp[i][j]+=solve(i, j-1);
    }
    dp[i][j]%=MOD;
    return dp[i][j];
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cin >> grid[i][j];
    }
    fill(&dp[0][0], &dp[n][m+1], -1);
    dp[1][1]=1;
    cout << solve(n, m);

}