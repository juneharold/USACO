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

bool check_all_white(vector<vector<char>> &a, int x1, int y1, int x2, int y2) {
    if (x1==x2) {
        for (int j=y1; j<=y2; j++) {
            if (a[x1][j]=='B') {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i=x1; i<=x2; i++) {
            if (a[i][y1]=='B') {
                return false;
            }
        }
        return true;
    }
}

bool check_all_black(vector<vector<char>> &a, int x1, int y1, int x2, int y2) {
    if (x1==x2) {
        for (int j=y1; j<=y2; j++) {
            if (a[x1][j]=='W') {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i=x1; i<=x2; i++) {
            if (a[i][y1]=='W') {
                return false;
            }
        }
        return true;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n+1, vector<char>(m+1));
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> a[i][j];
    if (check_all_white(a, 1, 1, 1, m) && check_all_black(a, n, 1, n, m)) {
        cout << "NO\n";
        return;
    }
    if (check_all_white(a, 1, m, n, m) && check_all_black(a, 1, 1, n, 1)) {
        cout << "NO\n";
        return;
    }
    if (check_all_white(a, n, 1, n, m) && check_all_black(a, 1, 1, 1, m)) {
        cout << "NO\n";
        return;
    }
    if (check_all_white(a, 1, 1, n, 1) && check_all_black(a, 1, m, n, m)) {
        cout << "NO\n";
        return;
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
