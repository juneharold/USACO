#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int s[305]={};
    for (int i=1; i<=n; i++) cin >> s[i];

    int dp[305][3]={};
    dp[1][1]=s[1];
    for (int i=2; i<=n; i++) {
        dp[i][1]=max(dp[i-2][1], dp[i-2][2])+s[i];
        dp[i][2]=dp[i-1][1]+s[i];
    }
    cout << max(dp[n][1], dp[n][2]);
}
