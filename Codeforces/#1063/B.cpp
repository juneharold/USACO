#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    for (int i=1; i<=n; i++) cin >> a[i];
    vector<char> x(n+5);
    for (int i=1; i<=n; i++) cin >> x[i];

    vector<int> pos(n+5);
    for (int i=1; i<=n; i++) pos[a[i]]=i;
    
    vector<pii> ans;
    ans.push_back({min(pos[1], pos[n]), max(pos[1], pos[n])});
    ans.push_back({1, pos[1]});
    ans.push_back({1, pos[n]});
    ans.push_back({pos[1], n});
    ans.push_back({pos[n], n});

    vector<char> s(n+5, '0');
    for (auto op: ans) {
        int l=op.fs, r=op.sc;
        for (int i=l+1; i<r; i++) {
            if (min(a[l], a[r])<a[i] && a[i]<max(a[l], a[r])) s[i]='1';
        }
    }

    for (int i=1; i<=n; i++) {
        if (x[i]=='1' && s[i]=='0') {
            cout << "-1\n";
            return;
        }
    }
    cout << "5\n";
    for (auto op: ans) cout << op.fs << ' ' << op.sc << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
