#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int g[5005][5005]={};

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    int target=a[1];
    for (int i=2; i<=n; i++) target=gcd(target, a[i]);

    vector<int> dp(5001, 1e9);
    for (int i=1; i<=n; i++) dp[a[i]]=0;
    for (int i=5000; i>=1; i--) {
        for (int j=1; j<=n; j++) {
            dp[g[i][a[j]]]=min(dp[g[i][a[j]]], dp[i]+1);
        }
    }

    int cnt=0;
    for (int i=1; i<=n; i++) if (a[i]!=target) cnt++;
    //cout << target << ' ' << dp[target] << endl;
    if (dp[target]>0) cout << cnt+dp[target]-1 << "\n";
    else cout << cnt+dp[target] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i=1; i<=5000; i++) {
        g[i][0]=i;
        g[0][i]=i;
        g[i][i]=i;
    }
    for (int i=1; i<=5000; i++) {
        for (int j=1; j<i; j++) {
            g[i][j]=g[j][i%j];
            g[j][i]=g[j][i%j];
        }
    }
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
/*
the final number is g=gcd(a[1], ..., a[n])
so we can divide every number by g, then make 1. 
for each i, find number of turns to make a[i] to 1. 
for every number from 1 to 5000, find numbers that make gcd=1 O(5000*5000)

dp[i]=number of operations to make at least one element in the array equal to i. 
for all j, dp[gcd(i, a[j])]=dp[i]+1
*/