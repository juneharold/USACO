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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll N, Q, A[nmax]; 

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

ll num_factors(ll x) {
    ll ret=1;
    while (x>1) {
        int div=minfactor[x], cnt=0;
        while (x%div==0) {
            x/=div;
            cnt++;
        }
        ret*=(cnt+1);
    }
    return ret;
}

ll segtree1[4*nmax]={};
ll query1(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree1[n];
    ll mid=(a+b)/2;
    return query1(2*n, a, mid, qa, qb)+query1(2*n+1, mid+1, b, qa, qb);
}
void update1(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree1[n]=v; return; }
    ll mid=(a+b)/2;
    update1(2*n, a, mid, qa, qb, v);
    update1(2*n+1, mid+1, b, qa, qb, v);
    segtree1[n]=segtree1[2*n]+segtree1[2*n+1];
}

ll segtree2[4*nmax]={};
void update2(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb && segtree2[n]) return;
    if (qa<=a && b<=qb && a==b) {
        ll x=num_factors(A[a]);
        update1(1, 1, N, a, a, x);
        A[a]=x;
        if (x==1 || x==2) segtree2[n]=1;
        return;
    }
    ll mid=(a+b)/2;
    update2(2*n, a, mid, qa, qb);
    update2(2*n+1, mid+1, b, qa, qb);
    segtree2[n]=segtree2[2*n]&segtree2[2*n+1];
}

void solve() {
    linear_sieve(1e6);
    cin >> N >> Q;
    for (ll i=1; i<=N; i++) {
        cin >> A[i];
        update1(1, 1, N, i, i, A[i]);
    }

    while (Q--) {
        ll type, s, e; cin >> type >> s >> e;
        if (type==1) {
            update2(1, 1, N, s, e);
        }
        else {
            cout << query1(1, 1, N, s, e) << "\n";
        }
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
