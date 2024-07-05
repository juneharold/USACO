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
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll a[nmax], b[nmax], c[nmax];
ll bef[nmax], dp[nmax]={};

void solve() {
    ll n, m; cin >> n >> m;
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<=n; i++) cin >> b[i];
    for (ll i=1; i<=m; i++) cin >> c[i];

    vector<pair<ll, pii>> v;
    for (ll i=1; i<=n; i++) v.push_back({a[i]-b[i], {a[i], b[i]}});
    sort(v.begin(), v.end());

    ll prev=1e9;
    fill(&bef[0], &bef[1000001], -1);
    for (ll i=0; i<v.size(); i++) {
        if (i==0 || (v[i].fs>v[i-1].fs && v[i].sc.fs<prev)) {
            bef[v[i].sc.fs]=v[i].fs;
            prev=v[i].sc.fs;
        }
    }
    for (ll i=1; i<=1000000; i++) if (bef[i]==-1) bef[i]=bef[i-1];

    for (ll i=1; i<=1000000; i++) {
        dp[i]=dp[i-1];
        if (bef[i]!=-1 && i-bef[i]>=0) dp[i]=max(dp[i], dp[i-bef[i]]+2);
    }

    ll ans=0;
    for (ll i=1; i<=m; i++) {
        ll cnt=0;
        if (c[i]>1000000LL) {
            cnt=(c[i]-1000000LL)/v[0].fs;
            if (c[i]-cnt*v[0].fs>1000000LL) cnt++;
            c[i]-=cnt*v[0].fs;
        }
        //cout << cnt << endl;
        ans+=cnt*2+dp[c[i]];
    }
    //for (int i=1; i<=10; i++) cout << bef[i] << ' ';
    //cout << endl;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
