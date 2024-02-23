#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<ll> graph[nmax];

pair<ll, pii> euclid(ll a, ll b) {
    if (a<b) swap(a, b);
    if (b==0) return {a, {1, 0}};
    auto res=euclid(b, a%b);
    ll g=res.fs, x1=res.sc.fs, y1=res.sc.sc;
    return {g, {y1, x1-y1*(a/b)}};
}

ll find_nd(ll li, ll lj, ll si, ll sj, ll H) {
    if (li==lj) return 0;
    else if ((lj-li)%gcd(si-sj, H)!=0 || (li!=lj && si==sj)) return INF;
    auto res=euclid(H, abs(si-sj));
    ll y0=res.sc.sc*(lj-li)/res.fs;
    if (si-sj<0) y0=-y0;
    if (y0<0) y0+=(H/res.fs)*(-y0/(H/res.fs)+1);
    if (y0-H/res.fs>0) y0-=(H/res.fs)*(y0/(H/res.fs));
    return y0;
}

void solve() {
    ll n, m, H; cin >> n >> m >> H;
    vector<ll> l(n+1), s(n+1);
    for (ll i=1; i<=n; i++) cin >> l[i];
    for (ll i=1; i<=n; i++) cin >> s[i];

    for (ll i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> d(n+1, INF);
    priority_queue<pii> pq;
    pq.push({0, 1});
    d[1]=0;
    while (!pq.empty()) {
        ll dist=-pq.top().fs, cur=pq.top().sc; 
        pq.pop();
        if (dist>d[cur]) continue;
        for (ll nx: graph[cur]) {
            ll cli=(l[cur]+dist%H*s[cur])%H, clj=(l[nx]+dist%H*s[nx])%H;
            ll nd=find_nd(cli, clj, s[cur], s[nx], H)+1;
            if (dist+nd<d[nx]) {
                d[nx]=dist+nd;
                pq.push({-d[nx], nx});
            }
        }
    }

    if (d[n]==INF) cout << "-1\n";
    else cout << d[n] << "\n";

    fill(&d[0], &d[n+1], INF);
    for (int i=1; i<=n; i++) graph[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
