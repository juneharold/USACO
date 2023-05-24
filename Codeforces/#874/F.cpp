#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

ll a[200005]={}, b[200005]={}, p[200005]={};

ll fermat(ll a) { //returns a^(1e9+7-2)
    ll ret=1, exponent=MOD-2;
    while (exponent) {
        if (exponent%2) {
            ret*=a;
            ret%=MOD;
        }
        a*=a;
        a%=MOD;
        exponent/=2;
    }
    return ret%MOD;
}

int main() 
{
    ll T; cin >> T;
    vector<int> out;
    while (T--) {
        ll n, m; cin >> n >> m;
        map<ll, ll> level;
        for (ll i=1; i<=n; i++) {
            ll x; cin >> x;
            a[i]=x;
            level[x]++;
        }
        sort(&a[1], &a[n+1]);
        ll idx=0;
        for (ll i=1; i<=n; i++) {
            if (a[i]!=a[i-1]) {
                idx++;
                b[idx]=a[i];
            }
        }

        p[0]=1;
        for (int i=1; i<=idx; i++) {
            p[i]=level[b[i]]*p[i-1];
            p[i]%=MOD;
        }

        ll l=1, ans=0;
        while (l<=idx) {
            ll r=l+m-1;
            if (b[r]-b[l]==m-1) {
                ans+=p[r]*fermat(p[l-1]);
                ans%=MOD;
            }
            l++;
        }

        out.push_back(ans);

        fill(&a[1], &a[n+1], 0);
        fill(&b[1], &b[n+1], 0);
        fill(&p[1], &p[n+1], 0);
        level.clear();
    }

    for (int x: out) cout << x << "\n";
}
