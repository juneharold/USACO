#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define fs first
#define sc second

const int nmax=100005;
vector<pii> graph[nmax];

int N, u[nmax]={}, v[nmax]={}, w[nmax]={};
int depth[nmax]={}, sz[nmax]={}, parent[nmax][20]={}, cost[nmax]={};
int comp[nmax]={}, head[nmax]={}, order[nmax]={}, piv1=0, piv2=0;
int st[4*nmax]={};

void dfs(int cur, int p) {
    sz[cur]=1;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].fs, c=graph[cur][i].sc;
        if (nx==p) continue;
        cost[nx]=c;
        depth[nx]=depth[cur]+1;
        parent[nx][0]=cur;
        dfs(nx, cur);
        sz[cur]+=sz[nx];
    }
}

void hld(int cur, int p) {
    sort(graph[cur].begin(), graph[cur].end(), [](const pii &a, const pii &b){return sz[a.fs]>sz[b.fs];});
    int heavy=-1;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].fs;
        if (nx==p) continue;
        heavy=nx;
        comp[nx]=comp[cur];
        order[nx]=++piv2;
        hld(nx, cur);
        break;
    }
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].fs;
        if (nx==p || nx==heavy) continue;
        comp[nx]=++piv1;
        head[piv1]=nx;
        order[nx]=++piv2;
        hld(nx, cur);
    }
}

void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) {st[n]=v; return;}
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    st[n]=max(st[2*n], st[2*n+1]);
}

int query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return -1e9;
    if (qa<=a && b<=qb) return st[n];
    int mid=(a+b)/2;
    return max(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}

void tree_update(int idx, int val) {
    if (depth[u[idx]]>depth[v[idx]]) swap(u[idx], v[idx]);
	update(1, 1, N, order[v[idx]], order[v[idx]], val);
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) swap(a, b);
    int diff=depth[a]-depth[b];
    for (int i=0; i<=19; i++) {
        if (diff&(1<<i)) a=parent[a][i];
    }
    if (a==b) return a;
    for (int i=19; i>=0; i--) {
        if (parent[a][i]!=parent[b][i]) {
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}

int tree_query(int a, int b) {
    int ret=0;
    while (comp[a]!=comp[b]) {
        int aa=head[comp[a]], bb=head[comp[b]];
        if (depth[aa]>depth[bb]) {
            ret=max(ret, query(1, 1, N, order[aa], order[a]));
            a=parent[aa][0];
        }
        else {
            ret=max(ret, query(1, 1, N, order[bb], order[b]));
            b=parent[bb][0];
        }
    }
    if (depth[a]>depth[b]) swap(a, b);
    if (order[a]<order[b]) ret=max(ret, query(1, 1, N, order[a]+1, order[b]));
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N-1; i++) {
        cin >> u[i] >> v[i] >> w[i];
        graph[u[i]].push_back({v[i], w[i]});
        graph[v[i]].push_back({u[i], w[i]});
    }

    dfs(1, 0);
    for (int i=1; i<20; i++) {
        for (int j=1; j<=N; j++) parent[j][i]=parent[parent[j][i-1]][i-1];
    }

    head[1]=1, comp[1]=1, order[1]=1, piv1=1, piv2=1;
    hld(1, 0);
    for (int i=2; i<=N; i++) update(1, 1, N, order[i], order[i], cost[i]);
    
    int M; cin >> M;
    while (M--) {
        int type; cin >> type; 
        if (type==1) {
            int idx, val; cin >> idx >> val;
            tree_update(idx, val);
        }
        else {
            int a, b; cin >> a >> b;
            int t=lca(a, b);
            cout << max(tree_query(a, t), tree_query(b, t)) << "\n";
        }
    }
}