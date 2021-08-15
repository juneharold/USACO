#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
const int MAX=2005;
ll N, id[MAX], ans=0;
map<ll, ll> p, sz;

struct edge {ll a, b, w;};
vector<edge> edges;

bool cmp (edge a, edge b) {return a.w>b.w;}

int Find(ll x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}
void Union (ll a, ll b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = b;
    sz[b] += sz[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> id[i];
        p[id[i]]=id[i];
        sz[id[i]]=1;
    }

    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            ll weight=(id[i]^id[j]);
            edges.push_back({id[i], id[j], weight});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    int choose=0;
    for (auto e: edges) {
        ll cur=e.a, nx=e.b;
        if (Find(cur)==Find(nx)) continue;
        Union(cur, nx);
        ans+=e.w;
        choose++;
        if (choose==N-1) break;
    }
    cout << ans;
}
