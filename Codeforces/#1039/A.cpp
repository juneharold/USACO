#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(&a[1], &a[n+1]);
    int ans=0;
    for (int i=n; i>=1; i--) {
        if (a[i]>c) ans++;
        else {
            for (int j=i-1; j>=1; j--) {
                a[j]*=2;
                a[j]=min(c+1, a[j]);
            }
        }
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
