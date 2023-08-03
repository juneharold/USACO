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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int ans;

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
        isprime.push_back(1);
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
    int cnt;
    bool end;
    Trie() {
        cnt=0;
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
        if (!ch[now]) {
            ch[now]=new Trie;
            cnt++;
        }
        ch[now]->insert(s+1);
    }
    void find(const char* s, int k, bool root) {
        if (!*s) { 
            ans+=k;
            return;
        }
        int now=*s-'a';
        if (root) ch[now]->find(s+1, k+1, false);
        else {
            if (cnt==1 && !end) ch[now]->find(s+1, k, false);
            else ch[now]->find(s+1, k+1, false);
        }
    }
};

void solve(int n) {
    Trie* root=new Trie;
    ans=0;
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        root->insert(&v[i][0]);
    }
    for (int i=0; i<n; i++) {
        root->find(&v[i][0], 0, true);
    }
    cout << fixed << setprecision(2) << (double)ans/n << "\n";
    delete root;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while (cin >> n) {
        solve(n);
    }
}
