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
    ll k, x, a; cin >> k >> x >> a;
    ll spending=0;
    for (int i=1; i<=x; i++) {
        ll cur=a-spending;
        ll need=(a-cur)/(k-1);
        if (cur+need*(k-1)<=a) need++;
        if (need>cur) {
            cout << "NO\n";
            return;
        }
        spending+=need;
    }
    if ((a-spending)*k<=a) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
