/*
dp[i][j]=i개의 발전소가 j조합으로 켜져 있을 때, 최소 비용
find dp[i][j] where i is at least P. 
int bef=j&(~(1<<k)), 
dp[i][j]=dp[i-1][bef]+cost[][k]

time complexity: O(2^N * N * N)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, P, dp[20][(1<<16)]={}, cost[20][20]={}, add_cost[(1<<16)][20], bc[(1<<16)]={};

int bitCount(int A) {
  if(A==0) return 0;
  return A%2+bitCount(A/2);
}

int solve(int i, int j) {
    if (i==0) return 1e9;
    if (dp[i][j]!=1e9) return dp[i][j];
    
    for (int k=0; k<N; k++) {
        if (j&(1<<k)) {
            int bef=j&(~(1<<k));
            dp[i][j]=min(dp[i][j], solve(i-1, bef)+add_cost[bef][k]);
        }
    }
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> cost[i][j];
    int first=0, cnt=0;
    for (int i=0; i<N; i++) {
        char c; cin >> c;
        if (c=='Y') {
            first|=(1<<i);
            cnt++;
        }
    }
    cin >> P;

    fill(&dp[0][0], &dp[N+1][(1<<N)], 1e9);
    dp[cnt][first]=0;

    fill(&add_cost[0][0], &add_cost[(1<<N)][N+2], 1e9);
    for (int i=0; i<(1<<N); i++) {
        for (int j=0; j<N; j++) {
            if (i&(1<<j)) continue; 
            for (int k=0; k<N; k++) {
                if (i&(1<<k)) add_cost[i][j]=min(add_cost[i][j], cost[k][j]);
            }
        }
    }
    for (int i=0; i<(1<<N); i++) bc[i]=bitCount(i);

    int ans=1e9;
    for (int i=P; i<=N; i++) {
        for (int j=0; j<(1<<N); j++) {
            if (bc[j]==i) ans=min(ans, solve(i, j));
        }
    }
    if (ans==1e9) cout << -1;
    else cout << ans;
}