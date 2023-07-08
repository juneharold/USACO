#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll nmax=100001;
#define f first
#define s second

ll N, depth[nmax]={}, p[nmax][20]={}, cost[nmax]={};
vector<pair<ll, ll>> graph[nmax];

void dfs(ll cur, ll parent) {
    for (auto nx: graph[cur]) {
        if (nx.f==parent) continue;
        depth[nx.f]=depth[cur]+1;
        p[nx.f][0]=cur;
        cost[nx.f]=cost[cur]+nx.s;
        dfs(nx.f, cur);
    }
}

int LCA(ll u, ll v) {
    if (depth[u]<depth[v]) swap(u, v);
    for (ll i=19; i>=0; i--) {
        if (p[u][i]==-1) continue;
        if (depth[v]<=depth[p[u][i]]) u=p[u][i];
    }
    if (u==v) return u;
    for (ll i=19; i>=0; i--) {
        if (p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}

void query1() {
    ll u, v; cin >> u >> v;
    cout << cost[u]+cost[v]-2*cost[LCA(u, v)] << "\n";
}

void query2() {
    ll u, v, k; cin >> u >> v >> k;
    ll x=LCA(u, v);
    if (k<=depth[u]-depth[x]+1) {
        k--;
        for (ll i=19; i>=0 && k>0; i--) {
            if (k&(1<<i)) {
                u=p[u][i];
                k-=(1<<i);
            }
        }
        cout << u << "\n";
    }
    else {
        k-=(depth[u]-depth[x]+1);
        k=depth[v]-depth[x]-k;
        for (ll i=19; i>=0 && k>0; i--) {
            if (k&(1<<i)) {
                v=p[v][i];
                k-=(1<<i);
            }
        }
        cout << v << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (ll i=0; i<N-1; i++) {
        ll u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    fill(&p[0][0], &p[N][20], -1);
    fill(&depth[0], &depth[N+1], -1);
    depth[1]=0;
    dfs(1, 0);
    for (ll j=1; j<20; j++) {
        for (ll i=2; i<=N; i++) {
            if (p[i][j-1]<1) continue;
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }

    ll M; cin >> M;
    while (M--) {
        ll type; cin >> type;
        if (type==1) query1();
        else query2();
    }
}