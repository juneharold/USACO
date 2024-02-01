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
    ll a, b, r; cin >> a >> b >> r;
    ll ans=abs(a-b);
    for (int i=59; i>=0; i--) {
        if (((1LL<<i)&a)==((1LL<<i)&b)) continue;
        //cout << "i: " << i << endl;
        if ((1LL<<i)&a) {
            ll x=0;
            for (int j=i-1; j>=0; j--) {
                if ((1LL<<j)&b || (((1LL<<j)&a)==((1LL<<j)&b))) continue;
                if (x+(1LL<<j)<=r) x+=(1LL<<j);
            }
            //cout << "1 i: " << i << ' ' << x << ' ' << abs((a^x)-(b^x)) << endl;
            //if (abs(a^x-b^x)==0) cout << "x: " << x << endl;
            ans=min(ans, abs((a^x)-(b^x)));
        }
        else {
            ll x=0;
            for (int j=i-1; j>=0; j--) {
                if ((1LL<<j)&a || (((1LL<<j)&a)==((1LL<<j)&b))) continue;
                if (x+(1LL<<j)<=r) x+=(1LL<<j);
            }
            //cout << "2 i: " << i << ' ' << x << endl;
            //if (abs(a^x-b^x)==0) cout << "x: " << x << endl;
            ans=min(ans, abs((a^x)-(b^x)));
        }
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
