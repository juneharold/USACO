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
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n, k, q; cin >> n >> k >> q;
        vector<ll> a(n+1, 0);
        for (ll i=1; i<=n; i++) cin >> a[i];
        ll ans=0;
        ll cnt=0;
        for (ll i=1; i<=n; i++) {
            if (a[i]<=q) cnt++;
            else {
                if (cnt-k+1>0) ans+=(cnt-k+1)*(cnt-k+2)/2;
                cnt=0;
            }
        }
        if (cnt-k+1>0) ans+=(cnt-k+1)*(cnt-k+2)/2;
        cout << ans << "\n";
    }
}
