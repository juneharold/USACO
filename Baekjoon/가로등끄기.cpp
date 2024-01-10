#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll dp[1005][1005][2]={}, w[1005]={}, sum=0, pfs[1005]={};

ll DP(ll i, ll j, ll k) {
    if (i>j) return 1e18;
    if (dp[i][j][k]!=-1) return dp[i][j][k];
    dp[i][j][k]=1e18;
    if (k==0) {
        dp[i][j][0]=min(dp[i][j][0], DP(i+1, j, 0)+sum-(pfs[j]-pfs[i]));
        dp[i][j][0]=min(dp[i][j][0], DP(i, j-1, 1)+sum-(pfs[j-1]-pfs[i-1])+(sum-(pfs[j]-pfs[i-1]))*(j-i));
    }
    else {
        dp[i][j][1]=min(dp[i][j][1], DP(i, j-1, 1)+sum-(pfs[j-1]-pfs[i-1]));
        dp[i][j][1]=min(dp[i][j][1], DP(i+1, j, 0)+sum-(pfs[j]-pfs[i])+(sum-(pfs[j]-pfs[i-1]))*(j-i));
    }
    return dp[i][j][k];
}

int main()
{
    ll N, M; cin >> N >> M;
    ll start=0;
    for (ll i=1; i<=N; i++) {
        ll D, W; cin >> D >> W;
        D++;
        w[D]+=W;
        sum+=W;
        if (i==M) start=D;
    }
    for (ll i=1; i<=1001; i++) pfs[i]=pfs[i-1]+w[i];

    fill(&dp[0][0][0], &dp[1001][1002][1], -1);
    dp[start][start][0]=0;
    dp[start][start][1]=0;

    cout << min(DP(1, 1001, 0), DP(1, 1001, 1));
}