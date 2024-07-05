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
    string a, b; cin >> a >> b;
    int ans=1e9;
    for (int j=0; j<b.size(); j++) {
        int idx=j;
        for (int i=0; i<a.size(); i++) {
            if (idx<b.size() && b[idx]==a[i]) {
                idx++;
            }
        }
        ans=min(ans, (int)a.size()+(int)(b.size()-idx+j));
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
