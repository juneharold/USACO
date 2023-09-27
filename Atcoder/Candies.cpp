/*
dp[i][j]=ith child, j candies given out
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll a[105]={}, dp[105][100005]={};

int main()
{
    ll N, K; cin >> N >> K;
    for (ll i=1; i<=N; i++) cin >> a[i];
    dp[0][0]=1;
    for (ll i=0; i<N; i++) {
        for (ll j=0; j<=K; j++) {
            int until=min(K, j+a[i+1]);
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            dp[i+1][until+1]=(dp[i+1][until+1]-dp[i][j]+MOD)%MOD;
        }
        for (ll j=0; j<=K; j++) {
            if (j>0) {
                dp[i+1][j]=dp[i+1][j-1]+dp[i+1][j];
                dp[i+1][j]%=MOD;
            }
        }
    }
    cout << dp[N][K];
}
