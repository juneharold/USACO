#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<pii> v[nmax];

void solve() {
    int n; cin >> n;
    int a, b;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        v[b].push_back({a, i});
    }

    vector<int> dp(2*n+1, 0), prev(2*n+1, -1), last_pick(2*n+1, -1);
    int idx=0;
    for (int i=1; i<=2*n; i++) {
        b=i;
        for (auto [a, id]: v[i]) {
            for (int j=1; j<a; j++) {
                //cout << i << ' ' << dp[j]+b-j << ' ' << dp[i] << endl;
                if (dp[j]+b-a>dp[i]) {
                    dp[i]=dp[j]+b-a;
                    prev[i]=j;
                    last_pick[i]=id;
                }
            }
            for (int j=a; j<b; j++) {
                //cout << i << ' ' << dp[j]+b-j << ' ' << dp[i] << endl;
                if (dp[j]+b-j>dp[i]) {
                    dp[i]=dp[j]+b-j;
                    prev[i]=j;
                    last_pick[i]=id;
                }
            }
        }
        if (dp[i-1]>dp[i]) {
            dp[i]=dp[i-1];
            prev[i]=i-1;
        }
    }

    int cur=2*n;
    set<int> ans;
    while (cur!=-1) {
        if (last_pick[cur]!=-1) ans.insert(last_pick[cur]);
        cur=prev[cur];
    }
    cout << ans.size() << "\n";
    for (int x: ans) cout << x << ' ';
    cout << "\n";

    for (int i=1; i<=2*n; i++) v[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}

/*
6
1 2
2 4
1 4
1 5
5 10
1 10

4
2 4
1 5
1 6
5 6

2
1 3
2 4
*/
