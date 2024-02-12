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
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll val[1005][1005]={};

ll nC2(ll x) {
    return x*(x-1)/2;
}

void solve() {
    ll n, b, x; cin >> n >> b >> x;
    vector<ll> c(n+1);
    ll maxc=0;
    for (ll i=1; i<=n; i++) {
        cin >> c[i];
        maxc=max(maxc, c[i]);
    }
    sort(&c[1], &c[n+1]);

    vector<ll> sumval(min(maxc+1, 1005LL), 0);
    ll from=-1;
    for (ll i=1; i<=n; i++) {
        if (c[i]<=1000) {
            for (ll k=1; k<=c[i]; k++) sumval[k]+=val[c[i]][k];
        }
        if (c[i]>1000 && from==-1) from=i;
    }

    ll ans=0, idx=1, cur=0;
    for (ll k=1; k<=maxc; k++) {
        while (idx<=n && c[idx]<=k) {
            cur+=c[idx]*(c[idx]-1)/2;
            idx++;
        }
        ll temp=0;
        if (from!=-1) {
            for (ll i=max(idx, from); i<=n; i++) {
                ll a=c[i]/k+1, b=c[i]/k, cnta=c[i]%k, cntb=k-c[i]%k;
                temp+=nC2(c[i])-cnta*nC2(a)-cntb*nC2(b);
            }
        }
        ll max_now=cur+temp;
        if (k<sumval.size()) max_now+=sumval[k];
        ans=max(ans, max_now*b-(k-1)*x);
    }
    cout << ans << "\n";
}

int main()
{
    for (ll i=2; i<=1000; i++) {
        for (ll j=1; j<i; j++) {
            ll a=i/j+1, b=i/j, cnta=i%j, cntb=j-i%j;
            val[i][j]=nC2(i)-cnta*nC2(a)-cntb*nC2(b);
        }
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
