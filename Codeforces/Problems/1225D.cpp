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

void solve() {
    linear_sieve(1e5);
    int n, k; cin >> n >> k;
    map<vector<pii>, int> m;
    ll ans=0;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        int temp=a;
        vector<int> pf;
        while (temp>1) {
            pf.push_back(minfactor[temp]);
            temp/=minfactor[temp];
        }
        vector<pii> L; 
        L.push_back({1, 0});
        int prev=-1, cnt=0;
        for (int p: pf) {
            if (p==prev) cnt++;
            else {
                if (prev!=-1 && cnt%k!=0) L.push_back({prev, cnt%k});
                prev=p;
                cnt=1;
            }
        }
        if (prev!=-1 && cnt%k!=0) L.push_back({prev, cnt%k});
        vector<pii> target=L;
        for (int j=0; j<target.size(); j++) {
            target[j].s=(k-L[j].s)%k;
        }
        ans+=m[target];
        m[L]++;
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
