#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<ll> isprime, primes, minfactor;
void linear_sieve(ll sz) {
    for (ll i=0; i<=sz; i++) {
        isprime.push_back((i>1 ? 1:0));
        minfactor.push_back(i);
    }
    for (ll i=2; i<=sz; i++) {
        if (isprime[i]) primes.push_back(i);
        for (ll j: primes) {
            if (i*j>sz) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}

ll cntbits(ll x) {
    ll ret=0;
    while (x) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}


vector<ll> find_prime_factors(ll n) {
    vector<ll> primeFactors;
    while (n>1) {
        ll temp=minfactor[n];
        while (n%temp==0) {
            n/=temp;
        }
        primeFactors.push_back(temp);
    }
    if (n!=1) primeFactors.push_back(n);
    return primeFactors;
}

// Function to calculate the Euler's Totient Function
ll eulerTotient(ll n, const vector<ll>& primeFactors) {
    ll result = n;
    for (ll p : primeFactors) {
        result *= (p - 1);
        result /= p;
    }
    return result;
}

// Function to find the sum of multiples of a prime factor p up to n
ll sumOfMultiples(ll n, ll p) {
    ll m = n / p;
    return p * (m * (m + 1)) / 2;
}

// Function to find the sum of j such that gcd(i, j) != 1
pair<ll, long long> countAndSumNonCoprimes(ll i, const vector<ll>& primeFactors) {
    ll totalNumbers = i; // Total numbers from 1 to i
    ll coprimesCount = eulerTotient(i, primeFactors); // Count of numbers where gcd(i, j) = 1
    ll nonCoprimesCount = totalNumbers - coprimesCount; // Complement: gcd(i, j) != 1
    
    // Sum of all numbers from 1 to i (arithmetic progression sum)
    long long totalSum = (1LL * i * (i + 1)) / 2;
    
    // Sum of non-coprimes (total sum minus sum of coprimes)
    long long nonCoprimeSum = 0;
    
    // Apply inclusion-exclusion principle
    ll numFactors = primeFactors.size();
    
    // Iterate over all subsets of the prime factors to include and exclude sums
    for (ll mask = 1; mask < (1 << numFactors); ++mask) {
        ll sign = -1; // Inclusion (positive) or exclusion (negative)
        ll product = 1;
        
        // Find the product of primes in this subset
        for (ll j = 0; j < numFactors; ++j) {
            if (mask & (1 << j)) {
                product *= primeFactors[j];
                sign *= -1;
            }
        }
        
        // Sum the multiples of this product
        nonCoprimeSum += sign * sumOfMultiples(i, product);
    }
    
    return {nonCoprimesCount, nonCoprimeSum};
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N; cin >> N;
    linear_sieve(1e6);
    ll ans=0;
    for (ll i=1; i<=N; i++) {
        vector<ll> v=find_prime_factors(i);
        auto res=countAndSumNonCoprimes(i, v);
        ans+=i*(i-res.fs)%MOD+i*(i+1)/2-res.sc;
        if (i!=1) ans+=i*(i-res.fs)%MOD+i*(i+1)/2-res.sc;
        ans%=MOD;
        //cout << i << ' ' <<i*(i-res.fs)%MOD+i*(i+1)/2-res.sc << endl;
        //cout << i << ' ' << i*res.fs+res.sc << endl;
    }
    cout << ans << endl;

    /*for (int i=1; i<=N; i++) {
        int temp=0;
        for (int j=1; j<=N; j++) {
            if (gcd(i, j)==1) temp+=i+j;
        }
        cout << temp << endl;
    }*/
    /*int ans2=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (gcd(i, j)==1) ans2+=i+j;
        }
    }
    cout << ans2 << endl;*/
}
