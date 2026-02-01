#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

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

vector<int> get_prime_factors(int x) {
    vector<int> ret;
    while (x>1) {
        int mnf=minfactor[x];
        while (x%mnf==0) {
            x/=mnf;
        }
        ret.push_back(mnf);
    }
    return ret;
}

vector<int> prime_factors[nmax];
int mark[nmax]={};

void solve() {
    int n; cin >> n;
    vector<pii> temp(n+5);
    for (int i=1; i<=n; i++) cin >> temp[i].sc;
    for (int i=1; i<=n; i++) cin >> temp[i].fs;
    sort(&temp[1], &temp[n+1]);

    vector<ll> a(n+5), b(n+5);
    for (int i=1; i<=n; i++) a[i]=temp[i].sc;
    for (int i=1; i<=n; i++) b[i]=temp[i].fs;

    vector<ll> cost;
    for (int i=1; i<=n; i++) {
        if (a[i]%2) cost.push_back(b[i]);
    }
    sort(cost.begin(), cost.end());

    ll ans=1e18;
    if (cost.size()>=2) ans=cost[0]+cost[1];

    map<int, int> seen;
    for (int i=1; i<=n; i++) {
        for (int f: prime_factors[a[i]]) {
            if (seen.count(f)) ans=min(ans, 0ll);
        }
        for (int f: prime_factors[a[i]]) seen[f]++;
    }

    for (int i=1; i<=n; i++) {
        for (int f: prime_factors[a[i]]) seen[f]--;
        for (int f: prime_factors[a[i]+1]) {
            if (seen.count(f)) ans=min(ans, b[i]);
        }
        for (int f: prime_factors[a[i]]) seen[f]++;

    }

    for (int f: prime_factors[a[1]]) seen[f]--;
    set<int> primes;
    for (int i=2; i<=n; i++) {
        for (int f: prime_factors[a[i]]) {
            primes.insert(f);
        }
    }
    
    for (int p: primes) {
        int target=p*(a[1]/p);
        if (target<a[1]) target+=p;
        ans=min(ans, b[1]*(target-a[1]));
    } 
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve(2e5);
    for (int i=2; i<=2e5; i++) {
        prime_factors[i]=get_prime_factors(i);
    }
    
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}