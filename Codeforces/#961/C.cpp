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

long double log_base(long double x, long double y) {
    return log(y) / log(x);
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];
    a[0]=1;

    ll ans=0, x=0;
    for (ll i=1; i<=n; i++) {
        if (a[i]==1 && a[i-1]!=1) {
            cout << "-1\n";
            return;
        }
        else if (a[i]==1 || a[i-1]==1) continue;
        long double temp=log_base(2.0, log_base((long double)a[i], (long double)a[i-1]));
        ll y=ceil((long double)x+temp);
        if (temp<-INF) y=0;
        ans+=max(0LL, y); 
        x=max(0LL, y);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
