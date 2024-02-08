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

/*
to make answer from x to x+(1<<b) 
if x is not a submask of a[i], need (1<<b) for a[i] to turn on b-th bbit
if x+(1<<b) is a submask of a[i], then don't need anything 
if x is a submask of a[i] but not a submask of x+(1<<b), then need (1<<b)-a[i]%(1<<b)

use two dp arrays calculated using SOS:
dp1[i]=number of a[i] that is a subset of i 
dp2[i][b]=sum of a[i]%(1<<b) for a[i] that is subset of i

Now the cost to make answer from x to x+(1<<b) is 
(n-dp1[x])*(1<<b)+(dp1[x]-dp1[x+(1<<b)])*(1<<b)-dp2[x][b]
*/

ll cnt[1<<21]={}, dp1[1<<21]={}, dp2[1<<21][21]={};

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n+1);
    ll sum=0;
    for (ll i=1; i<=n; i++) {
        cin >> a[i];
        sum+=a[i];
        dp1[a[i]]++;
        ll temp=0;
        for (int k=0; k<20; k++) {
            temp+=a[i]&(1LL<<k);
            dp2[a[i]][k]+=temp;
        }
    }

    for (ll j=0; j<20; j++) {
        for (ll i=0; i<(1<<20); i++) {
            if ((i&(1<<j))==0) dp1[i]+=dp1[i+(1<<j)];
        }
    }

    for (ll j=0; j<20; j++) {
        for (ll i=0; i<(1<<20); i++) {
            for (ll k=0; k<20; k++) {
                if ((i&(1<<j))==0) dp2[i][k]+=dp2[i+(1<<j)][k];
            }
        }
    }

    while (q--) {
        ll k; cin >> k;
        if (k>=n*(1LL<<20)-sum) {
            cout << (k+sum)/n << "\n";
            continue;
        }

        ll ans=0;
        for (ll i=19; i>=0; i--) {
            ll cost=(n-dp1[ans|(1<<i)])*(1LL<<i)-dp2[ans][i]+dp2[ans|(1<<i)][i];
            if (k>=cost) {
                ans+=(1<<i);
                k-=cost;
            }
        }
        cout << ans << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
