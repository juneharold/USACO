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

int cost[21][21]={}, dp[1<<21]={};

void solve() {
    string s; cin >> s;
    map<char, int> m;
    int n=0;
    for (int i=0; i<s.size(); i++) {
        if (m.find(s[i])==m.end()) m[s[i]]=n++;
        if (i>0) cost[m[s[i-1]]][m[s[i]]]++;
    }

    fill(&dp[0], &dp[1<<n], 1e9);
    dp[0]=1;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if ((i&(1<<j))==0) continue;
            int bef=i-(1<<j), nc=0;
            for (int k=0; k<n; k++) {
                if ((bef&(1<<k))==0) nc+=cost[j][k];
            }
            dp[i]=min(dp[i], dp[bef]+nc);
        }
    }
    cout << dp[(1<<n)-1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
