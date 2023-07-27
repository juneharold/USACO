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
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int sum=0;
    if (a[n-1]==a[n-2]) swap(a[0], a[n-2]);
    for (int i=n-1; i>=0; i--) {
        if (a[i]==sum) {
            cout << "NO\n";
            return;
        }
        sum+=a[i];
    }
    cout << "YES\n";
    for (int i=n-1; i>=0; i--) cout << a[i] << ' ';
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
