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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=3e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

char s[nmax];
int l[nmax]={}, r[nmax]={};
int ans=1e9;
void dfs(int cur, int cnt) {
    if (cur==0) return;
    if (l[cur]==0 && r[cur]==0) {
        ans=min(ans, cnt);
        return;
    }

    if (s[cur]=='U') {
        dfs(l[cur], cnt+1);
        dfs(r[cur], cnt+1);
    }
    if (s[cur]=='L') {
        dfs(l[cur], cnt);
        dfs(r[cur], cnt+1);
    }
    if (s[cur]=='R') {
        dfs(l[cur], cnt+1);
        dfs(r[cur], cnt);
    }
}

void solve() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int i=1; i<=n; i++) cin >> l[i] >> r[i];
    dfs(1, 0);
    cout << ans << "\n";
    ans=1e9;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
