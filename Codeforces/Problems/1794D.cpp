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
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5050, sqrmax=635, MOD=998244353;

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

ll fact[nmax]={}, fact_inv[nmax]={}, dp[nmax][nmax]={};
vector<pair<ll, ll>> p;
ll DP(ll x, ll y){
	if(dp[x][y]!=-1) return dp[x][y];
	if (x==p.size()) return dp[x][y]=(y==0);
	dp[x][y]=fact_inv[p[x].second] * DP(x + 1, y) % MOD;
	if(y>0) dp[x][y] = (dp[x][y] + fact_inv[p[x].second - 1] * DP(x + 1, y - 1)) % MOD;	
	return dp[x][y];
}

void solve() {
    linear_sieve(1e6);
    int n; cin >> n;
    vector<int> a(2*n);
    for (int i=0; i<2*n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<ll, ll>> a_comp;
    for (int i=0; i<2*n; i++){
		if(a_comp.empty()|| a_comp.back().fs!=a[i]) a_comp.push_back({a[i], 1});
		else a_comp.back().sc++;
	}
	fact[0]=1, fact_inv[0]=1;
	for(ll i=1; i<nmax; i++) {
        fact[i]=fact[i-1]*i%MOD;
	    fact_inv[i]=fastpow(fact[i], MOD-2);
    }

    for(auto x: a_comp){
		if (isprime[x.fs]) {
			p.push_back(x);
		}
	}
    fill(&dp[0][0], &dp[nmax-1][nmax], -1);
    ll ans=DP(0, n);
	for (auto x: a_comp){
		if(!isprime[x.fs]) ans=ans*fact_inv[x.sc]%MOD;
	}
	ans=ans*fact[n]%MOD;
	cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
