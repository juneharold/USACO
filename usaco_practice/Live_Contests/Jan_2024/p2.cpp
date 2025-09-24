#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll fastpow (ll x, ll y) {
    if (x==0) return 0;
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

ll dp[105][10005]={}, pfs[105][10005]={};

ll fact[10005]={}, invfact[10005]={};

ll nCr(ll n, ll r) {
    if (r<0) return 0;
    ll top=1, bottom=1;
    for (int i=1; i<=r; i++) {
        top*=n;
        bottom*=i;
        n--;
        top%=MOD;
        bottom%=MOD;
    }
    return top*fastpow(bottom, MOD-2)%MOD;
}

void solve() {
    int N, Q, C; cin >> N >> Q >> C;
    vector<pii> v(Q+1, {0, 0});
    for (int i=1; i<=Q; i++) cin >> v[i].fs >> v[i].sc;
    sort(&v[1], &v[Q+1]);

    for (int j=1; j<=C; j++) {
        dp[1][j]=dp[1][j-1];
        ll temp=(fastpow(j-1, v[1].fs)-fastpow(j-2, v[1].fs)+MOD)%MOD*fastpow(j-1, v[1].sc-v[1].fs-1)%MOD;
        dp[1][j]+=temp; //nCr(v[1].sc-1+j-2, j-2);
        dp[1][j]%=MOD;
    }
    /*for (int j=1; j<=C; j++) cout << dp[1][j] << ' ';
    cout << endl;*/

    for (int i=2; i<=Q; i++) {
        ll sum=0;
        for (int j=1; j<=C; j++) {
            ll temp=fastpow(j-1, v[i].fs-v[i-1].sc);
            if (v[i].sc-v[i].fs-1>0) temp=(temp-fastpow(j-2, v[i].fs-v[i-1].sc)+MOD)%MOD;
            temp=temp*fastpow(j-1, v[i].sc-v[i].fs-1)%MOD;
            dp[i][j]=dp[i][j-1]+dp[i-1][j-1]*fastpow(j-1, v[i].sc-v[i-1].sc-1)%MOD+pfs[i-1][j-2]*temp%MOD;
            dp[i][j]%=MOD;
            //sum=(sum+pfs[i-1][j-2]*temp)%MOD;
            pfs[i][j]=(pfs[i][j-1]+dp[i][j])%MOD;
            //cout << dp[i][j] << ' ';
        }
        //cout << endl;
    }
    ll ans=0;
    for (int i=1; i<=C; i++) ans=(ans+dp[Q][i]*fastpow(C, N-v[Q].sc))%MOD;
    cout << ans;
}
/*
6
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
