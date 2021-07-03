#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_T=1e7+5;
int dp[MAX_T][2]={};

int main()
{
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b; cin >> t >> a >> b;
    dp[0][0]=1;

    int ans=0;
    for (int i=1; i<=t*2+1; i++) {
        if (i-a>=0) dp[i][0]=max(dp[i][0], dp[i-a][0]);
        if (i-b>=0) dp[i][0]=max(dp[i][0], dp[i-b][0]);

        if (dp[i][0]!=0 && i>ans && i<=t) ans=i;
    }

    for (int i=1; i<=t; i++) {
        if (i-a>=0) dp[i][1]=max(dp[i][1], dp[i-a][1]);
        if (i-b>=0) dp[i][1]=max(dp[i][1], dp[i-b][1]);
        if (i*2<=t) dp[i][1]=max(dp[i][1], dp[i*2][0]);
        if (i*2+1<=t) dp[i][1]=max(dp[i][1], dp[i*2+1][0]);

        if (dp[i][1]!=0 && i>ans && i<=t) ans=i;
    }

    cout << ans;
}
