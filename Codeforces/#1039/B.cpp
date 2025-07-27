#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> p(n+1);
    for (int i=1; i<=n; i++) cin >> p[i];

    int l=1, r=n, t=0;
    while (l<=r) {
        t++;
        if (t%2) {
            if (p[l]<p[r]) {
                cout << 'L';
                l++;
            }
            else {
                cout << 'R';
                r--;
            }
        }
        else {
            if (p[l]>p[r]) {
                cout << 'L';
                l++;
            }
            else {
                cout << 'R';
                r--;
            }
        }
    }
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
