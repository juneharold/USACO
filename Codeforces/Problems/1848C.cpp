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
    vector<int> a(n+1), b(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    int check[3]={};
    for (int i=1; i<=n; i++) {
        int x=a[i], y=b[i];
        int cnt=0;
        while (x!=0 && y!=0) {
            if (x>=y) {
                int num=x/y;
                if (num%2) {
                    cnt+=(num-1)/2*3+1;
                    int temp=x%y;
                    x=y;
                    y=temp;
                }
                else {
                    cnt+=(num-1)/2*3+3;
                    x%=y;
                }
            }
            else {
                int temp=abs(x-y);
                x=y;
                y=temp;
                cnt++;
            }
        }
        if (x==0 && y==0) continue;
        if (x!=0) cnt++;
        check[cnt%3]=1;
    }
    if (check[0]+check[1]+check[2]>1) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
