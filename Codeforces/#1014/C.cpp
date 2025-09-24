#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> odds, evens;
    for (ll i=1; i<=n; i++) {
        if (a[i]%2) odds.push_back(a[i]);
        else evens.push_back(a[i]);
    }
    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end());

    if (odds.size()==n) {
        cout << odds.back() << "\n";
        return;
    }
    if (evens.size()==n) {
        cout << evens.back() << "\n";
        return;
    }
    
    ll ans=evens.back();
    evens.pop_back();
    for (ll i=0; i<odds.size(); i++) {
        ans+=odds[i]-1;
        odds[i]=1;
    }

    while (!odds.empty() && !evens.empty()) {
        int val=evens.back()+odds.back();
        ans+=val-1;
        evens.pop_back(); 
        odds.pop_back();
        odds.push_back(1);
    }
    while (true) {
        bool do_ops=false;
        if (ans%2==0 && !odds.empty()) {
            do_ops=true;
            ans+=odds.back();
            odds.pop_back();
        }
        if (ans%2 && !evens.empty()) {
            do_ops=true;
            ans+=evens.back();
            evens.pop_back();
        }
        if (!do_ops) break;
    }

    cout << ans << "\n";
}
/*
5
10 11 2 1 2
ans: 26

5
2 11 13 17 21
ans: 61
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
