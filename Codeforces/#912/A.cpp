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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    if (k>=2) {
        cout << "YES\n";
    }
    else {
        for (int i=1; i<n; i++) {
            if (a[i]<a[i-1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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
