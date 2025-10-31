#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

bool cmp(pii a, pii b) {
    if (a.fs==b.fs) return a.sc>b.sc;
    return a.fs<b.fs;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    
    vector<pii> b(n+5);
    for (int i=1; i<=n; i++) b[i]={a[i], i};
    sort(&b[1], &b[n+1], cmp);

    vector<int> dp(n+5, 0), mx(n+5, 0);
    int idx=0, val=0, ans=0;
    for (int i=1; i<=n; i++) {
        dp[i]=1;
        if (b[i-1].fs==b[i].fs) dp[i]=dp[i-1]+1;

        while (val+1<=b[i].fs-2) {
            mx[val+1]=max(mx[val+1], mx[val]);
            val++;
        }
        dp[i]=max(dp[i], (b[i].fs-2>=0 ? mx[b[i].fs-2] : 0)+1);

        while (idx+1<=n && (b[idx+1].fs<b[i].fs-1 || (b[idx+1].fs==b[i].fs-1 && b[idx+1].sc>b[i].sc))) {
            idx++;
        }
        dp[i]=max(dp[i], dp[idx]+1);
        
        mx[b[i].fs]=max(mx[b[i].fs], dp[i]);

        ans=max(ans, dp[i]);
    }
    cout << n-ans << "\n";
}

/*
1
8
2 3 3 2 2 2 2 3
ans: 2
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
