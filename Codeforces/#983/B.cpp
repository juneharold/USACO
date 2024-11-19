#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, k; cin >> n >> k;
    if (n==1) {
        cout << "1\n1\n";
        return;
    }
    if (k==1 || k==n) {
        cout << "-1\n";
        return;
    }
    set<int> s;
    s.insert(1);
    s.insert(k);
    s.insert(k+1);
    if ((k-1)%2==0) {
        s.insert(2);
    }
    if ((k-1)%2==0) {
        if (k+2>n) {
            cout << "-1\n";
            return;
        }
        s.insert(k+2);
    }

    cout << s.size() << "\n";
    for (int x: s) cout << x << ' ';
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
