#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

vector<ll> Hash[600011]={};

ll fastpow(ll x, ll y) {
    ll ret=1, exponent=y;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=600011;
        }
        x*=x;
        x%=600011;
        exponent/=2;
    }
    return ret;
}

int main()
{
    ll N, K; cin >> N >> K;
    string s1, s2; cin >> s1 >> s2;

    ll hash1=0, hash2=0;
    for (ll i=0; i<K; i++) {
        ll x=s1[i]-'0';
        hash1=(hash1*10+x)%600011;
        hash2=(hash2*11+x)%600011;
    }
    Hash[hash1].push_back(hash2);
    for (ll i=1; i<N; i++) {
        if (i+K-1>=N) break;
        ll x=s1[i-1]-'0';
        hash1=(hash1-x*fastpow(10, K-1)%600011+600011)%600011;
        hash2=(hash2-x*fastpow(11, K-1)%600011+600011)%600011;
        x=s1[i+K-1]-'0';
        hash1=(hash1*10+x)%600011;
        hash2=(hash2*11+x)%600011;
        Hash[hash1].push_back(hash2);
    }
    
    ll ans=0;
    hash1=0, hash2=0;
    for (ll i=0; i<K; i++) {
        ll x=s2[i]-'0';
        hash1=(hash1*10+x)%600011;
        hash2=(hash2*11+x)%600011;
    }
    for (ll j=0; j<Hash[hash1].size(); j++) {
        if (Hash[hash1][j]==hash2) {
            ans++;
            Hash[hash1].clear();
            break;
        }
    }
    for (ll i=1; i<N; i++) {
        if (i+K-1>=N) break;
        ll x=s2[i-1]-'0';
        hash1=(hash1-x*fastpow(10, K-1)%600011+600011)%600011;
        hash2=(hash2-x*fastpow(11, K-1)%600011+600011)%600011;
        x=s2[i+K-1]-'0';
        hash1=(hash1*10+x)%600011;
        hash2=(hash2*11+x)%600011;
        for (ll j=0; j<Hash[hash1].size(); j++) {
            if (Hash[hash1][j]==hash2) {
                ans++;
                Hash[hash1].clear();
                break;
            }
        }
    }
    cout << ans;
}