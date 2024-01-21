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


int N, Q, e[nmax]={};
vector<int> graph[nmax];

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

int sz[nmax]={};
void dfs(int cur, int p) {
    sz[cur]=1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        depth[nx]=depth[cur]+1;
        parent[nx][0]=cur;
        dfs(nx, cur);
        sz[cur]+=sz[nx];
    }
}

int group[nmax], head[nmax], order[nmax], piv1, piv2;
void hld(int cur, int p) {
    sort(graph[cur].begin(), graph[cur].end(), [](int &a, int &b){return sz[a]>sz[b];});
    int heavy=-1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        heavy=nx;
        group[nx]=group[cur];
        order[nx]=++piv2;
        hld(nx, cur);
        break;
    }
    for (int nx: graph[cur]) {
        if (nx==p || nx==heavy) continue;
        group[nx]=++piv1;
        head[group[nx]]=nx;
        order[nx]=++piv2;
        hld(nx, cur);
    }
}

int segtree[4*nmax]={};
int query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)^query(2*n+1, mid+1, b, qa, qb);
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=segtree[2*n]^segtree[2*n+1];
}

int tree_query(int a, int b) {
    int ret=0;
    while (group[a]!=group[b]) {
        //cout << a << ' ' << b << endl;
        if (a==1 && b==0) break;
        int aa=head[group[a]], bb=head[group[b]];
        if (depth[a]>depth[b]) {
            ret^=query(1, 1, N, order[aa], order[a]);
            a=parent[aa][0];
        }
        else {
            ret^=query(1, 1, N, order[bb], order[b]);
            b=parent[bb][0];
        }
    }
    if (depth[a]>depth[b]) swap(a, b);
    ret^=query(1, 1, N, order[a], order[b]);
    return ret;
}

void solve() {
    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> e[i];
    for (int i=1; i<=N-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    for (int i=1; i<20; i++) {
        for (int j=1; j<=N; j++) parent[j][i]=parent[parent[j][i-1]][i-1];
    }

    group[1]=head[1]=order[1]=piv1=piv2=1;
    hld(1, 0);

    for (int i=1; i<=N; i++) update(1, 1, N, order[i], order[i], e[i]);

    while (Q--) {
        int type; cin >> type;
        if (type==1) {
            int i, v; cin >> i >> v;
            e[i]=v;
            update(1, 1, N, order[i], order[i], v);
        }
        else {
            int u, v; cin >> u >> v;
            int t=lca(u, v);
            cout << (tree_query(u, t)^tree_query(t, v)^e[t]) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
