#include <iostream>
#include <algorithm>
using namespace std;

int N, M, dp[105][10005]={}, m[105]={}, c[105]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> m[i];
    for (int i=1; i<=N; i++) cin >> c[i];

    int ans=1e9;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=10000; j++) {
            if (j-c[i]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j-c[i]]+m[i]);
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if (dp[i][j]>=M) ans=min(ans, j);
        }
    }
    cout << ans;
}
