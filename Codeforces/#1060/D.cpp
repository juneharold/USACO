#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<int> graph[nmax];
int dist[nmax]={}, active_child[nmax]={}, parent[nmax]={};

void dfs(int cur, int p) {
    parent[cur]=p;
    active_child[cur]=graph[cur].size();
    if (p!=-1) active_child[cur]--;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dist[nx]=dist[cur]+1;
        dfs(nx, cur);
    }
}

void solve() {
    int n; cin >> n;
    int u, v;
    for (int i=1; i<=n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(n, -1);

    vector<int> leaves;
    for (int i=1; i<=n; i++) {
        if (active_child[i]==0) leaves.push_back(i);
    }

    int cnt=0;
    vector<pii> ans;
    while (!leaves.empty()) {
        if (leaves.size()==1 && leaves[0]==n) break;
        int leaf=leaves.back(); leaves.pop_back();
        if ((dist[1]+cnt)%2!=dist[leaf]%2) {
            ans.push_back({1, -1});
            ans.push_back({1, -1});
            cnt+=2;
            ans.push_back({2, leaf});
        }        
        else {
            ans.push_back({1, -1});
            cnt++;
            ans.push_back({2, leaf});
        }
        active_child[parent[leaf]]--;
        if (active_child[parent[leaf]]==0) leaves.push_back(parent[leaf]);
    }

    cout << ans.size() << "\n";
    for (auto x: ans) {
        if (x.fs==1) cout << "1\n";
        else cout << "2 " << x.sc << "\n";
    }

    fill(&dist[0], &dist[n+5], 0);
    fill(&active_child[0], &active_child[n+5], 0);
    fill(&parent[0], &parent[n+5], 0);
    for (int i=1; i<=n; i++) graph[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
