#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n, b, c; cin >> n >> b >> c;
    if (b==0) {
        if (c>n-1) cout << n << "\n";
        else if (c>=n-2) cout << n-1 << "\n";
        else cout << "-1\n";
        return;
    }
    ll i=(n-1-c)/b+1;
    if (n-1-c<0) i--;
    i=max(0LL, i);
    cout << n-i << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
