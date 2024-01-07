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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

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
ll cntbits(ll x) {
    ll ret=0;
    while (x) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}
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
ll EPF(ll n) {
    vector<pair<ll, ll>> factors;
    for (ll j: primes) {
        ll cnt=0;
        while (n%j==0) {
            cnt++;
            n/=j;
        }
        if (cnt!=0) factors.push_back({j, cnt});
    }
    if (n!=1) factors.push_back({n, 1});
    ll ret=1;
    for (auto x: factors) {
        ret*=fastpow(x.fs, x.sc)-fastpow(x.fs, x.sc-1);
    }
    return ret;
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
vector<ll> parent, sz;
ll Find(ll x) {
    if (parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union (ll a, ll b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    parent[a]=b;
    sz[b]+=sz[a];
}
ll ccw(pii A, pii B, pii C) {
    // returns AB x AC. if positive, counterclockwise
    return (A.fs*B.sc+B.fs*C.sc+C.fs*A.sc)-(A.sc*B.fs+B.sc*C.fs+C.sc*A.fs);
}

// Cannot name variables: nmax, sqrmax, MOD, INF, isprime, primes, minfactor, parent, sz

ll st[400005]={};

ll query(ll nn, ll a, ll b, ll qa, ll qb) {
	if (qb<a || qa>b) return 0;
	if (qa<=a && b<=qb) return st[nn];
	ll mid=(a+b)/2;
	return query(2*nn, a, mid, qa, qb)+query(2*nn+1, mid+1, b, qa, qb);
}

void update(ll nn, ll a, ll b, ll qa, ll qb, ll v) {
	if (qa<=a && b<=qb) { st[nn]=v; return; }
    if (qb<a || qa>b) return;
	ll mid = (a+b)/2;
	update(2*nn, a, mid, qa, qb, v);
	update(2*nn+1, mid+1, b, qa, qb, v);
	st[nn]=st[2*nn]+st[2*nn+1];
}


void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n+1, 0);
    ll sum=0;
    set<ll> pos; // keeps position of 1s
    for (ll i=1; i<=n; i++) {
        cin >> a[i];
        update(1, 1, n, i, i, a[i]);
        sum+=a[i];
        if (a[i]==1) pos.insert(i);
    }
    while (q--) {
        ll type; cin >> type;
        if (type==1) {
            ll s; cin >> s;
            bool possible=false;
            if (!pos.empty()) {
                auto it1=pos.begin();
                ll k1=query(1, 1, n, *it1, n);
                auto it2=--pos.end();
                ll k2=query(1, 1, n, 1, *it2);
                if (s<=max(k1, k2)) possible=true;
                //cout << "k1 k2 sum " << k1 << ' ' << k2 << ' ' << sum << endl;
            }
            if (sum%2==s%2 && s<=sum) possible=true;

            if (possible) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            ll j, v; cin >> j >> v;
            if (a[j]==1 && v==2) {
                pos.erase(j);
                sum++;
                update(1, 1, n, j, j, v);
                a[j]=2;
            }
            else if (a[j]==2 && v==1) {
                pos.insert(j);
                sum--;
                update(1, 1, n, j, j, v);
                a[j]=1;
            }
        }
    }
    for (ll i=0; i<=4*n+10; i++) st[i]=0;
}
/*
1 10
1
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
