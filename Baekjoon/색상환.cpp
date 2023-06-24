#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+3;

ll dp[1001][1001][2]={};

ll solve(ll start, ll n, ll k) {
    fill(&dp[0][0][0], &dp[n][n+1][2], 0);
    dp[1][start][start]=1;
    for (ll i=2; i<=n; i++) {
        for (ll j=0; j<=min(i, k); j++) {
            if (i==n) {
                if (start) {
                    dp[i][j][0]+=dp[i-1][j][1]+dp[i-1][j][0];
                    dp[i][j][0]%=MOD;
                }
                else {
                    if (j>0) dp[i][j][1]+=dp[i-1][j-1][0];
                    dp[i][j][1]%=MOD;
                    dp[i][j][0]+=dp[i-1][j][1]+dp[i-1][j][0];
                    dp[i][j][0]%=MOD;
                }
            }
            else {
                if (j>0) dp[i][j][1]+=dp[i-1][j-1][0];
                dp[i][j][1]%=MOD;
                dp[i][j][0]+=dp[i-1][j][1]+dp[i-1][j][0];
                dp[i][j][0]%=MOD;
            }
        }
    }

    return (dp[n][k][0]+dp[n][k][1])%MOD;
}

int main()
{
    ll n, k; cin >> n >> k;
    cout << (solve(0, n, k)+solve(1, n, k))%MOD;
}