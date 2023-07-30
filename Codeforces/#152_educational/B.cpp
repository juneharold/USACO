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

bool cmp(pii a, pii b) {
    if (a.f==b.f) return a.s<b.s;
    else return a.f>b.f;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i]=a[i]%k;
        if (a[i]==0) a[i]=k;
    }
    vector<pair<int, int>> b;
    for (int i=1; i<=n; i++) {
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end(), cmp);
    for (int i=0; i<b.size(); i++) {
        cout << b[i].s << ' ';
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
