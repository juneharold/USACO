#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    int cnt0=0, cnt1=0;
    for (int i=1; i<=n*2; i++) {
        int x; cin >> x;
        if (x==0) cnt0++;
        else cnt1++;
    }
    if (cnt1%2==0) cout << "0 ";
    else cout << "1 ";

    if (cnt1<=n) cout << cnt1 << "\n";
    else cout << 2*n-cnt1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
