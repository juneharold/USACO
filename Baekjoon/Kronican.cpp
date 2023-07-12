#include <iostream>
#include <algorithm>
using namespace std;

int N, K, C[20][20]={}, dp[1<<20]={};

int cntbits(int x) {
    int ret=0;
    while (x) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}

int solve(int cur) {
    if (dp[cur]!=1e9) return dp[cur];
    for (int i=0; i<N; i++) {
        if ((1<<i)&cur) {
            int bef=cur-(1<<i), mn=1e9;
            for (int j=0; j<N; j++) {
                if (!((1<<j)&cur)) {
                    mn=min(mn, C[i][j]);
                }
            }
            dp[cur]=min(dp[cur], solve(bef)+mn);
        }
    }
    return dp[cur];
}

int main()
{
    cin >> N >> K;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) cin >> C[i][j];
    fill(&dp[0], &dp[1<<N], 1e9);
    dp[0]=0;
    int ans=1e9;
    for (int i=0; i<(1<<N); i++) {
        if (cntbits(i)==N-K) {
            ans=min(ans, solve(i));
        }
    }
    cout << ans;
}
