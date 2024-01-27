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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> graph[nmax];
vector<pair<int, pii>> check[nmax];
int T[nmax]={}, active[nmax]={}, t_res[nmax]={}, a_res[nmax]={}, b_res[nmax]={};

int parent[nmax][20], depth[nmax];
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

void dfs1(int cur, int p) {
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        depth[nx]=depth[cur]+1;
        parent[nx][0]=cur;
        dfs1(nx, cur);
    }
}

void dfs2(int cur, int p) {
    active[T[cur]]++;
    for (int i=0; i<check[cur].size(); i++) {
        int type=check[cur][i].fs, idx=check[cur][i].sc.fs, target=check[cur][i].sc.sc;
        if (type==0) {
            if (T[cur]==target) t_res[idx]=active[target]-1;
            else t_res[idx]=active[target];
        }
        if (type==1) a_res[idx]=active[target];
        if (type==2) b_res[idx]=active[target];
    }
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dfs2(nx, cur);
    }
    active[T[cur]]--;
}

void solve() {
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> T[i];
    for (int i=1; i<=N-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs1(1, 0);
    for (int i=1; i<20; i++) {
        for (int j=1; j<=N; j++) parent[j][i]=parent[parent[j][i-1]][i-1];
    }

    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        int t=lca(a, b);
        check[t].push_back({0, {i, c}});
        check[a].push_back({1, {i, c}});
        check[b].push_back({2, {i, c}});
    }

    dfs2(1, 0);
    string ans="";
    for (int i=1; i<=M; i++) {
        if (a_res[i]>t_res[i] || b_res[i]>t_res[i]) ans+="1";
        else ans+="0";
    }
    cout << ans;
}

int main()
{
    //freopen("milkvisits.in", "r", stdin);
    //freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
