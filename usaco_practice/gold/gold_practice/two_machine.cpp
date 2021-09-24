#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=255;
int n, dp[MAX][MAX*MAX]={}, A[MAX]={}, B[MAX]={};
pair<int, int> remain[MAX][2];

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> A[i] >> B[i];
    }

    fill(&dp[0][0], &dp[MAX-1][MAX*MAX], 1e9);

    dp[0][0]=0;

    for (int i=1; i<=n; i++) {
        for (int a=0; a<=250*250; a++) {
            dp[i][a]=min(dp[i][a], dp[i-1][a]+B[i]);
            dp[i][a+A[i]]=min(dp[i][a+A[i]], dp[i-1][a]);
        }
    }

    int ans=1e9;
    for (int a=0; a<=250*250; a++) {
        ans=min(ans, max(dp[n][a], a));
    }
    cout << ans;
}
