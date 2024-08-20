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

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
        }
        x*=x;
        y/=2;
    }
    return ret;
}

vector<ll> v;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> ans;
    while (k>0) {
        for (int i=v.size()-1; i>=0; i--) {
            if (k-v[i]>=0) {
                ans.push_back(v[i]);
                k-=v[i];
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for (ll x: ans) cout << x << ' ';
    cout << "\n";
}

int main()
{
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=17; j++) {
            ll temp=0;
            for (int k=1; k<=j; k++) {
                temp+=i*fastpow(10, k-1);
            }
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end());
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
