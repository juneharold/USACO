#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

ll N, K, L;

vector<pii> graph[nmax];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    ll u, v, w;
    for (ll i=1; i<=N-1; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    if (N>14) {
        cout << "-1\n";
        return 0;
    }

    ll ans=1e18;
    for (ll i=1; i<(1<<N); i++) {
        ll cost=0;
        set<ll> s;
        for (ll j=0; j<N; j++) {
            if ((1<<j)&i) {
                cost+=A[j+1];
                dfs(j+1, j+1, 0);
                for (ll k=1; k<=N; k++) if (vst[k]) s.insert(k);
                fill(&vst[0], &vst[N+1], 0);
            }
        }
        if (s.size()==N) ans=min(ans, cost);
    }
    cout << ans;
}
