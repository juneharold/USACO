#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int nmax=5e5+5;

int N, M; 

int parent[nmax][20]={}, depth[nmax]={};
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

unsigned int segtree[4*nmax]={}, lazy[4*nmax][2]={};
void propagate(int n, unsigned int a, unsigned int b) {
    segtree[n]=segtree[n]*lazy[n][0]+(b-a+1)*lazy[n][1];
    if (a!=b) {
        lazy[2*n][0]=lazy[2*n][0]*lazy[n][0];
        lazy[2*n][1]=lazy[2*n][1]*lazy[n][0]+lazy[n][1];
        lazy[2*n+1][0]=lazy[2*n+1][0]*lazy[n][0];
        lazy[2*n+1][1]=lazy[2*n+1][1]*lazy[n][0]+lazy[n][1];
    }
    lazy[n][0]=1, lazy[n][1]=0;
}
unsigned int query(int n, int a, int b, int qa, int qb) {
    propagate(n, a, b);
    if (b<qa || qb<a) return (unsigned)0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return (query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb));
}
void update(int n, int a, int b, int qa, int qb, unsigned int mul, unsigned int add) {
    propagate(n, a, b);
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { 
        lazy[n][0]*=mul;
        lazy[n][1]*=mul;
        lazy[n][1]+=add;
        propagate(n, a, b);
        return; 
    }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, mul, add);
    update(2*n+1, mid+1, b, qa, qb, mul, add);
    segtree[n]=segtree[2*n]+segtree[2*n+1];
}

vector<int> graph[nmax];
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
// group[1]=head[1]=order[1]=piv1=piv2=1 잊지 말기!!!
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

unsigned int tree_query(int a, int b) {
    unsigned int ret=0;
    while (group[a]!=group[b]) {
        if (a==1 && b==0) break;
        int aa=head[group[a]], bb=head[group[b]];
        if (depth[a]>depth[b]) {
            ret+=query(1, 1, N, order[aa], order[a]);
            a=parent[aa][0];
        }
        else {
            ret+=query(1, 1, N, order[bb], order[b]);
            b=parent[bb][0];
        }
    }
    if (depth[a]>depth[b]) swap(a, b);
    ret+=query(1, 1, N, order[a], order[b]);
    return ret;
}

void tree_update(int a, int b, unsigned int mul, unsigned int add) {
    while (group[a]!=group[b]) {
        if (a==1 && b==0) break;
        int aa=head[group[a]], bb=head[group[b]];
        if (depth[a]>depth[b]) {
            update(1, 1, N, order[aa], order[a], mul, add);
            a=parent[aa][0];
        }
        else {
            update(1, 1, N, order[bb], order[b], mul, add);
            b=parent[bb][0];
        }
    }
    if (depth[a]>depth[b]) swap(a, b);
    update(1, 1, N, order[a], order[b], mul, add);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int a, b;
    for (int i=1; i<=N-1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    for (int j=1; j<20; j++) {
        for (int i=1; i<=N; i++) parent[i][j]=parent[parent[i][j-1]][j-1];
    }
    group[1]=1, head[1]=1, order[1]=1;
    hld(1, 0);

    for (int i=1; i<nmax; i++) lazy[i][0]=1;

    unsigned int ans=0, type, x, y, v, t, temp;
    while (M--) {
        cin >> type;
        if (type==1) {
            cin >> x >> v;
            update(1, 1, N, order[x], order[x]+sz[x]-1, 1, v);
        }
        else if (type==2) {
            cin >> x >> y >> v;
            t=lca(x, y);
            tree_update(x, t, 1, v);
            tree_update(y, t, 1, v);
            update(1, 1, N, order[t], order[t], 1, -v);
        }
        else if (type==3) {
            cin >> x >> v;
            update(1, 1, N, order[x], order[x]+sz[x]-1, v, 0);
            //for (int i=1; i<=N; i++) cout << tree_query(i, i) << endl;
        }
        else if (type==4) {
            cin >> x >> y >> v;
            t=lca(x, y);
            temp=query(1, 1, N, order[t], order[t]);
            tree_update(x, t, v, 0);
            update(1, 1, N, order[t], order[t], 1, -(v-1)*temp);
            tree_update(y, t, v, 0);
        }
        else if (type==5) {
            cin >> x;
            cout << query(1, 1, N, order[x], order[x]+sz[x]-1) << "\n";
        }
        else {
            cin >> x >> y;
            t=lca(x, y);
            ans=tree_query(x, t)+tree_query(y, t)-query(1, 1, N, order[t], order[t]);
            cout << ans << "\n";
            ans=0;
        }
    }
}
/*
4 7
1 2
2 3
2 4
1 1 1
4 3 4 1000000000
4 3 1 1000000000
5 1
6 2 2 
6 3 4
6 1 1

answer:
3321730048
2808348672
2321730048
1000000000
*/