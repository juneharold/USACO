#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

// Cannot name variables: nmax, sqrmax, MOD, INF, isprime, primes, minfactor, parent, sz
ll n, m, dist[1005][1005]={}, s[1005]={};
vector<pii> graph[1005];

void solve() {
    cin >> n >> m;
    for (ll i=1; i<=m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    for (ll i=1; i<=n; i++) cin >> s[i];
    fill(&dist[0][0], &dist[n+1][n+1], 1e18);
    dist[1][1]=0;
    priority_queue<pair<ll, pii>> pq;
    pq.push({-dist[1][1], {1, 1}});
    while (!pq.empty()) {
        ll d=-pq.top().fs, bike=pq.top().sc.fs, cur=pq.top().sc.sc;
        pq.pop();
        if (d>dist[cur][bike]) continue;
        for (ll i=0; i<graph[cur].size(); i++) {
            ll nx=graph[cur][i].fs, w=graph[cur][i].sc;
            if (s[bike]<s[nx] && d+w*s[bike]<dist[nx][bike]) {
                dist[nx][bike]=d+w*s[bike];
                pq.push({-dist[nx][bike], {bike, nx}});
            }
            else if (s[nx]<=s[bike] && d+w*s[bike]<dist[nx][nx]) {
                dist[nx][nx]=d+w*s[bike];
                pq.push({-dist[nx][nx], {nx, nx}});
            }
        }
    }
    ll ans=1e18;
    for (ll i=1; i<=n; i++) ans=min(ans, dist[n][i]);
    cout << ans << "\n";

    for (ll i=1; i<=n; i++) {
        graph[i].clear();
        s[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
