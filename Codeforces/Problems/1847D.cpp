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
typedef pair<int, int> pii;
#define f first
#define s second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll fastpow (ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        exponent/=2;
    }
    return ret;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    string st; cin >> st;
    set<int> S; 
    vector<int> pos(n, -1), order;
    for (int i=0; i<n; i++) S.insert(i);
    int idx=0;
    for (int i=0; i<m; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        auto it=S.lower_bound(l);
        vector<int> to_erase;
        while (it!=S.end() && *it<=r) {
            pos[*it]=idx++;
            order.push_back(*it);
            to_erase.push_back(*it);
            it++;
        }
        for (int x: to_erase) S.erase(x);
    }

    int cnt=0;
    for (int i=0; i<n; i++) if (st[i]=='1') cnt++;
    int ans=0;
    for (int i=0; i<min(cnt, idx); i++) if (st[order[i]]=='0') ans++;

    while (q--) {
        int x; cin >> x;
        x--;
        if (pos[x]!=-1 && pos[x]<cnt) {
            if (st[x]=='0') ans--;
            else ans++;
        }
        if (st[x]=='0') {
            st[x]='1';
            cnt++;
            if (cnt<=idx && st[order[cnt-1]]=='0') ans++;
        }
        else {
            st[x]='0';
            if (cnt>0 && cnt<=idx && st[order[cnt-1]]=='0') ans--;
            cnt--;
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1;// cin >> T;
    while (T--) {
        solve();
    }
}
