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
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=3e5+5, sqrmax=635, MOD=998244353;

pair<ll, ll> llerval[nmax];
ll c[nmax]={}, diff[nmax]={}; // c[n]=1/(n+1)*nCr(2n, n);
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rnd(0, __LONG_LONG_MAX__);

ll fastpow(ll x, ll y) {
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

void catalan() {
    c[1]=1;
    for (ll i=1; i<300000; i++) {
        c[i+1]=c[i]*2*(2*i+1);
        c[i+1]%=MOD;
        c[i+1]*=fastpow(i+2, MOD-2);
        c[i+1]%=MOD;
    }
}

map<ll, ll> groups;

int main()
{
    catalan();
    vector<ll> out;
    ll T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        ll hash=rnd(gen);
        diff[1]^=hash;
        diff[n+1]^=hash;
        for (ll i=1; i<=k; i++) {
            cin >> llerval[i].f >> llerval[i].s;
            hash=rnd(gen);
            diff[llerval[i].f]^=hash;
            diff[llerval[i].s+1]^=hash;
        }
        for (ll i=1; i<=n; i++) {
            diff[i]=diff[i]^diff[i-1];
            groups[diff[i]]++;
        }

        ll ans=1;
        bool possible=1;
        for (auto group: groups) {
            if (group.s%2) possible=0;
            ans*=c[group.s/2];
            ans%=MOD;
        }
        if (possible) out.push_back(ans);
        else out.push_back(0);

        groups.clear();
        fill(&llerval[1], &llerval[n+1], make_pair(0, 0));
        fill(&diff[0], &diff[n+2], 0);
    }
    for (ll x: out) cout << x << "\n";
}
