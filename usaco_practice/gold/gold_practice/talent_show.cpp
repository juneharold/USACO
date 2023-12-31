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
ll t[255]={}, w[255]={}, dp[255][1005]={};
void solve() {
    ll N, W; cin >> N >> W;
    for (ll i=1; i<=N; i++) cin >> w[i] >> t[i];
    ll lo=0, hi=1e9;
    while (lo<hi) {
        ll mid=(lo+hi)/2+1;
        vector<ll> new_talent(255, 0);
        for (ll i=1; i<=N; i++) new_talent[i]=1000*t[i]-mid*w[i];
        fill(&dp[0][0], &dp[N+1][W+1], -1e18);
        dp[0][0]=0;
        for (ll i=0; i<N; i++) {
            for (ll j=0; j<=W; j++) {
                if (dp[i][j]!=-1e18) {
                    int ww=min(j+w[i+1], W);
                    dp[i+1][ww]=max(dp[i+1][ww], dp[i][j]+new_talent[i+1]);
                    dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
                }
            }
        }
        if (dp[N][W]>=0) lo=mid;
        else hi=mid-1;
    }
    cout << lo << "\n";
}

int main()
{
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
