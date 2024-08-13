#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    multiset<ll> ms;
    ll mx_odd=-1;
    for (int i=0; i<n; i++) {
        ll x; cin >> x;
        if (x%2==0) ms.insert(x);
        else mx_odd=max(mx_odd, x);
    }

    if (ms.size()==0 || ms.size()==n) {
        cout << "0\n";
        return;
    }
    int ans=0;
    while (!ms.empty()) {
        if (mx_odd>*ms.begin()) {
            ll temp=mx_odd+*ms.begin();
            ms.erase(ms.begin());
            mx_odd=temp;
        }
        else {
            ll temp=mx_odd+*--ms.end();
            mx_odd=temp;
        }
        ans++;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
