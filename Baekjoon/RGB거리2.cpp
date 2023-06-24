#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=1005;

int cost[MAX_N][3]={}, dp[MAX_N][3][3]={};

int main()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) for (int j=0; j<3; j++) cin >> cost[i][j];

    fill(&dp[0][0][0], &dp[n][2][3], 1e9);
    dp[1][0][0]=cost[1][0]; dp[1][1][1]=cost[1][1]; dp[1][2][2]=cost[1][2];
    int ans=1e9;
    for (int i=2; i<=n; i++) {
        for (int k=0; k<3; k++) {
            for (int j=0; j<3; j++) {
                if (i==n && j!=k) {
                    dp[i][j][k]=min(dp[i-1][(j+1)%3][k], dp[i-1][(j+2)%3][k])+cost[i][j];
                    ans=min(ans, dp[i][j][k]);
                }
                else dp[i][j][k]=min(dp[i-1][(j+1)%3][k], dp[i-1][(j+2)%3][k])+cost[i][j];
            }
        }
    }
    cout << ans;
}