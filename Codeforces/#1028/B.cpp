#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=9e18;

ll fastpow (ll x, ll y) {
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

void solve() {
    ll n; cin >> n;
    vector<ll> p(n), q(n);
    for (ll i=0; i<n; i++) cin >> p[i];
    for (ll i=0; i<n; i++) cin >> q[i];

    vector<ll> mx_idx_p(n+1, 0), mx_idx_q(n+1, 0);
    for (ll i=1; i<n; i++) {
        if (p[i]>p[mx_idx_p[i-1]]) mx_idx_p[i]=i;
        else mx_idx_p[i]=mx_idx_p[i-1];
        if (q[i]>q[mx_idx_q[i-1]]) mx_idx_q[i]=i;
        else mx_idx_q[i]=mx_idx_q[i-1];
    }

    vector<ll> r(n);
    for (ll i=0; i<n; i++) {
        ll p_val1=p[mx_idx_p[i]], q_val1=q[i-mx_idx_p[i]];
        ll p_val2=p[i-mx_idx_q[i]], q_val2=q[mx_idx_q[i]];

        if (p_val1>q_val2) r[i]=fastpow(2, p_val1)+fastpow(2, q_val1);
        else if (q_val2>p_val1) r[i]=fastpow(2, p_val2)+fastpow(2, q_val2);
        else {
            if (q_val1>p_val2) r[i]=fastpow(2, p_val1)+fastpow(2, q_val1);
            else r[i]=fastpow(2, p_val2)+fastpow(2, q_val2);
        }
    }
    for (ll i=0; i<n; i++) cout << (r[i]%MOD) << ' ';
    cout << "\n";
}
/*

3
0 2 1
1 2 0

1
0
0
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
