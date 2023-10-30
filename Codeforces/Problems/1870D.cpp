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

void solve() {
    ll n; cin >> n;
    vector<ll> c(n+1, 0), ans(n+2, 0);
    for (ll i=1; i<=n; i++) cin >> c[i];
    ll k; cin >> k;
    vector<pii> valid;
    ll mn=2e9;
    for (ll i=n; i>=1; i--) {
        if (c[i]<mn) {
            valid.push_back({i, c[i]});
            mn=c[i];
        }
    }
    sort(valid.begin(), valid.end());

    ans[valid[0].fs]+=k/valid[0].sc;
    k-=(k/valid[0].sc)*valid[0].sc;
    for (int i=1; i<valid.size(); i++) {
        int d=valid[i].sc-valid[i-1].sc;
        int num_buy=min(ans[valid[i-1].fs], k/d);
        // (k/d)만큼 현재 구매, 
        ans[valid[i-1].fs]-=num_buy;
        ans[valid[i].fs]+=num_buy;
        k-=num_buy*d;
    }

    for (ll i=n; i>=1; i--) ans[i]+=ans[i+1];
    for (ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << "\n";
}
/*
1
3
999 1000 1001
1001
ans: 1 1 1

1
3
5 6 7
19
ans: 3 3 1

1
5
3 4 5 6 7  
8
ans: 2 2 0 0 0 

1
2
4 5
10
ans: 2 2

1
3
4 5 7
14
ans: 3 2 0

1
3
4 5 6
15
ans: 3 3 0
*/
/*
if c[i]=>c[j] (i<j), always buy c[j]
then only a small number of c[i] (arbitrary i) will be valid 
for valid c[i]'s, the cheapest in front and expensive in back. 
Better to buy 2 cheap than 1 expensive. 
Buy as many cheap as possible, 
if you have money buy two cheap, then purchase cheap, otherwise, pick the maximum possiblle expensive 
(in the end, you'll only be buying two unique c[i]'s) 
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
