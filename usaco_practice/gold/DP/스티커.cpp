#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int c=0; c<T; c++) {
        int n; cin >> n;
        int one[MAX_N]={}, two[MAX_N]={};
        for (int i=1; i<=n; i++) cin >> one[i];
        for (int i=1; i<=n; i++) cin >> two[i];
        int dp[MAX_N][3]={};
        
        //basecase
        dp[1][1]=one[1];
        dp[1][2]=two[1];
        dp[2][1]=two[1]+one[2];
        dp[2][2]=one[1]+two[2];

        int ans=max(dp[2][1], dp[2][2]);
        for (int i=3; i<=n; i++) {
            dp[i][1]=max(dp[i-1][2], max(dp[i-2][1], dp[i-2][2]))+one[i];
            dp[i][2]=max(dp[i-1][1], max(dp[i-2][1], dp[i-2][2]))+two[i];
        }
        for (int i=1; i<=n; i++) {
            ans=max(ans, dp[i][1]);
            ans=max(ans, dp[i][2]);
        }
        cout << ans << "\n";
    }
}
