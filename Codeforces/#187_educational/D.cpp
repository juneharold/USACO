#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n+5), b(m+5);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];

    ll temp=a[1];
    for (int i=2; i<=n; i++) {
        if (temp>n+m) temp=1e18;
        else temp=lcm(temp, a[i]);
    }

    set<ll> s;
    for (int i=1; i<=n; i++) s.insert(a[i]);

    vector<bool> marked(n+m+5, false);
    for (ll x: s) {
        ll k=1; 
        while (x*k<=n+m) {
            marked[x*k]=true;
            k++;
        }
    }

    vector<ll> A, B, C;
    for (int i=1; i<=m; i++) {
        if (marked[b[i]]) {
            if (b[i]%temp==0) A.push_back(b[i]);
            else B.push_back(b[i]);
        }
        else C.push_back(b[i]);
    }

    int turn=0;
    while (true) {
        if (turn%2==0) { // Alice;
            if (A.empty() && B.empty()) {
                cout << "Bob\n";
                return;
            }
            if (!B.empty()) B.pop_back();
            else A.pop_back();
        }
        else {
            if (B.empty() && C.empty()) {
                cout << "Alice\n";
                return;
            }
            if (!B.empty()) B.pop_back();
            else C.pop_back();
        }
        turn++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
