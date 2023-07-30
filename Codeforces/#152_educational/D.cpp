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
    vector<int> a(n+1, 0), vst(n+1, 0), twos;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]==2) twos.push_back(i);
    }
    int ans=0;
    for (int pos: twos) {
        if (vst[pos]) continue;
    }
    vector<int> ones;
    for (int i=1; i<=n; i++) {
        if (vst[i]) continue;
        if (a[i]==1 && a[i-1]==0) ones.push_back(i);
    }
    for (int pos: ones) {
        if (vst[pos]) continue;
        ans++;
        if (pos-1>0 && vst[pos-1]==0) {
            vst[pos-1]=1;
            for (int i=pos; i<=n; i++) {
                if (a[i]==0) break;
                vst[i]=1;
            }
        }
        else {
            for (int i=pos; i<=n; i++) {
                vst[i]=1;
                if (a[i]==0) break;
            }
        }
    }
    for (int i=1; i<=n; i++) if (vst[i]==0) ans++;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
