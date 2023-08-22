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

void solve() {
    ll n; cin >> n;
    vector<pii> v;
    for (ll i=0; i<n; i++) {
        ll l, r, a, b; cin >> l >> r >> a >> b;
        v.push_back({l, b});
    }
    sort(v.begin(), v.end());
    vector<pii> overlap;
    ll x=v[0].fs, y=v[0].sc;
    for (ll i=1; i<n; i++) {
        if (y>=v[i].fs) y=max(y, v[i].sc);
        else {
            overlap.push_back({x, y});
            x=v[i].fs, y=v[i].sc;
        }
    }
    overlap.push_back({x, y});

    vector<ll> ans;
    ll q; cin >> q;
    for (ll i=0; i<q; i++) {
        ll pos; cin >> pos;
        ll lo=0, hi=overlap.size()-1;
        while (lo<hi) {
            ll mid=(lo+hi)/2;
            if (overlap[mid].sc<pos) lo=mid+1;
            else hi=mid;
        }
        if (overlap[lo].fs<=pos && pos<=overlap[lo].sc) ans.push_back(overlap[lo].sc);
        else ans.push_back(pos);
    }
    for (ll aa: ans) cout << aa << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
