#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_X=1e6+5;
int dp[MAX_X]={}, coins[105]={};
int n, x;

int main()
{
    cin >> n >> x;
    for (int j=1; j<=n; j++) cin >> coins[j];

    fill(&dp[0], &dp[MAX_X], 1e9);
    dp[0]=0;

    for (int i=1; i<=x; i++) {
        for (int j=1; j<=n; j++) {
            if (i-coins[j]>=0) dp[i]=min(dp[i], dp[i-coins[j]]+1);
        }
    }

    if (dp[x]==1e9) cout << -1;
    else cout << dp[x];
}
