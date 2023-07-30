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
void linear_sieve(int sz) {
    for (int i=0; i<=sz; i++) {
        isprime.push_back(1);
        minfactor.push_back(i);
    }
    for (int i=2; i<=sz; i++) {
        if (isprime[i]) primes.push_back(i);
        for (int j: primes) {
            if (i*j>sz) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}

bool prime_number(int x) {
    for (int d: primes) {
        if (d>1e4) break;
        if (x%d==0) return false;
    }
    return true;
}

void solve() {
    linear_sieve(1e7);
    int n; cin >> n;
    vector<int> ans1, ans2;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        set<int> factors;
        int temp=a;
        while (temp>1) {
            factors.insert(minfactor[temp]);
            temp/=minfactor[temp];
        }
        if (factors.size()==1) {
            ans1.push_back(-1);
            ans2.push_back(-1);
        }
        else {
            int prod=1;
            for (int x: factors) prod*=x;
            ans1.push_back(*factors.begin());
            ans2.push_back(prod/(*factors.begin()));
        }
    }

    for (int x: ans1) cout << x <<' ';
    cout << "\n";
    for (int x: ans2) cout << x <<' ';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
