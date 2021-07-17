#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1005;
int cost[MAX_N][3]={};
int dp[MAX_N][3]={};
int n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=0; j<3; j++) cin >> cost[i][j];

    dp[1][0]=cost[1][0]; dp[1][1]=cost[1][1]; dp[1][2]=cost[1][2];

    for (int i=2; i<=n; i++) {
        dp[i][0]=min(dp[i-1][1], dp[i-1][2])+cost[i][0];
        dp[i][1]=min(dp[i-1][0], dp[i-1][2])+cost[i][1];
        dp[i][2]=min(dp[i-1][0], dp[i-1][1])+cost[i][2];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}
