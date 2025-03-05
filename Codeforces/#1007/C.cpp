#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<int> graph[nmax];
int dp[nmax]={};
int parent[nmax][20], depth[nmax];

void dfs(int cur, int p) {
    dp[cur]=1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        depth[nx]=depth[cur]+1;
        parent[nx][0]=cur;
        dfs(nx, cur);
        dp[cur]+=dp[nx];
    }
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) swap(a, b);
    for (int i=19; i>=0; i--) {
        if (depth[a]-depth[b]>=(1<<i)) a=parent[a][i];
    }
    if (a==b) return a;
    for (int i=19; i>=0; i--) {
        if (parent[a][i]!=parent[b][i]) a=parent[a][i], b=parent[b][i];
    }
    return parent[a][0];
}

void insert_all_children(set<int> &S, int cur, int p) {
    S.insert(cur);
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        insert_all_children(S, nx, cur);
    }
}

void solve() {
    int n, st, en; cin >> n >> st >> en;
    int u, v;
    for (int i=1; i<=n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // compute lca
    dfs(1, 0);
    for (int i=1; i<20; i++) {
        for (int j=1; j<=n; j++) parent[j][i]=parent[parent[j][i-1]][i-1];
    }
    u=lca(st, en);
    vector<int> ans;

    set<int> Y;
    insert_all_children(Y, en, parent[en][0]);
    

    set<int> rest;
    for (int i=1; i<=n; i++) {
        if (Y.find(i)!=Y.end()) continue;
        rest.insert(i);
    }

    vector<int> last_nodes;
    int cur=en;
    while (cur!=0) {
        last_nodes.push_back(cur);
        rest.erase(cur);
        Y.erase(cur);
        cur=parent[cur][0];
    }

    //use rest first 
    vector<pii> rest_list;
    for (int node: rest) rest_list.push_back({depth[node], node});
    sort(rest_list.begin(), rest_list.end());
    reverse(rest_list.begin(), rest_list.end());
    for (auto node: rest_list) ans.push_back(node.sc);

    // use Y next
    vector<pii> y_list;
    for (int node: Y) y_list.push_back({depth[node], node});
    sort(y_list.begin(), y_list.end());
    reverse(y_list.begin(), y_list.end());
    for (auto node: y_list) ans.push_back(node.sc);

    // use last nodes;
    while (!last_nodes.empty()) {
        ans.push_back(last_nodes.back());
        last_nodes.pop_back();
    }

    for (int aa: ans) cout << aa << ' ';
    cout << "\n";

    for (int i=1; i<=n; i++) {
        graph[i].clear();
        depth[i]=0;
        dp[i]=0;
        for (int j=0; j<20; j++) parent[i][j]=0;
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
