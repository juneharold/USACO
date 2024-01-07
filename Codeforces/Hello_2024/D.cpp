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
int a[nmax]={}, checked[nmax]={};
set<int> s;
priority_queue<pii> pq;

void check(int idx) {
    if (checked[idx]) return;
    auto it1=s.find(idx);
    if (it1!=s.begin() && it1!=s.end()) {
        it1--;
        if (a[*it1]+1==a[idx]) {
            pq.push({a[idx], idx});
            checked[idx]=1;
            return;
        }
    }
    auto it2=s.find(idx);
    if (it2!=--s.end() && it2!=s.end()) {
        it2++;
        if (a[*it2]+1==a[idx])  {
            pq.push({a[idx], idx});
            checked[idx]=1;
            return;
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) s.insert(i);
    for (int i=0; i<n; i++) check(i);

    while (!pq.empty()) {
        int val=pq.top().fs, idx=pq.top().sc;
        pq.pop();

        auto it1=s.find(idx);
        if (it1!=s.begin() && it1!=s.end()) it1--;
        auto it2=s.find(idx);
        if (it2!=--s.end() && it2!=s.end()) it2++;

        if (a[*it1]+1==val) {
            int temp1=*it1, temp2=*it2;
            s.erase(idx);
            check(temp1); check(temp2);
            continue;
        }
        if (a[*it2]+1==val)  {
            int temp1=*it1, temp2=*it2;
            s.erase(idx);
            check(temp1); check(temp2);
            continue;
        }
    }
    
    if (s.size()==1 && a[*s.begin()]==0) cout << "YES\n";
    else cout << "NO\n";

    s.clear();
    for (int i=0; i<n; i++) {
        a[i]=0;
        checked[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
