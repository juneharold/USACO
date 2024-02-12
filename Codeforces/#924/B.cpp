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
    set<int> s;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    vector<int> a;
    for (int x: s) a.push_back(x);
    sort(a.begin(), a.end());
    int m=a.size(), ans=0;
    for (int i=0; i<m; i++) {
        int j=lower_bound(a.begin(), a.end(), a[i]-(n-1))-a.begin();
        ans=max(ans, i-j+1);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
