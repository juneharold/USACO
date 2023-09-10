/*
use dijkstra or floyd-warshall to find cheapest way to make a[i] -> a[j]
dp[i][j]=if s[i] is j, minimum cost to make satisfying streak. 
dp[i][j]=dp[i-x][j']+cost to make s[(i-x+1)~i]==j where x>=k
this is O(n^2*m) solution, 
mindp[i]=min(dp[i][j']) where 1<=j<=M

dp[i][j]=min(mindp[i-k]+cst, dp[i][j-1]+cost[s[i]][j])
cst can be calculated using prefixsum 
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char s[100005]={};
int N, M, K, dp[100005][30]={}, mindp[100005]={}, cost[30][30]={}, pfs[100005][30]={};

int main()
{
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) {
        cin >> s[i];
        for (int j=1; j<=M; j++) {
            if (s[i]-'a'+1==j) pfs[i][j]=pfs[i-1][j]+1;
            else pfs[i][j]=pfs[i-1][j];
        }
    }
    for (int i=1; i<=M; i++) for (int j=1; j<=M; j++) cin >> cost[i][j];
    for (int k=1; k<=M; k++) {
        for (int i=1; i<=M; i++) {
            for (int j=1; j<=M; j++) {
                cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
    fill(&dp[1][0], &dp[N+1][M+1], 1e9);
    fill(&mindp[0], &mindp[N+1], 1e9);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+cost[s[i]-'a'+1][j]);
            int cst=0;
            for (int k=1; k<=M; k++) {
                if (i-K>=0) cst+=(pfs[i][k]-pfs[i-K][k])*cost[k][j];
            }
            if (i-K>=0) dp[i][j]=min(dp[i][j], mindp[i-K]+cst);
            if (i>=K) mindp[i]=min(mindp[i], dp[i][j]);
        }
    }
    int ans=1e9;
    for (int i=1; i<=M; i++) ans=min(ans, dp[N][i]);
    cout << ans;
}
