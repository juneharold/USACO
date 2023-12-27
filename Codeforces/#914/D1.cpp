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
void solve() {
    int n; cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    vector<pii> range(n+1, {0, 0});
    for (int i=1; i<=n; i++) {
        int l=i, r=i;
        for (int j=i-1; j>=1; j--) {
            if (a[j]<a[i]) l=j;
            else break;
        }
        for (int j=i+1; j<=n; j++) {
            if (a[j]<a[i]) r=j;
            else break;
        }
        range[i]={l, r};
    }
    range[0]={1e9, 0};
    for (int i=1; i<=n; i++) {
        if (a[i]<b[i]) {
            pii candidate={0, 0};
            for (int j=i-1; j>=1; j--) {
                if (a[j]==b[i]) {
                    candidate.fs=j;
                    break;
                }
            }
            for (int j=i+1; j<=n; j++) {
                if (a[j]==b[i]) {
                    candidate.sc=j;
                    break;
                }
            }
            //cout << i << ' ' << candidate.fs << ' ' << candidate.sc << endl;
            bool possible=false;
            if (candidate==make_pair(0, 0)) {
                cout << "NO\n";
                return;
            }
            if (i<=range[candidate.fs].sc) {
                for (int j=candidate.fs; j<=i; j++) {
                    if (a[candidate.fs]>b[j]) break;
                    if (j==i-1) possible=true;
                }
            }
            if (range[candidate.sc].fs<=i) {
                for (int j=candidate.sc; j>=i; j--) {
                    if (a[candidate.sc]>b[j]) break;
                    if (j==i+1) possible=true;
                }
            }
            if (!possible) {
                cout << "NO\n";
                return;
            }
        }
        else if (a[i]>b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
/*
7
1 2 3 3 3 2 1
3 3 3 3 3 3 3

10
1 2 3 3 3 2 1 4 6 6
3 3 3 3 3 3 3 6 6 6

1 3 3 4 2
1 4 3 4 2
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
