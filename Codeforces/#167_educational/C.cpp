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
    vector<int> a(n+1), b(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    int cnt1=0, cnt2=0, s1=0, s2=0;
    for (int i=1; i<=n; i++) {
        pii temp={a[i], b[i]};
        if (temp==make_pair(1, -1) || temp==make_pair(1, 0)) s1++;
        else if (temp==make_pair(-1, 1) || temp==make_pair(0, 1)) s2++;
        else if (temp==make_pair(1, 1)) cnt1++;
        else if (temp==make_pair(-1, -1)) cnt2++;
    }
    while (cnt2>0) {
        if (s1<=s2) s2--;
        else s1--;
        cnt2--;
    }
    while (cnt1>0) {
        if (s1<=s2) s1++;
        else s2++;
        cnt1--;
    }
    cout << min(s1, s2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
