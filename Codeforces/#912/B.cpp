#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<vector<ll>> M(n+5, vector<ll>(n+5));
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> M[i][j];

    vector<ll> a(n+1, 0);
    for (int i=1; i<=n; i++) {
        ll cur=(1<<30)-1;
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            cur&=M[i][j];
        }
        a[i]=cur;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            if ((a[i]|a[j])!=M[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
