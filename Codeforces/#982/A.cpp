#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int mx=0, pos=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]>mx) {
            mx=a[i];
            pos=i;
        }
    }
    int ans=1e9;
    for (int i=0; i<n; i++) {
        int cnt=0;
        for (int j=i+1; j<n; j++) if (a[j]>a[i]) cnt++;
        for (int j=i-1; j>=0; j--) if (a[j]<a[i]) cnt++;
        ans=min(ans, cnt);
        if (pos==i) break;
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
