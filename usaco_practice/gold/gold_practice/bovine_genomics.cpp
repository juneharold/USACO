#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

const ll p=5, MOD=1e9+7;
ll fastpow (ll x, ll y) {
    ll ret=1;
    while (y) {
        if (y%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        y/=2;
    }
    return ret;
}

int s1[505][505], s2[505][505];
ll hash1[505]={}, hash2[505]={};
map<char, int> m;

int main() 
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    m['A']=1, m['C']=2, m['G']=3, m['T']=4;
    ll N, M; cin >> N >> M;
    for (ll i=0; i<N; i++) {
        string s; cin >> s;
        for (ll j=0; j<M; j++) s1[i][j]=m[s[j]];
    }
    for (ll i=0; i<N; i++) {
        string s; cin >> s;
        for (ll j=0; j<M; j++) s2[i][j]=m[s[j]];
    }

    ll lo=1, hi=M;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        bool possible=false, overlap=false;
        multiset<ll> active;
        for (ll i=0; i<N; i++) {
            for (ll j=0; j<mid; j++) {
                hash1[i]+=s1[i][j]*fastpow(p, mid-1-j)%MOD;
                hash1[i]%=MOD;
            }
            active.insert(hash1[i]);
        }
        for (ll i=0; i<N; i++) {
            for (ll j=0; j<mid; j++) {
                hash2[i]+=s2[i][j]*fastpow(p, mid-1-j)%MOD;
                hash2[i]%=MOD;
            }
            if (active.find(hash2[i])!=active.end()) overlap=true;
        }
        if (!overlap) possible=true;

        for (ll idx=1; idx<M-mid+1; idx++) {
            active.clear(); overlap=false;
            for (ll i=0; i<N; i++) {
                hash1[i]=(hash1[i]-s1[i][idx-1]*fastpow(p, mid-1))*p+s1[i][idx-1+mid]+MOD;
                hash1[i]%=MOD;
                active.insert(hash1[i]);
            }
            for (ll i=0; i<N; i++) {
                hash2[i]=(hash2[i]-s2[i][idx-1]*fastpow(p, mid-1))*p+s2[i][idx-1+mid]+MOD;
                hash2[i]%=MOD;
                if (active.find(hash2[i])!=active.end()) overlap=true;
            }
            if (!overlap) possible=true;
        }
        if (possible) hi=mid;
        else lo=mid+1;
        fill(&hash1[0], &hash1[N+1], 0);
        fill(&hash2[0], &hash2[N+1], 0);
    }
    cout << lo;
}
