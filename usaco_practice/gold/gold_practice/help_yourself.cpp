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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

void solve() {
    int N; cin >> N;
    vector<pii> v(N+1);
    for (int i=1; i<=N; i++) cin >> v[i].fs >> v[i].sc;
    vector<ll> pfs(2*N+5, 0);
    for (int i=1; i<=N; i++) pfs[v[i].fs+1]++, pfs[v[i].sc+1]--;
    for (int i=1; i<=2*N; i++) pfs[i]+=pfs[i-1];

    /*for (int i=1; i<=2*N; i++) cout << pfs[i] << ' ';
    cout << endl;*/

    ll ans=0;
    for (int i=1; i<=N; i++) {
        ans+=fastpow(2, N-1-pfs[v[i].fs]);
        ans%=MOD;
    }
    cout << ans;
}

int main()
{
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
