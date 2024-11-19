#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(&a[1], &a[n+1]);

    int ans=1e9;
    for (int i=1; i<=n-2; i++) {
        int lo=i+2, hi=n;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (a[mid]<a[i]+a[i+1]) lo=mid;
            else hi=mid-1;
        }
        if (a[lo]>=a[i]+a[i+1]) lo--;
        ans=min(ans, i-1+(n-lo));
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
