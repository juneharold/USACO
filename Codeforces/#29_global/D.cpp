#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+5);
    for (ll i=1; i<=n; i++) cin >> a[i];

    map<ll, ll> cnt;
    for (ll i=1; i<=n; i++) cnt[a[i]]++;

    ll alice=0, bob=0;
    vector<pii> odds;
    for (auto x: cnt) {
        if (x.fs%2) odds.push_back({x.sc, x.fs});
        else {
            alice+=(x.fs/2)*x.sc;
            bob+=(x.fs/2)*x.sc;
        }
    }
    sort(odds.begin(), odds.end());
    reverse(odds.begin(), odds.end());

    ll turn=0;
    for (ll i=0; i<odds.size(); i++) {
        if (i%2==0) {
            alice+=((odds[i].sc+1)/2)*odds[i].fs;
            bob+=(odds[i].sc/2)*odds[i].fs;
        }
        else {
            bob+=((odds[i].sc+1)/2)*odds[i].fs;
            alice+=(odds[i].sc/2)*odds[i].fs;
        }
    }
    cout << alice << ' ' << bob << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
/*
counterexample:
3
1 2 2

my output:
2 3

correct output:
3 2
*/