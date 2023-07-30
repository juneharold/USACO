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
    vector<char> S(n+1);
    for (int i=1; i<=n; i++) cin >> S[i];
    vector<int> zero(n+5, 0), one(n+5, 0); // zero[i] contains position of rightmost to the left of i (inclusive)
    int pos=0;
    for (int i=1; i<=n; i++) {
        if (S[i]=='0') pos=i;
        zero[i]=pos;
    }
    pos=n+1;
    for (int i=n; i>=1; i--) {
        if (S[i]=='1') pos=i;
        one[i]=pos;
    }
    int same=0;
    set<pii> unique;
    for (int i=0; i<m; i++) {
        int l, r; cin >> l >> r;
        int nl=one[l], nr=zero[r];
        //cout << "here: " << nl << ' ' << nr << endl;
        if (nl>=nr || nl<l || r<nr) same=1;
        else unique.insert({nl, nr});
    }
    //for (auto x: unique) cout << x.f << ' ' << x.s << endl;
    cout << unique.size()+same << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
