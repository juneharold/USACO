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
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7;

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

vector<int> graph[nmax];
int num[nmax]={}, p[nmax][20]={}, mp[nmax]={}, ans[nmax]={}, cnt=0;

void dfs(int cur) {
    if (cur!=0 && mp[num[cur]]==0) cnt++;
    mp[num[cur]]++;
    ans[cur]=cnt;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx!=0) dfs(nx);
    }
    mp[num[cur]]--;
    if (cur!=0 && mp[num[cur]]==0) cnt--;
}

void solve() {
    /*
    use a tree-like structure to keep track of array
    "+ x": add new node (with node number different from x) from current node
    "- k": move up k parents using binary lifting
    "!": just go back to node in previous query. 
    "?": store current node in some vector.
    */
    int q; cin >> q;
    vector<int> hist, query;
    hist.push_back(0);
    int cur=0, idx=0, prev=-1;
    while (q--) {
        char type; cin >> type;
        if (type=='+') {
            int x; cin >> x;
            idx++;
            graph[cur].push_back(idx);
            num[idx]=x;
            p[idx][0]=cur;
            for (int j=1; j<20; j++) p[idx][j]=p[p[idx][j-1]][j-1];
            hist.push_back(idx);
            cur=idx;
        }
        if (type=='-') {
            int k; cin >> k;
            for (int j=0; j<20; j++) {
                if ((1<<j)&k) cur=p[cur][j];
            }
            hist.push_back(cur);
        }
        if (type=='!') {
            hist.pop_back();
            cur=hist.back();
        }
        if (type=='?') query.push_back(cur);
    }
    dfs(0);
    for (int x: query) cout << ans[x] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //in >> T;
    while (T--) {
        solve();
    }
}
