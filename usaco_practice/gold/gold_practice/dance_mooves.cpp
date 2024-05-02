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

ll nx[nmax]={}, vst[nmax]={}, sz=0;
set<pii> s[nmax];
ll ans[nmax]={};

void solve() {
    ll N, K, M; cin >> N >> K >> M;
    vector<ll> c(N+1);
    for (ll i=1; i<=N; i++) {
        c[i]=i;
        s[i].insert({i, 0});
    }
    for (ll i=1; i<=K; i++) {
        ll a, b; cin >> a >> b;
        s[c[a]].insert({b, i});
        s[c[b]].insert({a, i});
        swap(c[a], c[b]);
    }
    for (ll i=1; i<=N; i++) nx[c[i]]=i;

    if (M<=K) {
        for (ll i=1; i<=N; i++) {
            set<ll> temp;
            for (auto e: s[i]) if (e.sc<=M) temp.insert(e.fs);
            cout << temp.size() << "\n";
        }
        return;
    }

    for (ll i=1; i<=N; i++) {
        if (vst[i]==0) {
            ll x=i, y=i, sz1=1, sz2=M/K, rem=M%K;
            set<ll> active;
            multiset<ll> ms;
            for (auto e: s[x]) {
                active.insert(e.fs);
                ms.insert(e.fs);
            }
            bool special=false;
            while (sz1<sz2) {
                if (nx[y]==x) {
                    special=true;
                    break;
                }
                y=nx[y];
                for (auto e: s[y]) {
                    active.insert(e.fs);
                    ms.insert(e.fs);
                }
                sz1++;
            }

            while (vst[x]==0) {
                vst[x]=1;
                // take rem at nx[y]
                ans[x]=active.size();
                if (special) {
                    x=nx[x];
                    continue;
                }

                y=nx[y];
                set<ll> checked;
                for (auto e: s[y]) {
                    if (e.sc<=rem && active.find(e.fs)==active.end() && checked.find(e.fs)==checked.end()) {
                        ans[x]++;
                        checked.insert(e.fs);
                    }
                }
                for (auto e: s[x]) {
                    ms.erase(ms.find(e.fs));
                    if (ms.find(e.fs)==ms.end()) active.erase(e.fs);
                }
                for (auto e: s[y]) {
                    active.insert(e.fs);
                    ms.insert(e.fs);
                }
                x=nx[x];
            }
        }
    }

    for (ll i=1; i<=N; i++) cout << ans[i] << "\n";
}
/*
5 9 24
3 4
1 2
2 4
2 3
2 3
3 4
1 2
2 4
2 5

Your output:
4 5 4 5 6 
Solution output:
4 5 4 5 5 

5 5 9
3 5
3 5
1 4
3 5
3 4
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
