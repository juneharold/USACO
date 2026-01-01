#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> b(n+1);
    for (int i=1; i<=n; i++) cin >> b[i];

    vector<int> x(q+1), y(q+1), z(q+1);
    for (int i=1; i<=q; i++) cin >> x[i] >> y[i] >> z[i];

    vector<int> state(n+1);
    for (int i=1; i<=n; i++) state[i]=b[i];

    for (int i=q; i>=1; i--) {
        int zz=state[z[i]];
        state[z[i]]=0;
        state[x[i]]=max(state[x[i]], zz);
        state[y[i]]=max(state[y[i]], zz);
    }

    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        if (state[i]==0) state[i]=1e9;
        a[i]=state[i];
    }

    for (int i=1; i<=q; i++) state[z[i]]=min(state[x[i]], state[y[i]]);
    for (int i=1; i<=n; i++) {
        if (state[i]!=b[i]) {
            cout << "-1\n";
            return;
        }
    }

    for (int i=1; i<=n; i++) cout << a[i] << ' ';
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
