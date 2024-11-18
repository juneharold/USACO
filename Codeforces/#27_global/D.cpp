#include <bits/stdc++.h>
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
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    vector<ll> b(n+1), cnt(n+1, 0);
    for (ll i=1; i<=n; i++) {
        b[i]=a[i];
        while (b[i]%2==0) {
            b[i]/=2;
            cnt[i]++;
        }
    }


    priority_queue<pair<ll, ll>> pq;
    vector<ll> Ans(n+1);
    ll ans=0;
    //cout << 27582366232LL%MOD << endl;
    //for (int i=1; i<=n; i++) cout << b[i] << ' ' << cnt[i] << endl;
    for (ll i=1; i<=n; i++) {
        while (!pq.empty() && -pq.top().fs<=b[i]*min(INF/b[i], fastpow(2, cnt[i]))) {
            pair<ll, ll> cur=pq.top(); pq.pop();
            cur.fs=-cur.fs;
            ans=ans-(cur.fs*fastpow(2, cur.sc))%MOD+cur.fs+MOD;
            ans%=MOD;
            cnt[i]+=cur.sc;
        }
        ans+=b[i]*fastpow(2, cnt[i])%MOD;
        ans%=MOD;
        pq.push({-b[i], cnt[i]});
        Ans[i]=ans;
    }
    for (ll i=1; i<=n; i++) cout << Ans[i] << ' ';
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
