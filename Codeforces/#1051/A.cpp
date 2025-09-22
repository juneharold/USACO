#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    int target=n;
    for (int k=1; k<=n; k++) {
        int start=-1, end=-1;
        for (int i=1; i<=n; i++) {
            if (a[i]==target) {
                if (start==-1) start=i;
                end=i;
            }
        }
        if (end-start+1==k) {
            for (int i=start; i<=end; i++) a[i]--;
        }
        else {
            cout << "NO\n";
            return;
        }
        target--;
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
