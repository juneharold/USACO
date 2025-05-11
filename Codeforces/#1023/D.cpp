#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=150005, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<pair<int, pii>> ans;
queue<vector<pii>> trees; // each tree is a list of edges 

vector<int> graph[nmax];
int removed[nmax]={};
int depth[nmax]={}, parent[nmax]={};
void dfs1(int cur, int p) {
    for (int nx: graph[cur]) {
        if (nx==p || removed[nx]) continue;
        parent[nx]=cur;
        depth[nx]=depth[cur]+1;
        dfs1(nx, cur);
    }
}

vector<pii> new_edges;
int vst[nmax]={};
void dfs2(int cur) {
    vst[cur]=1;
    for (int nx: graph[cur]) {
        if (removed[nx]) continue;
        if (vst[nx]==0) {
            new_edges.push_back({cur, nx});
            dfs2(nx);
        }
    }
}

void operation(int n, vector<pii> edges) {
    vector<int> nodes, seen(n+1, 0);
    for (auto [u, v]: edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
        if (seen[u]==0) {
            seen[u]=1;
            nodes.push_back(u);
        }
        if (seen[v]==0) {
            seen[v]=1;
            nodes.push_back(v);
        }
    }
    sort(nodes.begin(), nodes.end());

    dfs1(edges[0].fs, 0);
    int root=-1, mx=0;
    for (int u: nodes) {
        if (depth[u]>=mx) {
            root=u;
            mx=depth[u];
        }
    }
    for (int u: nodes) {
        depth[u]=0;
        parent[u]=0;
    }

    dfs1(root, 0);
    int target=-1;
    mx=0;
    for (int u: nodes) {
        if (depth[u]>=mx) {
            target=u;
            mx=depth[u];
        }
    }
    int cur=target, d=0;
    while (cur!=0) {
        removed[cur]=1;
        d++;
        cur=parent[cur];
    }
    ans.push_back({d, {max(root, target), min(root, target)}});

    for (int u: nodes) {
        if (removed[u] || vst[u]) continue;
        dfs2(u);
        if (new_edges.empty()) {
            ans.push_back({1, {u, u}});
            removed[u]=1;
            continue;
        }
        trees.push(new_edges);
        new_edges.clear();
    }

    for (int u: nodes) {
        graph[u].clear();
        depth[u]=0;
        parent[u]=0;
        vst[u]=0;
    }
}

void solve() {
    int n; cin >> n; 
    vector<pii> edges;
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        edges.push_back({u, v});
    }
    if (edges.empty()) {
        ans.push_back({1, {1, 1}});
    }
    else trees.push(edges);
    while (!trees.empty()) {
        operation(n, trees.front());
        trees.pop();
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (auto x: ans) {
        cout << x.fs << ' '<< x.sc.fs << ' ' << x.sc.sc << ' ';
    }
    cout << "\n";
    ans.clear();
    for (int i=1; i<=n; i++) removed[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}