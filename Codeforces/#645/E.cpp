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
#include <iomanip>
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
        ll now=*s-'a';
        if (!ch[now]) ch[now]=new Trie;
        ch[now]->insert(s+1);
    }
    bool find(const char* s) {
        if (!*s) { 
            if (end) return true;
            return false;
        }
        ll now=*s-'a';
        if (!ch[now]) return false;
        return ch[now]->find(s+1);
    }
};

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1), pfs(n+1);
    for (ll i=1; i<=(n+1)/2; i++) {
        cin >> a[i];
        pfs[i]=pfs[i-1]+a[i];
    }
    ll x; cin >> x;
    for (ll i=(n+1)/2+1; i<=n; i++) {
        a[i]=x;
        pfs[i]=pfs[i-1]+a[i];
    }
    if (pfs[n]>0) {
        cout << n;
        return;
    }
    else if (x>=0) {
        cout << -1;
        return;
    }

    vector<ll> maxlimit(n+1, 0);
    for (ll i=1; i<=n; i++) {
        ll lo=n/2+1, hi=n;
        while (lo<hi) {
            ll mid=(lo+hi+1)/2;
            if (pfs[mid]-pfs[i-1]>0) lo=mid;
            else hi=mid-1;
        }
        if (pfs[lo]-pfs[i-1]<=0) continue;
        maxlimit[i]=lo-i+1;
        /*
        pfs[j]-pfs[i]>0 인 최대 j 찾기, j>(n+1)/2
        maxlimit[i]=j-i+1;
        */
    }

    //for (ll i=1; i<=n; i++) cout << maxlimit[i] << ' ';

    ll k=1e18;
    for (ll i=1; i<=n; i++) {
		k=min(k, maxlimit[i]);
		if(n-i+1<=k) {
			cout << k;
			return;
		}
	}
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
