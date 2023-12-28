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
const ll nmax=2e5+5, sqrmax=635, MOD=998244353, INF=1e18;

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
ll n, ans=1, vst[100005]={}, sum_weight=0, sum_node=0;
vector<pii> graph[100005];
vector<int> path;

void dfs(ll cur, ll bef) {
    vst[cur]=1;
    path.push_back(cur);
    sum_node++;
    for (ll i=0; i<graph[cur].size(); i++) {
        ll nx=graph[cur][i].fs, w=graph[cur][i].sc;
        if (nx==cur) {
            ans=ans*fastpow(n, w)%MOD;
            sum_weight+=w;
            continue;
        }
        else if (vst[nx]==0) {
            ans=ans*fastpow(2, w-1)%MOD;
            sum_weight+=w;
            dfs(nx, cur);
        }
        else if (nx!=bef) {
            int idx=-1;
            for (int j=0; j<path.size(); j++) {
                if (path[j]==nx) idx=j;
            }
            if (idx!=-1) {
                ans=ans*2%MOD;
                sum_weight+=w;
            }
        }
    }
    path.pop_back();
}

void initialize() {
    ans=1;
    for (ll i=0; i<=n; i++) {
        vst[i]=0;
        graph[i].clear();
    }
}

void solve() {
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i=0; i<n; i++) cin >> a[i];
    for (ll i=0; i<n; i++) {
        cin >> b[i];
        if (a[i]>b[i]) swap(a[i], b[i]);
    }
    
    map<pii, ll> m;
    for (ll i=0; i<n; i++) {
        m[{a[i], b[i]}]++;
    }
    ll cnt=0;
    for (auto x: m) {
        ll u=x.fs.fs, v=x.fs.sc, w=x.sc;
        graph[u].push_back({v, w});
        if (u!=v) graph[v].push_back({u, w});
    }
    for (ll i=1; i<=n; i++) {
        path.clear();
        sum_node=0, sum_weight=0;
        if (vst[i]==0) dfs(i, -1);
        if (sum_node>sum_weight) ans=0;
    }
    cout << ans%MOD << "\n";
    initialize();
}
/*
4
1 2 3 4
3 1 2 4

4
1 2 2 4
2 3 3 4

4
1 2 4 4 
2 3 4 4
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}