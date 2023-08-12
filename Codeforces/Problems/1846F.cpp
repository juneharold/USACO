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
    int n; cin >> n;
    vector<int> cnt1(10, 0), cnt2(10, 0), a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt1[a[i]]++;
    }
    cout << "- 0\n" << flush;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt2[a[i]]++;
    }
    int num=-1;
    for (int i=1; i<=9; i++) if (cnt1[i]<cnt2[i]) num=i;
    if (num==-1) {
        fill(&cnt1[1], &cnt1[10], 0);
        cout << "- 0\n" << flush;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            cnt1[a[i]]++;
        }
        for (int i=1; i<=9; i++) if (cnt1[i]>cnt2[i]) num=i;
    }
    int cnt=0;
    for (int i=1; i<=n; i++) if (a[i]!=num) cnt++;
    if (n-cnt==1) {
        for (int i=1; i<=n; i++) if (a[i]==num) cout << "! " << i << "\n" << flush;
        return;
    }
    cout << "- " << cnt << flush;
    for (int i=1; i<=n; i++) if (a[i]!=num) cout << ' ' << i << flush;
    cout << "\n" << flush;
    cout.flush();

    n-=cnt;
    fill(&cnt1[1], &cnt1[10], 0);
    fill(&cnt2[1], &cnt2[10], 0);
    int ans=0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i]!=num) ans=i;
        cnt1[a[i]]++;
    }
    if (ans!=0) {
        cout << "! " << ans << "\n" << flush;
        return;
    }
    cout << "- 0\n" << flush;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt2[a[i]]++;
    }
    num=-1;
    for (int i=1; i<=9; i++) if (cnt1[i]<cnt2[i]) num=i;
    if (num==-1) {
        fill(&cnt1[1], &cnt1[10], 0);
        cout << "- 0\n" << flush;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            cnt1[a[i]]++;
        }
        for (int i=1; i<=9; i++) if (cnt1[i]>cnt2[i]) num=i;
    }
    for (int i=1; i<=n; i++) {
        if (a[i]==num) cout << "! " << i << "\n" << flush;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
