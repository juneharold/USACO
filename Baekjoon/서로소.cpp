#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> p, isprime(1000001, 1);
void find_primes() {
    for (int i=2; i<=1000000; i++) {
        if (isprime[i]) p.push_back(i);
        for (int j: p) {
            if (i*j>100000) break;
            isprime[i*j]=0;
            if (i%j==0) break;
        }
    }
}

vector<ll> find_prime_factors(ll n) {
    vector<ll> ret;
    for (int i=0; i<p.size(); i++) {
        if (n%p[i]==0) ret.push_back(p[i]);
        while (n%p[i]==0) {
            n/=p[i];
        }
    }
    if (n!=1) ret.push_back(n);
    return ret;
}

int countbits(int n) {
    int ret=0;
    while (n) {
        if (n%2) ret++;
        n/=2;
    }
    return ret;
}

ll solve(ll mx, vector<ll> factors) {
    ll ret=0, sz=factors.size();
    for (int i=1; i<(1<<sz); i++) {
        ll temp=1;
        for (int j=0; j<sz; j++) if (i&(1<<j)) temp*=factors[j];
        if (countbits(i)%2) ret+=mx/temp;
        else ret-=mx/temp;
    }
    return mx-ret;
}

int main()
{
    find_primes();
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        ll a, b, n; cin >> a >> b >> n;
        vector<ll> factors=find_prime_factors(n);
        cout << "Case #" << t << ": " << solve(b, factors)-solve(a-1, factors) << "\n";
    }
}