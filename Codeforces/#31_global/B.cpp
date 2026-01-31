#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n; 
    vector<string> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    string ans=a[1];
    for (int i=2; i<=n; i++) {
        string s1=ans+a[i], s2=a[i]+ans;
        ans=min(s1, s2);
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
