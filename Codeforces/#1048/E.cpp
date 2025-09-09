#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e3+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<int> graph[nmax];
int depth[nmax]={}, sz[nmax]={};

void dfs(int cur) {
    sz[depth[cur]]++;
    for (int nx: graph[cur]) {
        depth[nx]=depth[cur]+1;
        dfs(nx);
    }
}

void solve() {
    int n, k; cin >> n >> k;
    int p;
    for (int i=2; i<=n; i++) {
        cin >> p;
        graph[p].push_back(i);
    }

    dfs(1);

    int lo=0, hi=1e9;
    for (int i=1; i<=n; i++) {
        if (graph[i].size()==0) hi=min(hi, depth[i]);
    }
    //cout << "lo hi: " << lo << ' ' << hi << endl;

    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        vector<int> objects;
        int sum=0;
        for (int i=0; i<=mid; i++) {
            objects.push_back(sz[i]);
            sum+=sz[i];
        }
        vector<int> dp(k+1, 0);
        dp[0]=1;
        for (int obj: objects) {
            for (int i=k; i>=1; i--) {
                if (i-obj>=0 && dp[i-obj]) dp[i]=1;
            }
        }
        // cout << "mid: " << mid << endl;
        // for (int i=0; i<=k; i++) cout << dp[i] << ' ';
        // cout << endl;

        bool possible=false;
        for (int i=0; i<=k; i++) {
            if (dp[i] && sum-i<=n-k) possible=true;
        }

        if (possible) lo=mid;
        else hi=mid-1;
    }
    cout << lo+1 << "\n";

    for (int i=0; i<nmax; i++) {
        sz[i]=0;
        depth[i]=0;
        graph[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
