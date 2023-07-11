#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define f first
#define s second

pair<ll, ll> pos[100005];
ll idx[11]={};
vector<pair<ll, ll>> y[11];
ll p[100005]={}, sz[100005]={};

ll Find(ll x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}

void Union(ll a, ll b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    p[a]=b;
    sz[b]+=sz[a];
}

int main()
{
    ll N; cin >> N;
    for (ll i=1; i<=N; i++) cin >> pos[i].f >> pos[i].s;
    sort(&pos[1], &pos[N+1]);
    for (ll i=1; i<=N; i++) y[pos[i].s].push_back({pos[i].f, i});
    for (ll i=0; i<=10; i++) sort(y[i].begin(), y[i].end());
    
    vector<pair<ll, pair<ll, ll>>> edge;
    for (ll i=1; i<=N; i++) {
        for (ll j=0; j<=10; j++) {
            while (idx[j]<y[j].size() && y[j][idx[j]].f<pos[i].f) {
                idx[j]++;
            }
            if (idx[j]>=y[j].size()) continue;
            ll w=(y[j][idx[j]].f-pos[i].f)*(y[j][idx[j]].f-pos[i].f);
            w+=(j-pos[i].s)*(j-pos[i].s);
            edge.push_back({w, {i, y[j][idx[j]].s}});
            
            int nidx=idx[j]+1;
            if (nidx>=y[j].size()) continue;
            w=(y[j][nidx].f-pos[i].f)*(y[j][nidx].f-pos[i].f);
            w+=(j-pos[i].s)*(j-pos[i].s);
            edge.push_back({w, {i, y[j][nidx].s}});
        }
    }

    sort(edge.begin(), edge.end());
    for (ll i=1; i<=N; i++) {
        p[i]=i;
        sz[i]=1;
    }
    ll cost=0;
    for (auto e: edge) {
        if (Find(e.s.f)!=Find(e.s.s)) {
            cost+=e.f;
            Union(e.s.f, e.s.s);
        }
    }
    cout << cost;
}

/*
4
1 1
1 2
1 3
2 3
*/