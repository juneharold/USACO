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
typedef pair<int, int> pii;
#define f first
#define s second
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
vector<int> isprime, primes, minfactor;
void linear_sieve() {
    for (int i=0; i<=2e5; i++) {
        isprime.push_back(1);
        minfactor.push_back(i);
    }
    for (int i=2; i<=2e5; i++) {
        if (isprime[i]) primes.push_back(i);
        for (int j: primes) {
            if (i*j>2e5) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> p(n+1), pos(n+1);
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        pos[p[i]]=i;
    }
    vector<int> l(n+1, 0), r(n+1, 0);
    stack<pii> stk;
    stk.push({1e9, 0});
    for (int i=1; i<=n; i++) {
        while (stk.top().f<p[i]) {stk.pop();}
        l[i]=stk.top().s+1;
        stk.push({p[i], i});
    }
    while (!stk.empty()) {stk.pop();}
    stk.push({1e9, n+1});
    for (int i=n; i>=1; i--) {
        while (stk.top().f<p[i]) {stk.pop();}
        r[i]=stk.top().s-1;
        stk.push({p[i], i});
    }

    ll ans=0;
    for (int i=1; i<=n; i++) {
        if (i-l[i]+1<r[i]-i+1) {
            for (int j=i-1; j>=l[i]; j--) {
                if (i<=pos[p[i]-p[j]] && pos[p[i]-p[j]]<=r[i]) ans++;
            }
        }
        else {
            for (int j=i+1; j<=r[i]; j++) {
                if (l[i]<=pos[p[i]-p[j]] && pos[p[i]-p[j]]<=i) ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1;// cin >> T;
    while (T--) {
        solve();
    }
}
