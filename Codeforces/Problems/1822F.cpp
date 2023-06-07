#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second
typedef long long ll;

int main()
{
    ll T; cin >> T;
    while (T--) {
        ll n, k, c; cin >> n >> k >> c;
        vector<vector<ll>> graph(n+1);
        for (ll i=0; i<n-1; i++) {
            ll u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<ll> dist1(n+1, 1e9);
        priority_queue<pair<ll, ll>> pq;
        pq.push(make_pair((ll)0, (ll)1));
        dist1[1]=0;
        while (!pq.empty()) {
            ll d=-pq.top().f, cur=pq.top().s;
            pq.pop();
            if (d>dist1[cur]) continue;
            for (ll i=0; i<graph[cur].size(); i++) {
                ll nx=graph[cur][i];
                if (dist1[cur]+1<dist1[nx]) {
                    dist1[nx]=dist1[cur]+1;
                    pq.push(make_pair(-(dist1[cur]+1), nx));
                }
            }
        }

        ll a=0, mx=0;
        for (ll i=1; i<=n; i++) {
            if (dist1[i]>mx) {
                a=i;
                mx=dist1[i];
            }
        }
        if (c>=k) {
            cout << mx*k*1LL << "\n";
            continue;
        }

        vector<ll> dist2(n+1, 1e9);
        pq.push(make_pair((ll)0, (ll)a));
        dist2[a]=0;
        while (!pq.empty()) {
            ll d=-pq.top().f, cur=pq.top().s;
            pq.pop();
            if (d>dist2[cur]) continue;
            for (ll i=0; i<graph[cur].size(); i++) {
                ll nx=graph[cur][i];
                if (dist2[cur]+1<dist2[nx]) {
                    dist2[nx]=dist2[cur]+1;
                    pq.push(make_pair(-(dist2[cur]+1), nx));
                }
            }
        }
        
        ll b=0; mx=0;
        for (ll i=1; i<=n; i++) {
            if (dist2[i]>mx) {
                b=i;
                mx=dist2[i];
            }
        }

        ll ans=0;
        for (int j=1; j<=n; j++) {
            ans=max(ans, dist2[j]*k*1LL-abs(dist1[1]-dist1[j])*c*1LL);
        }
        cout << ans << "\n";
    }
}

/*
1
10 6 4
1 3
1 9
9 7
7 6
6 4
9 2
2 8
8 5
5 10
*/