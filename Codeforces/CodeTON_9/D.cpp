#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> factors[nmax];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m+1);
    for (int i=1; i<=m; i++) cin >> a[i];

    vector<int> ans(n+1);
    ans[1]=m; // a[m]
    for (int i=2; i<=n; i++) {
        int mn=m;
        //cout << i << endl;
        for (int f: factors[i]) {
            if (f==i) continue;
            mn=min(mn, ans[f]);
        }
        if (mn==1) {
            cout << "-1\n";
            return;
        }
        ans[i]=mn-1;
    }

    for (int i=1; i<=n; i++) cout << a[ans[i]] << ' ';
    cout << "\n";
}

int main()
{
    for (int i=1; i<=100000; i++) {
        for (int j=1; j*j<=i; j++) {
            if (i%j==0) factors[i].push_back(j);
            if (i%j==0 && j*j!=i)  factors[i].push_back(i/j);
        }
        sort(factors[i].begin(), factors[i].end());
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
