#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

ll c[1000005]={}, v[1000005]={}, dp[1000005][26]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    for (ll i=1; i<=n; i++) {
        char temp; cin >> temp >> v[i];
        c[i]=temp-'a';
    }
    for (ll i=1; i<=n; i++) {
        for (ll j=0; j<26; j++) {
            if (j==c[i]) continue;
            dp[i][j]=dp[i-1][j];
            dp[i][j]%=MOD;
            dp[i][c[i]]+=dp[i-1][j]*v[i];
            dp[i][c[i]]%=MOD;
        }
        dp[i][c[i]]+=dp[i-1][c[i]]+v[i];
        dp[i][c[i]]%=MOD;
    }

    ll ans=0;
    for (ll j=0; j<26; j++) ans+=dp[n][j];
    cout << ans%MOD;
}