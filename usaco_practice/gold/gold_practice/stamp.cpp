#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll MAX=1e6+5, mod=1e9+7;
ll N, M, K, dp[MAX]={}, pfs[MAX]={}, total=1;

int main()
{
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    cin >> N >> M >> K;
    dp[0]=1;
    for (ll i=1; i<=N; i++) {
        if (i<K) {
            dp[i]=M*dp[i-1];
            dp[i]%=mod;
        }
        else {
            dp[i]=(M-1)*(pfs[i-1]-pfs[i-K]);
            dp[i]%=mod;
        }
        pfs[i]=pfs[i-1]+dp[i]; pfs[i]%=mod;
        total*=M; total%=mod;
    }
    cout << (total-dp[N])%mod;
}
