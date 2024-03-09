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
typedef pair<int, int> pii;
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
vector<int> isprime, primes, minfactor;
void linear_sieve(int sz) {
    for (int i=0; i<=sz; i++) {
        isprime.push_back((i>1 ? 1:0));
        minfactor.push_back(i);
    }
    for (int i=2; i<=sz; i++) {
        if (isprime[i]) primes.push_back(i);
        for (int j: primes) {
            if (i*j>sz) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}
int EPF(int n) {
    vector<pair<int, int>> factors;
    for (int j: primes) {
        int cnt=0;
        while (n%j==0) {
            cnt++;
            n/=j;
        }
        if (cnt!=0) factors.push_back({j, cnt});
    }
    if (n!=1) factors.push_back({n, 1});
    int ret=1;
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
        for (int i=0; i<26; i++) ch[i]=NULL;
    }
    ~Trie() {
        for (int i=0; i<26; i++) if (ch[i]) delete ch[i];
    }
    void insert(const char* s) {
        if (!*s) {
            end=true;
            return;
        }
        int now=*s-'a';
        if (!ch[now]) ch[now]=new Trie;
        ch[now]->insert(s+1);
    }
    bool find(const char* s) {
        if (!*s) { 
            if (end) return true;
            return false;
        }
        int now=*s-'a';
        if (!ch[now]) return false;
        return ch[now]->find(s+1);
    }
};
int leader[nmax], sz[nmax];
int Find(int x) {
    if (leader[x]==x) return x;
    return leader[x]=Find(leader[x]);
}
void Union (int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    leader[a]=b;
    sz[b]+=sz[a];
}
int ccw(pii A, pii B, pii C) {
    // returns AB x AC. if positive, counterclockwise
    return (A.fs*B.sc+B.fs*C.sc+C.fs*A.sc)-(A.sc*B.fs+B.sc*C.fs+C.sc*A.fs);
}
int parent[nmax][20], depth[nmax];
int lca(int a, int b) {
    if (depth[a]<depth[b]) swap(a, b);
    for (int i=19; i>=0; i--) {
        if (depth[a]-depth[b]>(1<<i)) a=parent[a][i];
    }
    if (a==b) return a;
    for (int i=0; i<=19; i++) {
        if (parent[a][i]!=parent[b][i]) a=parent[a][i], b=parent[b][i];
    }
    return parent[a][0];
}
int segtree[4*nmax]={};
int query(int n, int a, int b, int qa, int qb) {
	if (b<qa || qb<a) return 0;
	if (qa<=a && b<=qb) return segtree[n];
	int mid=(a+b)/2;
	return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
	if (qa<=a && b<=qb) { segtree[n]=v; return; }
	int mid=(a+b)/2;
	update(2*n, a, mid, qa, qb, v);
	update(2*n+1, mid+1, b, qa, qb, v);
	segtree[n]=segtree[2*n]+segtree[2*n+1];
}


vector<int> graph[nmax];
int sz[nmax]={};
void dfs(int cur, int p) {
    sz[cur]=1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        depth[nx]=depth[cur]+1;
        parent[nx][0]=cur;
        dfs(nx, cur);
        sz[cur]+=sz[nx];
    }
}

int N, group[nmax], head[nmax], order[nmax], piv1, piv2;
void hld(int cur, int p) {
    sort(graph[cur].begin(), graph[cur].end(), [](int &a, int &b){return sz[a]>sz[b];});
    int heavy=-1;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        heavy=nx;
        group[nx]=group[cur];
        order[nx]=++piv2;
        hld(nx, cur);
        break;
    }
    for (int nx: graph[cur]) {
        if (nx==p || nx==heavy) continue;
        group[nx]=++piv1;
        head[group[nx]]=nx;
        order[nx]=++piv2;
        hld(nx, cur);
    }
}

int tree_query(int a, int b) {
    int ret=0;
    while (group[a]!=group[b]) {
        if (a==1 && b==0) break;
        int aa=head[group[a]], bb=head[group[b]];
        if (depth[a]>depth[b]) {
            ret+=query(1, 1, N, order[aa], order[a]);
            a=parent[aa][0];
        }
        else {
            ret+=query(1, 1, N, order[bb], order[b]);
            b=parent[bb][0];
        }
    }
    if (depth[a]>depth[b]) swap(a, b);
    ret+=query(1, 1, N, order[a], order[b]);
    return ret;
}

ll fact[nmax]={}, invfact[nmax]={};
ll nCr(ll n, ll r) {
    return fact[n]*invfact[n-r]%MOD*invfact[r]%MOD;
}

pair<ll, pii> euclid(ll a, ll b) {
    if (a<b) swap(a, b);
    if (b==0) return {a, {1, 0}};
    auto res=euclid(b, a%b);
    ll g=res.fs, x1=res.sc.fs, y1=res.sc.sc;
    return {g, {y1, x1-y1*(a/b)}};
}

bool diophantine(ll a, ll b, ll c) { // find if solution exists for ax+by=c
    auto res=euclid(abs(a), abs(b));
    ll g=res.fs, x=res.sc.fs, y=res.sc.sc;
    if (c%g) return false;
    x*=c/g;
    y*=c/g;
    if (a<0) x=-x;
    if (b<0) y=-y;
    return true;
}

void solve() {
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
