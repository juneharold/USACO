#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<ll> b(n+1);
    if (k%2==1) {
        for (int i=1; i<=n; i++) {
            b[i]=a[i]+(a[i]%2LL==1 ? k : 0);
        }
    }
    else {
        ll target=k-1;
        if (target==1) { // k==2
            for (int i=1; i<=n; i++) {
                if (a[i]%3LL==2) b[i]=a[i]+2LL*k;
                else if (a[i]%3LL==1) b[i]=a[i]+k;
                else b[i]=a[i];
            }
        }
        else {
            for (int i=1; i<=n; i++) {
                b[i]=a[i]+(target-a[i]%target)*k;
            }
        }
    }
    for (int i=1; i<=n; i++) cout << b[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
