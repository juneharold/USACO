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
const ll nmax=5005, sqrmax=635, MOD=1e9+7;

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

ll ans=0, dp[nmax]={};
vector<ll> graph[nmax];
void dfs(ll cur, ll p) {
    dp[cur]=1;
    ll sum=0;
    vector<ll> w;
    w.push_back(0);
    for (ll nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
        dp[cur]+=dp[nx];
        sum+=dp[nx];
        w.push_back(dp[nx]);
    }

    vector<ll> DP[2];
    for (ll i=0; i<2; i++) {
        for (ll j=0; j<=sum+5; j++) DP[i].push_back(0);
    }
    DP[0][0]=1;
    for (ll i=1; i<w.size(); i++) {
        for (ll j=1; j<=sum; j++) DP[i%2][j]=0;
        for (ll j=1; j<=sum; j++) {
            DP[i%2][j]=DP[(i+1)%2][j];
            if (j-w[i]>=0) DP[i%2][j]=max(DP[i%2][j], DP[(i+1)%2][j-w[i]]);
        }
    }
    ll temp=0;
    for (ll j=1; j<=sum; j++) {
        ll i=(w.size()-1)%2;
        if (DP[i][j]==1) {
            temp=max(temp, j*(sum-j));
        }
    }
    ans+=temp;
}

void solve() {
    ll n; cin >> n;
    for (ll i=2; i<=n; i++) {
        ll p; cin >> p;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }
    dfs(1, 0);
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
