#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int n, k;
int nx[nmax][27]={}, dp[nmax]={};
char s[nmax];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> s[i];

    for (int j=1; j<=k; j++) {
        int next=1e9;
        for (int i=n; i>=0; i--) {
            nx[i][j]=next;
            if (s[i]-'a'+1==j) next=i;
        }
    }

    fill(&dp[0], &dp[n+1], 1e9);
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=k; j++) {
            if (nx[i][j]==1e9) {
                dp[i]=1;
                break;
            }
            dp[i]=min(dp[i], dp[nx[i][j]]+1);
        }
    }

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int pos=0, idx=0;
        while (idx<t.size()) {
            pos=nx[pos][t[idx]-'a'+1];
            if (pos==1e9) break;
            idx++;
        }
        if (pos==1e9) cout << "0\n";
        else cout << dp[pos] << "\n";
    }
}
