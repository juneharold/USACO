#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll x, y, a; cin >> x >> y >> a;
    a++;
    ll k=a/(x+y);
    k-=10;
    ll cur=max(0LL, k*(x+y));
    while (cur<a) {
        cur+=x;
        if (cur>=a) {
            cout << "NO\n";
            return;
        }
        cur+=y;
        if (cur>=a) {
            cout << "YES\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
