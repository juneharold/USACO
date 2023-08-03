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
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

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
vector<ll> isprime, primes, minfactor;
void linear_sieve(ll sz) {
    for (ll i=0; i<=sz; i++) {
        isprime.push_back(1);
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
struct Trie {
    Trie *ch[26];
    //map<string, Trie*> ch;
    //vector<pair<char, Trie*>> ch
    bool end;
    Trie() {
        end=false;
        for (ll i=0; i<26; i++) ch[i]=NULL;
    }
    ~Trie() {
        for (ll i=0; i<26; i++) if (ch[i]) delete ch[i];
    }
    void insert(const char* s) {
        if (!*s) {
            end=true;
            return;
        }
        ll now=*s-'A';
        if (!ch[now]) ch[now]=new Trie;
        ch[now]->insert(s+1);
    }
    bool find(const char* s) {
        if (!*s) { 
            if (end) return true;
            return false;
        }
        ll now=*s-'A';
        if (!ch[now]) return false;
        return ch[now]->find(s+1);
    }
};

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> d(2*n+10), pfs1(2*n+10), pfs2(2*n+10);
    for (ll i=1; i<=n; i++) {
        cin >> d[i];
        d[n+i]=d[i];
    }
    for (ll i=1; i<=2*n; i++) {
        pfs1[i]=pfs1[i-1]+d[i]; // counts days
        pfs2[i]=pfs2[i-1]+(d[i]+1)*d[i]/2; // counts hugs
    }

    ll ans=0;
    for (ll i=1; i<=2*n; i++) {
        ll lo=1, hi=i; 
        while (lo<hi) {
            ll mid=(lo+hi+1)/2;
            if (pfs1[i]-pfs1[mid-1]>x) lo=mid;
            else hi=mid-1;
        }
        ll temp=pfs2[i]-pfs2[lo];
        ll days_left=x-(pfs1[i]-pfs1[lo]);
        if (days_left>d[lo]) temp+=(d[lo]+1)*d[lo]/2;
        else temp+=(2*d[lo]-days_left+1)*days_left/2;
        ans=max(ans, temp);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
