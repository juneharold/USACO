#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll MOD=1e9+7, INF=1e18;

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            if (ret>=INF/x+1) {
                return INF+1;
            }
            ret*=x;
        }
        if (x>=INF/x+1 && y!=1) {
            return INF+1;
        }
        x*=x;
        y/=2;
    }
    return ret;
}

ll apowb[65][65]={};

void solve() {
    ll l, r; cin >> l >> r;
    vector<int> f;
    for (int i=1; i<=60; i++) {
        if (l<=apowb[2][i] && apowb[2][i]<=r) f.push_back(i);
        else if (apowb[2][i]<l && l<=apowb[2][i+1]) f.push_back(i);
    }

    ll ans=0;
    for (int i=0; i<f.size(); i++) {
        ll x1=max(l, apowb[2][f[i]]), x2=min(r, apowb[2][f[i]+1]-1);
        ll prev=x1;
        for (int j=1; j<=60; j++) {
            if (x1<apowb[f[i]][j+1] && apowb[f[i]][j]<=x2) {
                ll temp=min(x2, apowb[f[i]][j+1]-1);
                if (prev>temp) continue;
                ans+=(temp-prev+1)%MOD*j;
                ans%=MOD;
                prev=temp+1;
            }
            if (prev>x2) break;
        } 
    }
    cout << ans << "\n";
}

int main()
{
    // precompute a pow b
    for (int i=1; i<=62; i++) {
        for (int j=1; j<=62; j++) {
            apowb[i][j]=fastpow(i, j);
        }
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
