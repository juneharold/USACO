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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

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
    int n, m, d; cin >> n >> m >> d;
    vector<int> s(m+1);
    for (int i=1; i<=m; i++) cin >> s[i];
    int res=(s[1]==1 ? 0 : (s[1]-1-1)/d+1); // how many cookies without removing any sellers 
    for (int i=1; i<m; i++) res+=(s[i+1]-1-s[i])/d+1;
    res+=(n-s[m])/d+1;

    int mn=res-((s[2]-1-s[1])/d+1)-(s[1]==1 ? 0 : (s[1]-1-1)/d+1)+((s[2]-1-1)/d+1);
    mn=min(mn, res-((n-s[m])/d+1)-((s[m]-1-s[m-1])/d+1)+((n-s[m-1])/d+1));
    for (int i=2; i<m; i++) {
        mn=min(mn, res-((s[i+1]-1-s[i])/d+1)-((s[i]-1-s[i-1])/d+1)+((s[i+1]-1-s[i-1])/d+1));
    }
    int cnt=0;
    if (res-((s[2]-1-s[1])/d+1)-(s[1]==1 ? 0 : (s[1]-1-1)/d+1)+((s[2]-1-1)/d+1)==mn) cnt++;
    if (res-((n-s[m])/d+1)-((s[m]-1-s[m-1])/d+1)+((n-s[m-1])/d+1)==mn) cnt++;
    for (int i=2; i<m; i++) {
        if (res-((s[i+1]-1-s[i])/d+1)-((s[i]-1-s[i-1])/d+1)+((s[i+1]-1-s[i-1])/d+1)==mn) cnt++;
    }
    cout << mn << ' ' << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
