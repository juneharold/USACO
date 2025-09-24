#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int n, m;
char grid[55][55];

bool check_top(int i, int j) {
    for (int k=i; k>=1; k--) {
        if (grid[k][j]=='0') return false;
    }
    return true;
}

bool check_left(int i, int j) {
    for (int k=j; k>=1; k--) {
        if (grid[i][k]=='0') return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> grid[i][j];

    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
        if (grid[i][j]=='1' && !check_top(i, j) && !check_left(i, j)) {
            cout << "NO\n";
            return;
        }
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
