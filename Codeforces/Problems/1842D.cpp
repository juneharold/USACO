#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
#define f first
#define s second

ll dist[105]={};
vector<pair<ll, ll>> graph[105];

int main()
{
    ll n, m; cin >> n >> m;
    for (ll i=0; i<m; i++) {
        ll u, v, y; cin >> u >> v >> y;
        graph[u].push_back({v, y});
        graph[v].push_back({u, y});
    }
    fill(&dist[0], &dist[n+1], 1e18);
    dist[1]=0;
    priority_queue<pair<ll, ll>> pq; 
    pq.push({0, 1});
    while (!pq.empty()) {
        ll d=-pq.top().f, cur=pq.top().s; 
        pq.pop();
        if (dist[cur]<d) continue;
        for (ll i=0; i<graph[cur].size(); i++) {
            ll nx=graph[cur][i].f, nd=graph[cur][i].s;
            if (d+nd<dist[nx]) {
                dist[nx]=d+nd;
                pq.push({-(d+nd), nx});
            }
        }
    }

    if (dist[n]==1e18) {
        cout << "inf";
        exit(0);
    }
    string ans="";
    vector<pair<ll, ll>> v;
    for (ll i=2; i<=n; i++) {
        ans+="0";
        v.push_back({dist[i], i});
    }
    ans+="0";
    sort(v.begin(), v.end());
    vector<pair<string, ll>> out;
    ans[0]='1';
    ll time=0;
    for (auto x: v) {
        if (x.f-time>0) out.push_back({ans, x.f-time});
        ans[x.s-1]='1';
        time=x.f;
        if (x.s==n) break;
    }
    cout << time << ' ' << out.size() << "\n";
    for (auto x: out) cout << x.f << ' ' << x.s << "\n";
}