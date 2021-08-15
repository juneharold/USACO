#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second

const int MAX=1e5+5;
int N, Q, parent[MAX]={}, sz[MAX]={}, ans[MAX]={};

struct edge { int u, v, w; };
vector<edge> edges;
struct query {int num, v, k; };
vector<query> queries;

bool cmp (query a, query b) {
    return a.k > b.k;
}
bool cmp2 (edge a, edge b) {
    return a.w > b.w;
}

int Find (int x) {
    if (parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}

void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    if (sz[a] > sz[b]) swap(a, b);
    parent[a] = b;
    sz[b]+=sz[a];
}


int main()
{
    cin >> N >> Q;
    for (int i=1; i<=N-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    for (int i=1; i<=Q; i++) {
        int v, k; cin >> k >> v;
        queries.push_back({i, v, k});
    }

    sort(queries.begin(), queries.end(), cmp);
    sort (edges.begin(), edges.end(), cmp2);

    for (int i=1; i<=N; i++) {
        parent[i]=i;
        sz[i]=1;
    }

    int idx=0;
    for (auto q: queries) {
        while (idx<edges.size() && edges[idx].w >= q.k) {
            Union(edges[idx].u, edges[idx].v);
			idx++;
		}
        int f=Find(q.v);
        ans[q.num]=sz[f]-1;
    }

    for (int i=1; i<=Q; i++) {
        cout << ans[i] << "\n";
    }
}
