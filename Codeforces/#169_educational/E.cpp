#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int g[10000005]={};

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    int s=0;
    for (int i=1; i<=n; i++) s^=g[a[i]];
    cout << (s==0 ? "Bob" : "Alice") << "\n";
}
/*
grundy number of s is mex of all grundy number of s' 
*/

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve(1e7);
    g[0]=0, g[1]=1;
    int cnt=2;
    for (int i=2; i<=1e7; i++) {
        if (i%2==0) continue;
        if (isprime[i]) g[i]=cnt++;
        else g[i]=g[minfactor[i]];
    }
    /*
    g[i] pattern:
    if i is even, then g[i]=0;
    if i is prime, then g[i] is the order of prime. For instance 5 is the 3rd prime number, so g[5]=3
    g[9] no g[3]=2. 
    if i is odd, then g[i] is g[j] where j is smallest prime that divides i. 
    */

    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
