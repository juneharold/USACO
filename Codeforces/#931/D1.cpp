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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

bool check1left(ll x, ll pos) {
    for (ll i=pos+1; i<63; i++) {
        if (x&(1LL<<i)) return true;
    }
    return false;
}

void solve() {
    ll x, m; cin >> x >> m;
    ll c01=0, c10=0;
    vector<ll> path;
    path.push_back(x);
    for (ll i=0; i<63; i++) {
        if ((x&(1LL<<i)) && (m&(1LL<<i))==0) c10+=(1LL<<i);
        else if ((x&(1LL<<i))==0 && (m&(1LL<<i))) c01+=(1LL<<i);
        //cout << c01 << ' ' << c10 << endl;
        if (c01==c10) continue;
        if (c01>c10 && !check1left(x, i)) {
            x=x-c10+c01;
            path.push_back(x);
            c01=0, c10=0;
        }
        else if (c01<c10 && c01+c10<x) {
            //cout << "here\n";
            x=x-c10+c01;
            path.push_back(x);
            c01=0, c10=0;
        }
    }
    if (x!=m) {
        cout << "-1\n";
        return;
    }
    cout << path.size()-1 << "\n";
    for (ll a: path) cout << a << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
