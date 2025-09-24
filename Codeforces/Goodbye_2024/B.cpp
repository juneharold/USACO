#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> l(n+1), r(n+1);
    vector<int> a(2*n+5, 0), pfs(2*n+5, 0);
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
        if (l[i]==r[i]) a[l[i]]++;
    }
    for (int i=1; i<=2*n+1; i++) pfs[i]=pfs[i-1]+(a[i]>0 ? 1 : 0);
    string ans="";
    for (int i=1; i<=n; i++) {
        if (l[i]==r[i]) {
            if (a[l[i]]==1) ans+="1";
            else ans+="0";
        }
        else {
            if (pfs[r[i]]-pfs[l[i]-1]==r[i]-l[i]+1) ans+="0";
            else ans+="1";
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
