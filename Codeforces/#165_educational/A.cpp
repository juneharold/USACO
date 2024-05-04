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
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans=n;
    vector<int> vst(n, 0);
    for (int i=0; i<n; i++) {
        if (vst[i]) continue;
        int cur=i, cnt=0;
        while (vst[cur]==0) {
            vst[cur]=1;
            cnt++;
            cur=a[cur];
        }
        if (cnt>1) ans=min(ans, min(3, cnt));
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
