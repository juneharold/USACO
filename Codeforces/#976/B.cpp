#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll k; cin >> k;
    ll lo=1, hi=2e18;
    while (lo<hi) {
        ll mid=(lo+hi)/2LL;
        ll temp=sqrt((long double)mid);
        if (mid-temp>=k) hi=mid;
        else lo=mid+1;
    }
    ll x=sqrt(lo);
    if (x*x==lo) lo--;
    cout << lo << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
