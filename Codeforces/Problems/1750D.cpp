#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

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


void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n+1);
    for (ll i=1; i<=n; i++) cin >> a[i];

    ll ans=1;
    for (ll i=2; i<=n; i++) {
        ll res=m/a[i], x=a[i-1]/a[i];
        if (x==0 || a[i-1]%a[i]!=0) {
            cout << "0\n";
            return;
        }
        vector<ll> v;
        for (ll p: primes) {
            if (p>x) continue;
            if (x%p==0) {
                v.push_back(p);
                while (x%p==0) {
                    x/=p;
                }
            }
        }
        if (x>1) v.push_back(x);
        for (ll j=1; j<(1<<v.size()); j++) {
            ll temp=1, cnt=0;
            for (ll k=0; k<v.size(); k++) {
                if (j&(1<<k)) temp*=v[k], cnt++;
            }
            if (cnt%2) res-=(m/a[i])/temp;
            else res+=(m/a[i])/temp;
        }
        ans=ans*res%MOD;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve(1e5);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
