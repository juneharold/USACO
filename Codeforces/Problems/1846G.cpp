#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define f first
#define s second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll n, m, dist[1<<10]={}, day[1005]={};
string cure[1005]={}, side[1005]={};

void solve() {
    cin >> n >> m;
    ll start=0;
    for (ll i=0; i<n; i++) {
        char c; cin >> c;
        if (c=='1') start+=(1<<i);
    }
    for (ll i=1; i<=m; i++) cin >> day[i] >> cure[i] >> side[i];
    fill(&dist[0], &dist[1<<n], 1e9);
    dist[start]=0;
    priority_queue<pii> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur=pq.top().s, d=-pq.top().f;
        pq.pop();
        if (d>dist[cur]) continue;
        for (int i=1; i<=m; i++) {
            int nx=cur;
            for (ll j=0; j<n; j++) {
                if (cure[i][j]=='1' && (1<<j)&cur) nx-=(1<<j);
                if (side[i][j]=='1' && !((1<<j)&cur)) nx+=(1<<j); 
            }
            if (d+day[i]<dist[nx]) {
                dist[nx]=d+day[i];
                pq.push({-dist[nx], nx});
            }
        }
    }

    if (dist[0]==1e9) cout << "-1\n";
    else cout << dist[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
