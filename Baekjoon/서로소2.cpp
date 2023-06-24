#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
typedef long long ll;

int fastpow (int x, int y) {
    int exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
        }
        x*=x;
        exponent/=2;
    }
    return ret;
}

vector<int> p, isprime(100001, 1);
void linear_sieve() {
    for (int i=2; i<=100000; i++) {
        if (isprime[i]) p.push_back(i);
        for (int j: p) {
            if (i*j>100000) break;
            isprime[i*j]=0;
            if (i%j==0) break;
        }
    }
}

int EPF(int n) {
    vector<pair<int, int>> factors;
    for (int j: p) {
        int cnt=0;
        while (n%j==0) {
            cnt++;
            n/=j;
        }
        if (cnt!=0) factors.push_back({j, cnt});
    }
    if (n!=1) factors.push_back({n, 1});
    
    ll ret=1;
    for (auto x: factors) {
        ret*=fastpow(x.f, x.s)-fastpow(x.f, x.s-1);
    }
    return ret;
}

int main()
{
    linear_sieve();
    while (true) {
        int n; cin >> n;
        if (n==0) break;
        if (n==1) cout << 0 << "\n";
        else cout << EPF(n) << "\n";
    }
}