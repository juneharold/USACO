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
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;
 
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
 
ll lsb(ll x) {
    int ret=1e9;
    for (int i=0; i<=30; i++) {
        if (x&(1<<i)) ret=min(ret, i);
    }
    return ret;
}
 
string tobinary(ll x) {
    string ret="";
    while (x) {
        if (x%2) ret+="1";
        else ret+="0";
        x/=2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve() {
    ll a, b, d; cin >> a >> b >> d;
    if (min(lsb(a), lsb(b))<lsb(d)) {
        cout << "-1\n";
        return;
    }
    ll x=0;
    for (ll i=0; i<30; i++) {
        if ((x&(1<<i))==0 && i-lsb(d)>=0) x+=d*(1<<(i-lsb(d)))*1LL;
    }
    cout << x << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
