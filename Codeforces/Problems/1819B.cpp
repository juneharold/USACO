#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define f first
#define s second

void solve() {
    ll n; cin >> n;
    vector<ll> used(n+1, 0);
    set<pair<ll, ll>> ans;
    map<ll, vector<pair<ll, ll>>> box1, box2;
    ll area=0, h0=0, w0=0;
    for (ll i=1; i<=n; i++) {
        ll a, b; cin >> a >> b;
        box1[a].push_back({b, i});
        box2[b].push_back({a, i});
        h0=max(h0, a), w0=max(w0, b);
        area+=a*b;
    }
    
    ll h=h0, w=(area%h0 ? 0 : area/h0);
    while (h>0 && w>0) {
        int befh=h, befw=w;
        for (ll i=0; i<box1[h].size(); i++) {
            if (!used[box1[h][i].s]) {
                w-=box1[h][i].f;
                used[box1[h][i].s]=1;
            }
        }
        for (ll i=0; i<box2[w].size(); i++) {
            if (!used[box2[w][i].s]) {
                h-=box2[w][i].f;
                used[box2[w][i].s]=1;
            }
        }
        if (befh==h && befw==w) break;
    }
    ll possible=true;
    for (ll i=1; i<=n; i++) {
        if (used[i]!=1) possible=false;
        used[i]=0;
    }
    if (possible) ans.insert({h0, area/h0});

    h=(area%w0 ? 0 : area/w0), w=w0;
    while (h>0 && w>0) {
        int befh=h, befw=w;
        for (ll i=0; i<box2[w].size(); i++) {
            if (!used[box2[w][i].s]) {
                h-=box2[w][i].f;
                used[box2[w][i].s]=1;
            }
        }
        for (ll i=0; i<box1[h].size(); i++) {
            if (!used[box1[h][i].s]) {
                w-=box1[h][i].f;
                used[box1[h][i].s]=1;
            }
        }
        if (befh==h && befw==w) break;
    }
    possible=true;
    for (ll i=1; i<=n; i++) if (used[i]!=1) possible=false;
    if (possible) ans.insert({area/w0, w0});

    cout << ans.size() << "\n";
    for (auto x: ans) cout << x.f << ' ' << x.s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
