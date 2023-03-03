#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll num[1001005]={}, check[1000005]={};

int main()
{
    vector<ll> primes;
    for (ll i=2; i<=1001000; i++) {
        if (num[i]==0) {
            primes.push_back(i);
            for (ll j=i*2; j<=1001000; j+=i) num[j]=1;
        }
    }
    ll Min, Max, ans=0; cin >> Min >> Max;
    for (ll n: primes) {
        ll jegobsu=n*n;
        ll Minfactor=Min/jegobsu;
        for (ll i=Minfactor; i<=Minfactor+1e9; i++) {
            if(i*jegobsu>Max) break;
            if (i*jegobsu<Min) continue;
            check[i*jegobsu-Min]=1;
        }
    }
    for (ll i=Min; i<=Max; i++) if (check[i-Min]==0) {
        ans++;
    }
    cout << ans;
}
