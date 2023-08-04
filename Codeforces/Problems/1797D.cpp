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
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7;

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

ll a[nmax]={}, vst[nmax]={}, sz[nmax]={}, im[nmax]={}, fa[nmax]={};
vector<ll> graph[nmax];
set<pii> order[nmax];

void dfs(ll cur, ll parent) {
    vst[cur]=1; fa[cur]=parent; im[cur]=a[cur]; sz[cur]=1;
    for (ll nx: graph[cur]) {
        if (!vst[nx]) {
            dfs(nx, cur);
            im[cur]+=im[nx]; sz[cur]+=sz[nx];
            order[cur].insert({sz[nx], -nx});
        }
    }
}

void solve() {
    ll n, m; cin >> n >> m;
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<n; i++) {
        ll u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        ll type, x; cin >> type >> x;
        if (type==1) cout << im[x] << "\n";
        else if (!order[x].empty()){
            auto it=--order[x].end();
            ll i=-(*it).sc;
            order[x].erase(it);
            ll sz_x=sz[x], sz_i=sz[i], im_x=im[x], im_i=im[i];
            sz[i]=sz_x; im[i]=im_x; sz[x]=sz_x-sz_i; im[x]=im_x-im_i;
            order[i].insert({sz[x], -x});
            order[fa[x]].erase({sz_x, -x});
            order[fa[x]].insert({sz[i], -i});
            fa[i]=fa[x]; fa[x]=i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
