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
const ll nmax=305, sqrmax=635, MOD=998244353;

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

ll dp[2][200000]={};
/*
dp[i][j] = number of different arrays from 1~i when a[i]==j
*/

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    const int n2=300*300;
    dp[0][a[2]+n2]=1;
    for (int i=2; i<n; i++) {
        for (int j=-n2; j<=n2; j++) dp[(i+1)%2][j+n2]=0;
        for (int j=-n2; j<=n2; j++) {
            dp[(i+1)%2][a[i+1]+j+n2]+=dp[i%2][j+n2];
            dp[(i+1)%2][a[i+1]+j+n2]%=MOD;
            if (j==0) continue;
            dp[(i+1)%2][a[i+1]-j+n2]+=dp[i%2][j+n2];
            dp[(i+1)%2][a[i+1]-j+n2]%=MOD;
        }
    }
    ll ans=0;
    for (int j=0; j<=n2*2; j++) {
        ans+=dp[n%2][j];
        ans%=MOD;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
