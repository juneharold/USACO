#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=1e4+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> isprime, primes, minfactor;
void linear_sieve(int sz) {
    for (int i=0; i<=sz; i++) {
        isprime.push_back((i>1 ? 1:0));
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

void solve() {
    ll N, M; cin >> N >> M;
    if (N==1) {
        cout << 1;
        return;
    }
    linear_sieve(N);
    vector<vector<ll>> dp(primes.size()+1, vector<ll>(N+1, 0)); 
    /*
        dp[i]=sum of all K with permutation length i 
        for prime number p, raised to power e
        dp[i+fastpow(p, e)]+=dp[i]*fastpow(p, e);
    */ 
    for (int i=0; i<=N; i++) dp[0][i]=1;
    for (int i=1; i<=primes.size(); i++) {
        for (int j=0; j<=N; j++) {
            dp[i][j]=dp[i-1][j];
            ll p=1;
            while (j-p*primes[i-1]>=0) {
                p*=primes[i-1];
                dp[i][j]+=dp[i-1][j-p]*p;
                dp[i][j]%=M;
            }
        }
    }
    cout << dp[primes.size()][N];
}

/*
permutation cycles of length c1, c2, ... 
then K=LCM(c1, c2, ...) and sum of c_i should not exceed N 
to make sum of c_i short as possible, 
- gcd(c_i, c_j)==1 
- c_i should be consisted of a single prime number 
*/

int main()
{
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
