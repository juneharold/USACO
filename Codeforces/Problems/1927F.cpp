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
typedef pair<int, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int leader[nmax], sz[nmax];
int Find(int x) {
    if (leader[x]==x) return x;
    return leader[x]=Find(leader[x]);
}
void Union (int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    leader[a]=b;
    sz[b]+=sz[a];
}

vector<pii> graph[nmax];
vector<int> path, ans;
int vst[nmax]={}, s, e;

void dfs(int cur, int prev) {
    vst[cur]=1;
    path.push_back(cur);
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].fs;
        if (nx==prev) continue;
        if (nx==e) {
            int idx=-1;
            ans=path;
            ans.push_back(e);
        }
        else if (vst[nx]==0) dfs(nx, cur);
    }
    path.pop_back();
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, pii>> edges;
    for (int i=1; i<=m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());
    for (int i=1; i<=n; i++) leader[i]=i, sz[i]=1;
    int idx=-1;
    for (int i=m-1; i>=0; i--) {
        int u=edges[i].sc.fs, v=edges[i].sc.sc;
        if (Find(u)!=Find(v)) Union(u, v);
        else idx=i;
    }

    for (int i=m-1; i>=idx; i--) {
        int u=edges[i].sc.fs, v=edges[i].sc.sc, w=edges[i].fs;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    s=edges[idx].sc.fs, e=edges[idx].sc.sc;
    dfs(s, e);

    cout << edges[idx].fs << ' ' << ans.size() << "\n";
    for (int u: ans) cout << u << ' ';
    cout << "\n";

    path.clear();
    ans.clear();
    for (int i=1; i<=n; i++) {
        vst[i]=0;
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
