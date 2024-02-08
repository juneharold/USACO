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

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> A(n+1);
    for (ll i=1; i<=n; i++) cin >> A[i];

    /*vector<ll> cost(20, 0);
    for (ll i=1; i<=n; i++) {
        for (ll j=0; j<20; j++) {
            if ((a[i]&(1<<j))==0) cost[j]+=(1<<j);
        }
    }*/
    /*for (ll j=0; j<20; j++) cout << cost[j] << ' ';
    cout << endl;*/

    vector<ll> a(n+1);
    while (q--) {
        ll k; cin >> k;
        ll ans=0;
        for (ll i=1; i<=n; i++) a[i]=A[i];
        for (ll j=59; j>=0; j--) {
            ll cost=0;
            bool of=false;
            vector<ll> idx;
            for (ll i=1; i<=n; i++) {
                if ((a[i]&(1LL<<j))==0) {
                    if ((1LL<<j)-a[i]+cost>k) of=true;
                    cost+=(1LL<<j)-a[i];
                    idx.push_back(i);
                }
                else a[i]-=(1LL<<j);
            }
            if (k>=cost && !of) {
                k-=cost;
                ans+=(1LL<<j);
                for (ll i: idx) a[i]=0;
            }
            //cout << j << ' ' << cost << endl;
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
