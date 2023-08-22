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

void solve() {
    /*
    dp[i][j]: maximum value of segments that end before (or at) i and has total length j.
    dp[i][j]=max(dp[i-1][j], dp[i-l][j-l]+f(i-l+1, i));
    Which is...
    dp[i][j]=max(
        dp[i-1][j],
        a[i]-b[i]+(a[i-l]-b[i-l]+dp[i-l][j-l]),
        a[i]+b[i]+(-a[i-l]-b[i-l]+dp[i-l][j-l]),
        -a[i]-b[i]+(a[i-l]+b[i-l]+dp[i-l][j-l]),
        -a[i]+b[i]+(-a[i-l]+b[i-l]+dp[i-l][j-l]),
    )
    where 1<=l<=j
    now, only one l-value for a pair(i, j) is largest. so keep that in four different vectors. 
    */
    int n, k; cin >> n >> k;
    vector<int> a(n+1), b(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    vector<ll> mx1(n+2, -INF), mx2(n+2, -INF), mx3(n+2, -INF), mx4(n+2, -INF);
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, -INF));
    dp[0][0]=0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=min(i, k); j++) {
            int diag=i-j;
            if (i!=0) {
                dp[i][j]=dp[i-1][j];
                dp[i][j]=max(dp[i][j], a[i]-b[i]+mx1[diag]);
                dp[i][j]=max(dp[i][j], a[i]+b[i]+mx2[diag]);
                dp[i][j]=max(dp[i][j], -a[i]-b[i]+mx3[diag]);
                dp[i][j]=max(dp[i][j], -a[i]+b[i]+mx4[diag]);
            }
            if (i!=n) {
                mx1[diag]=max(mx1[diag], a[i+1]-b[i+1]+dp[i][j]);
                mx2[diag]=max(mx2[diag], -a[i+1]-b[i+1]+dp[i][j]);
                mx3[diag]=max(mx3[diag], +a[i+1]+b[i+1]+dp[i][j]);
                mx4[diag]=max(mx4[diag], -a[i+1]+b[i+1]+dp[i][j]);
            }
        }
    }
    cout << dp[n][k] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
