#include <iostream>
#include <algorithm>
using namespace std;

int dp[2005][2005]={}, a[2005];

int solve (int i, int j) {
    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=(solve(i+1, j-1) && a[i]==a[j]);
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    fill(&dp[0][0], &dp[N+1][N+1], -1);
    for (int i=1; i<=N; i++) {
        dp[i][i]=1;
        if (i>1 && a[i]==a[i-1]) dp[i-1][i]=1;
        else if (i>1 && a[i]!=a[i-1]) dp[i-1][i]=0;
    }

    int Q; cin >> Q;
    for (int i=1; i<=Q; i++) {
        int s, e; cin >> s >> e;
        cout << solve(s, e) << "\n";
    }
}
