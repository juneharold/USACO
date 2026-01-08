#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<int> dp(n+5, -1e9), cnt(n+5, 0);
    for (int i=1; i<=n; i++) {
        int mx=0;
        fill(&cnt[0], &cnt[n+1], 0);
        for (int j=i-1; j>=1; j--) {
            // check if j is possible
            if ((i-j-1)%2==0 && mx<=(i-j-1)/2 && a[j]==a[i]) {
                dp[i]=max(dp[i], dp[j]+1);
            }
            // update cnt
            cnt[a[j]]++;
            mx=max(mx, cnt[a[j]]);
        }

        // do j==0
        if ((i-1)%2==0 && mx<=(i-1)/2) {
            dp[i]=max(dp[i], 1);
        }
    }

    int ans=0, mx=0;
    fill(&cnt[0], &cnt[n+1], 0);
    for (int i=n; i>=1; i--) {
        // check if j is possible
        if ((n-i)%2==0 && mx<=(n-i)/2) {
            ans=max(ans, dp[i]);
        }
        // update cnt
        cnt[a[i]]++;
        mx=max(mx, cnt[a[i]]);
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
/*
let's say we want to keep 3 
any pairs that doesn't include 3 can be removed instantly

we have some form:
11113333333311111322223333333

if we want to delete from l to r, the maximum occuring element must be at most half of r-l+1

for each i,
(1) can we end by keeping a[i], which asks can we clear the right side of i within itself?
(2) what's the previous element same as a[i], call it a[j], where we could clear the right side of j within itself?
(3) the answer for i is ans[j]+

dp[i]=maximum remaining element ending at i
dp[i]=dp[j]+1 if we can remove everything between j to i within itself and a[i]==a[j]

a[0] is wildcard 

for dp[i] to be possible answer, we need to check if we can remove everything to the right. 

12121233
*/