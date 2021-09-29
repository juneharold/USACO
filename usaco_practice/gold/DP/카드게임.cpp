#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=2005;
int N, r[MAX_N]={}, l[MAX_N]={}, dp[MAX_N][MAX_N]={};

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> l[i];
    for (int j=1; j<=N; j++) cin >> r[j];

    fill(&dp[0][0], &dp[MAX_N-1][MAX_N], -1);
    dp[1][1]=0;
    int ans=0;

    for (int i=1; i<=N+1; i++) {
        for (int j=1; j<=N+1; j++) {
            if (dp[i-1][j]!=-1) dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if (dp[i-1][j-1]!=-1) dp[i][j]=max(dp[i][j], dp[i-1][j-1]);
            if (r[j-1]<l[i] && dp[i][j-1]!=-1) dp[i][j]=max(dp[i][j], dp[i][j-1]+r[j-1]);

            ans=max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
