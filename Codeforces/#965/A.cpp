#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll xc, yc, k; cin >> xc >> yc >> k;
    if (k%2==1) {
        cout << xc << ' ' << yc << "\n";
        k--;
    }
    for (int i=1; i<=k/2; i++) cout << xc-i <<  ' ' << yc << "\n";
    for (int i=1; i<=k/2; i++) cout << xc+i <<  ' ' << yc << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
