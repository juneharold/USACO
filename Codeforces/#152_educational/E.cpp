#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define f first
#define s second
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7;

ll fastpow (ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        exponent/=2;
    }
    return ret;
}
vector<ll> isprime, primes, minfactor;
void linear_sieve() {
    for (ll i=0; i<=2e5; i++) {
        isprime.push_back(1);
        minfactor.push_back(i);
    }
    for (ll i=2; i<=2e5; i++) {
        if (isprime[i]) primes.push_back(i);
        for (ll j: primes) {
            if (i*j>2e5) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}

ll p[nmax], lmax[nmax], rmax[nmax], lmin[nmax], rmin[nmax];

void solve() {
    ll n; cin >> n; 
    for (ll i=1; i<=n; i++) cin >> p[i];
    stack<pii> stk1, stk2;
    stk1.push({1e9, 0});
    stk2.push({-1e9, 0});
    for (ll i=1; i<=n; i++) {
        while (stk1.top().f<p[i]) {stk1.pop();}
        while (stk2.top().f>p[i]) {stk2.pop();}
        lmax[i]=stk1.top().s+1;
        lmin[i]=stk2.top().s+1;
        stk1.push({p[i], i});
        stk2.push({p[i], i});
    }
    while (!stk1.empty()) {stk1.pop();}
    while (!stk2.empty()) {stk2.pop();}
    stk1.push({1e9, n+1});
    stk2.push({-1e9, n+1});
    for (ll i=n; i>=1; i--) {
        while (stk1.top().f<p[i]) {stk1.pop();}
        while (stk2.top().f>p[i]) {stk2.pop();}
        rmax[i]=stk1.top().s-1;
        rmin[i]=stk2.top().s-1;
        stk1.push({p[i], i});
        stk2.push({p[i], i});
    }
    ll ans=0;
    for (ll i=1; i<=n; i++) {
        if (i-lmax[i]+1<rmax[i]-i+1) {
            ll mn=1e9;
            for (ll j=i-1; j>=lmax[i]; j--) {
                mn=min(mn, p[j]);
                if (p[j]==mn) ans+=(j-max(lmax[i], lmin[j])+1)*(min(rmin[j], rmax[i])-i+1);
            }
        }
        else {
            ll mn=1e9, res=0;
            for (ll j=i; j<=rmax[i]; j++) {
                mn=min(mn, p[j]);
                if (p[j]==mn) res+=(i-max(lmax[i], lmin[j])+1)*(min(rmin[j], rmax[i])-j+1);
            }
            ans+=(i-lmax[i]+1)*(rmax[i]-i+1)-res;
        }
    }
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
