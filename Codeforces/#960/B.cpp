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
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n+1, 0);
    for (int i=1; i<=x; i++) a[i]=1;

    for (int i=x+1; i<=n; i++) a[i]=(a[i-1]==1 ? -1 : 1);
    for (int i=y-1; i>=1; i--) a[i]=(a[i+1]==1 ? -1 : 1);

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
