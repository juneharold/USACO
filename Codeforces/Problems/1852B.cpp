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
    vector<pii> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i].f;
        a[i].s=i;
    }
    sort(&a[1], &a[n+1]);
    vector<int> b(n+1);
    int l=1, r=n, sz=n;
    while (l<=r) {
        if (a[r].f==n-l+1) {
            b[a[r].s]=sz;
            r--;
        }
        else if (a[l].f==n-r) {
            b[a[l].s]=-sz;
            l++;
        }
        else {
            cout << "NO\n";
            return;
        }
        sz--;
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) cout << b[i] << ' ';
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
