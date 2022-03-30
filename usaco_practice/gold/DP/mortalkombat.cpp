#include <iostream>
#include <algorithm>
using namespace std;

int a[200005]={}, dp[200005][3]={};

int main()
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];

        fill(&dp[0][0], &dp[n+1][2], 1e9);
        dp[1][1]=a[1]; dp[2][1]=a[1]+a[2];
        for (int i=2; i<=n; i++) {
            dp[i][0]=min(dp[i][0], min(dp[i-1][1], dp[i-2][1]));
            dp[i][1]=min(dp[i][1], min(dp[i-1][0]+a[i], dp[i-2][0]+a[i-1]+a[i]));
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }

        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}

/*
1
8
1 0 1 1 0 1 1 1
*/
