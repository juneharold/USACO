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
vector<int> parent, sz;
int Find(int x) {
    if (parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union (int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    parent[a]=b;
    sz[b]+=sz[a];
}
int ccw(pii A, pii B, pii C) {
    // returns AB x AC. if positive, counterclockwise
    return (A.fs*B.sc+B.fs*C.sc+C.fs*A.sc)-(A.sc*B.fs+B.sc*C.fs+C.sc*A.fs);
}

// Cannot name variables: nmax, sqrmax, MOD, INF, isprime, primes, minfactor, parent, sz
ll st[8000005]={};

ll query(ll nn, ll a, ll b, ll qa, ll qb) {
	if (qb<a || qa>b) return 0;
	if (qa<=a && b<=qb) return st[nn];
	ll mid=(a+b)/2;
	return query(2*nn, a, mid, qa, qb)+query(2*nn+1, mid+1, b, qa, qb);
}

void update(ll nn, ll a, ll b, ll qa, ll qb, ll v) {
	if (qa<=a && b<=qb) { st[nn]=v; return; }
    if (qb<a || qa>b) return;
	ll mid=(a+b)/2;
	update(2*nn, a, mid, qa, qb, v);
	update(2*nn+1, mid+1, b, qa, qb, v);
	st[nn]=st[2*nn]+st[2*nn+1];
}


void solve() {
    int n; cin >> n;
    vector<int> a(2*n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n]=a[i];
    }

    vector<int> pos(n+1, -1), ans(n+1, -1);
    for (int i=1; i<=2*n; i++) {
        int idx=(i-1)%n+1;
        pos[a[i]]=i;
        if (pos[idx]==-1) continue;
        else if (ans[idx]!=-1) {
            update(1, 1, 2*n, pos[idx], pos[idx], 1);
            continue;
        }
        ans[idx]=i-pos[idx]-query(1, 1, 2*n, pos[idx]+1, i-1);
        update(1, 1, 2*n, pos[idx], pos[idx], 1);
    }
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << "\n";

    for (int i=0; i<=8*n; i++) st[i]=0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
