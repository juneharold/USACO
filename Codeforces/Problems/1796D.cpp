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

ll dp[nmax][21][3]={};

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    fill(&dp[0][0][0], &dp[n][k+1][2], -INF);
    dp[0][0][0]=0;
    ll ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=k; j++) {
            for (int t=0; t<3; t++) {
                if (dp[i][j][t]==-INF) continue;
                if (t==0) {
                    if (j<k) dp[i+1][j+1][t]=max(dp[i+1][j+1][t], dp[i][j][t]);
                    dp[i+1][j][t]=max(dp[i+1][j][t], dp[i][j][t]);
                    if (j<k) dp[i+1][j+1][t+1]=max(dp[i+1][j+1][t+1], a[i+1]+x);
                    dp[i+1][j][t+1]=max(dp[i+1][j][t+1], a[i+1]-x);
                }
                if (t==1) {
                    if (j<k) dp[i+1][j+1][t]=max(dp[i+1][j+1][t], dp[i][j][t]+a[i+1]+x);
                    dp[i+1][j][t]=max(dp[i+1][j][t], dp[i][j][t]+a[i+1]-x);
                    if (j<k) dp[i+1][j+1][t+1]=max(dp[i+1][j+1][t+1], dp[i][j][t]);
                    dp[i+1][j][t+1]=max(dp[i+1][j][t+1], dp[i][j][t]);
                }
                if (t==2) {
                    if (j<k) dp[i+1][j+1][t]=max(dp[i+1][j+1][t], dp[i][j][t]);
                    dp[i+1][j][t]=max(dp[i+1][j][t], dp[i][j][t]);
                }
            }
        }
    }
    cout << max(0LL, max(dp[n][k][1], dp[n][k][2])) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}