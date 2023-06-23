#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

vector<pair<int, int>> query[nmax], ans;
vector<int> graph[nmax];
int w[nmax]={}, pfs[nmax]={}, h[nmax]={}, l[nmax]={};
pair<int, int> dp[nmax]; // dp[i] stores maximum and minimum subsegment from node 1 to i

void dfs(int cur, int p) {
    pfs[cur]=pfs[p]+w[cur];
    dp[cur].f=max(dp[cur].f, pfs[cur]-l[cur]);
    dp[cur].s=min(dp[cur].s, pfs[cur]-h[cur]);
    for (int nx: graph[cur]) {
        dp[nx]=dp[cur];
        h[nx]=max(h[cur], pfs[cur]);
        l[nx]=min(l[cur], pfs[cur]);
        dfs(nx, cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int idx=2;
        for (int i=0; i<n; i++) {
            char c; cin >> c; 
            if (c=='?') {
                int u, v, k; cin >> u >> v >> k;
                query[v].push_back({k, i});
            }
            else {
                int v, x; cin >> v >> x;
                graph[v].push_back(idx);
                w[idx]=x;
                idx++;
            }
        }
        
        for (int i=2; i<idx; i++) dp[i]={-1e9, 1e9};
        w[1]=1;
        dp[1]={1, 0};
        h[1]=0; 
        l[1]=0;
        dfs(1, 0);

        for (int i=1; i<idx; i++) {
            for (auto q: query[i]) {
                if (dp[i].s<=q.f && q.f<=dp[i].f) ans.push_back({q.s, 1});
                else ans.push_back({q.s, 0});
            }
        }
        sort(ans.begin(), ans.end());
        for (auto x: ans) {
            if (x.s) cout << "YES\n";
            else cout << "NO\n";
        }
        ans.clear();
        for (int i=1; i<idx; i++) {
            graph[i].clear();
            query[i].clear();
        }
    }
}
/*
1
7
+ 1 -1
+ 1 1
+ 2 -1
+ 4 1
+ 5 1
+ 5 -1
+ 7 -1


? 1 1 2
? 1 2 1
+ 1 1
? 1 3 -1
? 1 1 1
? 1 3 2
? 1 1 0
*/