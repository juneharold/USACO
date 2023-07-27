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
    int n, m; cin >> n >> m;
    vector<int> a(n+1, 0), won(n+1, 0);
    vector<pair<int, int>> b;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    int sum=0, last=0, cnt=0;
    for (int i=0; i<n; i++) {
        if (sum+b[i].f<=m) {
            sum+=b[i].f;
            last=b[i].f;
            won[b[i].s]=1;
            cnt++;
        }
    }

    for (int i=n; i>=1; i--) {
        //place n-i+1
        int opponent=i;
        if (won[i]) opponent--;
        if (won[i]==0 && sum-last+a[i]<=m && cnt>=opponent-1)  {
            cout << n-i+1 << "\n";
            return;
        }
        if (cnt>=opponent) {
            cout << n-i+1 << "\n";
            return;
        }
    }
    cout << n+1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
