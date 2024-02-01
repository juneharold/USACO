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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll segtree[4*nmax]={};
ll query(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return 1e18;
    if (qa<=a && b<=qb) return segtree[n];
    ll mid=(a+b)/2;
    return min(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}
void update(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=min(segtree[2*n], segtree[2*n+1]);
}

ll pfs[nmax]={};

ll find_index(ll x, ll idx, ll target) {
    ll lo=0, hi=idx;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (x-pfs[mid]<=target) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1, 0);
    for (ll i=1; i<=n; i++) {
        cin >> a[i];
        pfs[i]=pfs[i-1]+a[i];
    }

    ll lo=0, hi=1e18; 
    while (lo<hi) {
        ll mid=(lo+hi)/2;

        vector<ll> dp(n+1, 0);
        //for (ll i=1; i<=n; i++) update(1, 1, n, i, i, 1e9);
        for (ll i=1; i<=n; i++) {
            ll j=find_index(pfs[i-1], i-1, mid);
            //if (mid==7) cout << "j: " << j << ' ' << i-1 << ' ' << query(1, 1, n, j, i-1) << endl;
            if (j==0) dp[i]=a[i];
            else dp[i]=query(1, 1, n, j, i-1)+a[i];
            update(1, 1, n, i, i, dp[i]);
        }

        /*if (mid==7) {
            for (ll i=1; i<=n; i++) cout << dp[i] << ' ';
            cout << endl;
        }*/

        bool possible=false;
        for (ll i=1; i<=n; i++) {
            if (dp[i]<=mid && pfs[n]-pfs[i]<=mid) {
                possible=true;
                //if (mid==7) cout << i << endl;
            }
        }
        if (possible) hi=mid;
        else lo=mid+1;
        for (ll i=1; i<=n; i++) update(1, 1, n, i, i, 0);
    }
    cout << lo << "\n";
    fill(&pfs[0], &pfs[n+1], 0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
