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
    int a=1, b=n*n;
    vector<vector<int>> ans(55, vector<int>(55, 0));
    int prev=1;
    for (int i=1; i<=n-1; i+=2) {
        for (int j=1; j<=n; j++) {
            if (prev) ans[i][j]=a++;
            else ans[i][j]=b--;
            prev=1-prev;
        }
        for (int j=n; j>=1; j--) {
            if (prev) ans[i+1][j]=a++;
            else ans[i+1][j]=b--;
            prev=1-prev;
        }
    }
    if (n%2) {
        for (int j=1; j<=n; j++) {
            if (prev) ans[n][j]=a++;
            else ans[n][j]=b--;
            prev=1-prev;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << ans[i][j] << ' ';
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
