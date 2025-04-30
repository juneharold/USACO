#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<ll> isprime, primes, minfactor;
void linear_sieve(ll sz) {
    for (ll i=0; i<=sz; i++) {
        isprime.push_back((i>1 ? 1:0));
        minfactor.push_back(i);
    }
    for (ll i=2; i<=sz; i++) {
        if (isprime[i]) primes.push_back(i);
        for (ll j: primes) {
            if (i*j>sz) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}

ll pfs[400005]={};

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    sort(&a[1], &a[n+1]);
    ll ans=n-1, sum=0;
    for (ll i=n; i>=1; i--) {
        sum+=a[i];
        if (pfs[n-i+1]<=sum) ans=min(ans, i-1);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve(1e7);
    for (ll i=1; i<=4e5; i++) {
        pfs[i]=pfs[i-1]+primes[i-1];
    }
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
