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
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1, 0);
    for (ll i=1; i<=n; i++) cin >> a[i];

    map<ll, ll> m;
    vector<ll> b(n+1, 0);
    ll mad=0, ans=0; 
    for (ll i=1; i<=n; i++) {
        ans+=a[i];
        m[a[i]]++;
        if (m[a[i]]>1 && mad<a[i]) mad=a[i];
        b[i]=mad;
    }

    /*for (ll i=1; i<=n; i++) cout << b[i] << ' ' ;
    cout << endl;*/

    ll cnt=1, added=0;
    for (ll i=n-1; i>=1; i--) {
        if (b[i]!=b[i+1]) {
            if (cnt>1) {
                ans+=((n-i)*(n-i+1)/2-added)*b[i+1];
                added=(n-i)*(n-i+1)/2;
            }
            else {
                ans+=b[i+1];
                added++;
            }
            cnt=1;
        }
        else cnt++;
        //cout << ans << endl;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
